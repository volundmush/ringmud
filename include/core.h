//
// Created by volund on 11/13/21.
//

#ifndef RINGMUD_CORE_H
#define RINGMUD_CORE_H

#include "asio.hpp"
#include "entt/entt.hpp"

namespace ring {
    extern asio::io_context executor;
    extern entt::registry netreg;
    extern void(*on_ready_cb)(entt::entity ent);

    bool readyTLS();
    bool listenPlainTelnet(const std::string& ip, uint16_t port);
    bool listenTLSTelnet(const std::string& ip, uint16_t port);
    bool listenWebSocket(const std::string& ip, uint16_t port);

    void run();
}

#endif //RINGMUD_CORE_H
