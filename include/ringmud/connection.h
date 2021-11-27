//
// Created by volund on 11/25/21.
//

#ifndef RINGMUD_CONNECTION_H
#define RINGMUD_CONNECTION_H

#include "core.h"
#include "ringnet/net.h"

namespace ring::conn {

    extern std::map<uint64_t, entt::entity> connections;
    extern std::set<uint64_t> closing;

    extern std::function<void(uint64_t, entt::entity)> on_make_connection, on_create_connection, on_close_connection;
    extern std::function<void(uint64_t, entt::entity, nlohmann::json&)> on_load_connection, on_save_connection;
    extern std::function<void(uint64_t, entt::entity, nlohmann::json&)> handle_input;

    struct ConnectionData {
        explicit ConnectionData(std::weak_ptr<ring::net::connection_details> cd);
        ~ConnectionData();
        std::weak_ptr<ring::net::connection_details> conn;
        std::list<nlohmann::json> input;
        entt::entity entity;
        uint64_t conn_id;

        void process_input();
        void send_text(const std::string& txt, ring::net::TextType mode);
        bool isColor();
    };

    entt::entity make_connection(uint64_t conn_id);

    entt::entity create_connection(uint64_t conn_id);

    void close_connection(uint64_t conn_id);

    nlohmann::json save_connection(uint64_t conn_id);

    nlohmann::json save_connections();

    void load_connection(uint64_t conn_id, nlohmann::json &j);

    void load_connections(nlohmann::json& j);

}

#endif //RINGMUD_CONNECTION_H
