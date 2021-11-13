//
// Created by volund on 11/12/21.
//

#include "net.h"
#include "telnet.h"

namespace ring::net {


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
        in_buffer = new asio::streambuf;
        out_buffer = new asio::streambuf;
    }

    connection_details::connection_details(entt::entity ent) {
        entity = ent;
        in_mutex = new std::mutex;
        out_mutex = new std::mutex;
    }

    connection_details::~connection_details() {
        delete in_mutex;
        delete out_mutex;
    }

    plain_socket::plain_socket(entt::entity ent, asio::ip::tcp::socket *sock) {
        entity = ent;
        socket = sock;
    }

    plain_socket::~plain_socket() {
        if(socket) {
            socket->cancel();
            delete socket;
        }
    }

    void plain_socket::send() {
        if(!isWriting) {
            auto &buffers = netreg.get<socket_buffers>(entity);
            if(buffers.out_buffer->size()) {
                isWriting = true;
                auto handler = [&](std::error_code ec, std::size_t trans) {
                    buffers.out_buffer->consume(trans);
                    isWriting = false;
                    if(buffers.out_buffer->size())
                        send();
                };
                socket->async_write_some(asio::buffer(buffers.out_buffer->data(), buffers.out_buffer->size()), handler);
            }
        }
    }

    void plain_socket::receive() {
        if(!isReading) {
            isReading = true;
            auto &buffers = netreg.get<socket_buffers>(entity);
            auto prep = buffers.in_buffer->prepare(1024);
            auto handler = [&](std::error_code ec, std::size_t trans) {
                if(!ec) {
                    onDataReceived();
                    // re-arm the socket and call receive again.
                    isReading = false;
                    buffers.in_buffer->commit(trans);
                    receive();
                } else {
                    // something bad happened. what do we do???
                }
            };
            socket->async_read_some(asio::buffer(prep), handler);
        }
    }

    void plain_socket::onDataReceived() {
        auto &buffers = netreg.get<socket_buffers>(entity);
        auto &details = netreg.get<client_details>(entity);

        if(details.clientType == TcpTelnet || details.clientType == TlsTelnet) {
            auto msg = ring::telnet::parse_message(*buffers.in_buffer);
            if(msg.has_value()) {
                auto &telnet = netreg.get<ring::telnet::TelnetProtocol>(entity);
                telnet.handleMessage(msg.value());
            }
        }
    }

    plain_telnet_listen::plain_telnet_listen(entt::entity ent, asio::ip::tcp::endpoint endp) :acceptor(executor, endp) {
        entity = ent;
    }

    void plain_telnet_listen::listen() {
        if(!isListening) {
            isListening = true;
            auto sock = new asio::ip::tcp::socket(executor);
            auto handler = [&](std::error_code ec) {
                if(!ec) {
                    auto new_ent = netreg.create();
                    netreg.emplace<plain_socket>(new_ent, new_ent, sock);
                    netreg.emplace<socket_buffers>(new_ent, new_ent);
                    netreg.emplace<connection_details>(new_ent, new_ent);
                    netreg.emplace<client_details>(new_ent, new_ent, TcpTelnet);
                    auto &telnet = netreg.emplace<telnet::TelnetProtocol>(new_ent, new_ent);
                    telnet.onConnect();
                } else {
                    // Oops, something bad happened. handle it!
                }
                isListening = false;
                listen();
            };
            acceptor.async_accept(*sock, handler);

        }
    }

}