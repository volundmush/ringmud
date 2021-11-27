//
// Created by volund on 11/25/21.
//

#ifndef RINGMUD_CORE_H
#define RINGMUD_CORE_H

#include "sysdep.h"
#include <mutex>
#include "asio.hpp"

namespace ring::core {
    extern entt::registry registry;
    extern std::set<int> new_connections, closed_connections, ready_connections;
    extern std::mutex new_conn_mutex, closed_conn_mutex, ready_conn_mutex;
    extern bool copyover_execute, sleeping, had_connections, copyover_after;
    extern asio::high_resolution_timer *loop_timer;
    extern fs::path profile_path;
    extern std::chrono::milliseconds interval;
    extern uint64_t pulse;

    extern std::function<void()> on_copyover_execute, on_copyover_fail, on_load_db;
    extern std::function<void(nlohmann::json&)> on_copyover_save, on_copyover_recover;
    extern std::function<void(uint64_t)> on_heartbeat;

    void connection_ready(int conn_id);
    void connection_closed(int conn_id);
    void connection_hasdata(int conn_id);

    void load_db();
    void clock_loop();
    void network_loop();
    void game_loop(const std::string &host, uint16_t telnet_port);

    void copyover_recover();

}

#endif //RINGMUD_CORE_H
