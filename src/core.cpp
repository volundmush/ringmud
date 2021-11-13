//
// Created by volund on 11/13/21.
//

#include <iostream>
#include "core.h"
#include "net.h"

namespace ring {
    asio::io_context executor;
    entt::registry netreg;
    void(*on_ready_cb)(entt::entity ent) = nullptr;

    bool readyTLS() {
        return false;
    }

    bool listenPlainTelnet(const std::string& ip, uint16_t port) {
        std::error_code ec;
        auto ip_address = asio::ip::address::from_string(ip, ec);

        if(ec) {
            std::cerr << "Failed to parse IP Address: " << ip << " Error code: " << ec.value() << " - " << ec.message() << std::endl;
            exit(1);
        }
        asio::ip::tcp::endpoint endp(ip_address, port);

        auto new_ent = netreg.create();
        auto &listener = netreg.emplace<net::plain_telnet_listen>(new_ent, new_ent, endp);
        listener.listen();

    }

    bool listenTLSTelnet(const std::string& ip, uint16_t port) {
        return false;
    }

    bool listenWebSocket(const std::string& ip, uint16_t port) {
        return false;
    }

    void run() {
        if(!on_ready_cb) {
            std::cerr << "Error! on_ready_cb not set." << std::endl;
            exit(1);
        }
        // quick and dirty
        executor.run();
    }
}