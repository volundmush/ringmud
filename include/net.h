//
// Created by volund on 11/12/21.
//

#ifndef RINGMUD_NET_H
#define RINGMUD_NET_H

#include <mutex>
#include <memory>
#include "entt/entt.hpp"
#include "asio.hpp"
#include "core.h"


namespace ring::net {

    enum ClientType : uint8_t {
        TcpTelnet = 0,
        TlsTelnet = 1,
        WebSocket = 2
    };

    enum ColorType : uint8_t {
        NoColor = 0,
        StandardColor = 1,
        XtermColor = 2,
        TrueColor = 3
    };

    struct client_details {
        entt::entity entity;
        ClientType clientType = TcpTelnet;
        ColorType colorType = NoColor;
        std::string clientName = "UNKNOWN", clientVersion = "UNKNOWN";
        std::string hostIp = "UNKNOWN", hostName = "UNKNOWN";
        int width = 78, height = 24;
        bool utf8 = false, screen_reader = false, proxy = false, osc_color_palette = false;
        bool vt100 = false, mouse_tracking = false, naws = false, msdp = false, gmcp = false;
        bool mccp2 = false, mccp2_active = false, mccp3 = false, mccp3_active = false;
        bool mtts = false, ttype = false, mnes = false, suppress_ga = false;
        bool force_endline = false, linemode = false, mssp = false, mxp = false, mxp_active = false;

        client_details(entt::entity ent, ClientType ctype);
        bool isSecure() const;
        bool supportsOOB() const;
    };

    struct connection_details {
        explicit connection_details(entt::entity ent);
        ~connection_details();
        entt::entity entity;
        std::mutex *in_mutex, *out_mutex;
    };

    struct socket_buffers {
        explicit socket_buffers(entt::entity ent);
        entt::entity entity;
        asio::streambuf *in_buffer, *out_buffer;
    };

    struct plain_socket {
        explicit plain_socket(entt::entity ent, asio::ip::tcp::socket *sock);
        ~plain_socket();
        entt::entity entity;
        asio::ip::tcp::socket *socket;
        bool isWriting = false;
        bool isReading = false;

        void send();
        void receive();
        void onDataReceived();
    };

    struct plain_telnet_listen {
        plain_telnet_listen(entt::entity ent, asio::ip::tcp::endpoint endp);
        entt::entity entity;
        asio::ip::tcp::acceptor acceptor;

        bool isListening = false;

        void listen();
    };


}

#endif //RINGMUD_NET_H
