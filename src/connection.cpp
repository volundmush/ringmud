//
// Created by volund on 11/25/21.
//

#include "connection.h"


namespace ring::conn {
    std::map<uint64_t, entt::entity> connections;
    std::set<uint64_t> closing;


    ConnectionData::~ConnectionData() {
        if(conn.expired()) return;
        auto c = conn.lock();
        ring::net::manager.closeConn(c->conn_id);
    }

    void ConnectionData::process_input() {
        if(conn.expired()) return;
        auto c = conn.lock();

        c->in_queue_mutex.lock();
        input.splice(input.end(), c->queue_in);
        c->in_queue_mutex.unlock();

        if(input.empty())
            return;

        auto comm = input.front();

        if(handle_input) handle_input(conn_id, entity, comm);

        input.pop_front();
    }

    void ConnectionData::send_text(const std::string &txt, ring::net::TextType mode) {
        if(conn.expired()) return;
        auto c = conn.lock();
        c->sendText(txt, mode);
    }

    bool ConnectionData::isColor() {
        if(conn.expired()) return false;
        auto c = conn.lock();
        return c->details.colorType > 0;
    }

    entt::entity make_connection(uint64_t conn_id) {
        auto ent = core::registry.create();
        auto wp = ring::net::manager.connections[conn_id];
        core::registry.emplace<ConnectionData>(ent, wp);
        conn::connections[conn_id] = ent;
        if(on_make_connection) on_make_connection(conn_id, ent);
        return ent;
    }

    entt::entity create_connection(uint64_t conn_id) {
        auto ent = make_connection(conn_id);
        if(on_create_connection) on_create_connection(conn_id, ent);
        return ent;
    }

    void close_connection(uint64_t conn_id) {
        auto ent = connections[conn_id];
        if(on_close_connection) on_close_connection(conn_id, ent);
        connections.erase(conn_id);
        core::registry.destroy(ent);
        closing.erase(conn_id);
    }

    nlohmann::json save_connection(uint64_t conn_id) {
        auto ent = connections[conn_id];
        nlohmann::json j;
        j["conn_id"] = conn_id;
        if(on_save_connection) on_save_connection(conn_id, ent, j);
        return j;
    }

    nlohmann::json save_connections() {
        nlohmann::json j;
        for(auto &s : connections) {
            j[std::to_string(s.first)] = save_connection(s.first);
        }
        return j;
    }

    void load_connection(uint64_t conn_id, nlohmann::json& j) {
        auto ent = make_connection(conn_id);
        if(on_load_connection) on_load_connection(conn_id, ent, j);
    }

    void load_connections(nlohmann::json& j) {
        for(nlohmann::json::iterator it = j.begin(); it != j.end();it++) {
            uint64_t conn_id = std::strtoull(it.key().c_str(), nullptr, 10);
            load_connection(conn_id, it.value());
        }
    }

}