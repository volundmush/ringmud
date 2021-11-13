//
// Created by volund on 11/12/21.
//

#include "net.h"
#include "telnet.h"

namespace ring::net {
    entt::registry connections;

    client_details::client_details(entt::entity ent, ClientType ctype) {
        entity = ent;
        clientType = ctype;
    }

    bool client_details::isSecure() const {
        switch(clientType) {
            case TlsTelnet:
            case WebSocket:
                return true;
            default:
                return false;
        }
    }

    bool client_details::supportsOOB() const {
        if(clientType == WebSocket) return true;
        return gmcp || msdp;

    }

    socket_buffers::socket_buffers(entt::entity ent) {
        entity = ent;
    }

    connection_details::connection_details(entt::entity ent) {
        entity = ent;
    }

    void connection_details::start() {

    }

    plain_socket::plain_socket(entt::entity ent, asio::ip::tcp::socket sock) : socket(std::move(sock)) {
        entity = ent;
    }

    void plain_socket::send() {
        if(!isWriting) {
            auto &buffers = connections.get<socket_buffers>(entity);
            if(buffers.out_buffer.size()) {
                isWriting = true;
                auto handler = [&](std::error_code ec, std::size_t trans) {
                    buffers.out_buffer.consume(trans);
                    isWriting = false;
                    if(buffers.out_buffer.size())
                        send();
                };
                socket.async_write_some(buffers.out_buffer, handler);
            }
        }
    }

    void plain_socket::receive() {
        if(!isReading) {
            isReading = true;
            auto &buffers = connections.get<socket_buffers>(entity);
            auto handler = [&](std::error_code ec, std::size_t trans) {
                if(!ec) {
                    onDataReceived();
                    // re-arm the socket and call receive again.
                    isReading = false;
                    receive();
                } else {
                    // something bad happened. what do we do???
                }
            };
            socket.async_read_some(buffers.in_buffer, handler);
        }
    }

    void plain_socket::onDataReceived() {
        auto &buffers = connections.get<socket_buffers>(entity);
        auto &details = connections.get<client_details>(entity);

        if(details.clientType == TcpTelnet || details.clientType == TlsTelnet) {
            auto msg = ring::telnet::parse_message(buffers.in_buffer);
            if(msg.has_value()) {
                auto &telnet = connections.get<ring::telnet::TelnetProtocol>(entity);
                telnet.handleMessage(msg.value());
            }
        }
    }

}