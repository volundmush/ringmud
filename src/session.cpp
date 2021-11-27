//
// Created by volund on 11/25/21.
//

#include "session.h"
#include "connection.h"
#include "ansi.h"

namespace ring::session {
    std::map<uint64_t, entt::entity> sessions;
    std::set<uint64_t> closing;

    std::function<void(uint64_t, entt::entity)> on_make_session, on_create_session;
    std::function<void(uint64_t, entt::entity)> on_session_start, on_session_end, handle_output;
    std::function<void(uint64_t, entt::entity, nlohmann::json&)> on_save_session, on_load_session;
    std::function<void(uint64_t, entt::entity, const std::string&)> handle_command;

    void SessionData::writeToOutput(const char *txt, ...) {
        va_list args;
        va_start(args, txt);
        vwriteToOutput(txt, args);
        va_end(args);
    }

    void SessionData::vwriteToOutput(const char *format, va_list args) {
        std::string s;
        va_list apc;
        va_copy(apc, args);
        s.resize(vsnprintf(nullptr, 0, format, args)+1);
        vsnprintf(s.data(), s.capacity(), format, apc);
        output.emplace_back(s);
        va_end(apc);
    }

    void SessionData::send_text(const std::string &txt) {
        output.emplace_back(txt);
    }

    void SessionData::process_input() {
        if(input.empty())
            return;

        auto comm = input.front();

        if(handle_command) handle_command(char_id, entity, comm);

        input.pop_front();

    }


    void SessionData::process_output() {
        // This function takes everything in the output list, renders it, and sends it off to all connections.

        if(!output.empty() && handle_output)
            handle_output(char_id, entity);
        output.clear();
    }

    entt::entity make_session(uint64_t char_id) {
        auto ent = core::registry.create();
        auto &sdata = core::registry.emplace<SessionData>(ent);
        sdata.char_id = char_id;
        sdata.entity = ent;
        sessions[char_id] = ent;
        if(on_make_session) on_make_session(char_id, ent);
        return ent;
    }

    entt::entity create_session(uint64_t char_id) {
        auto ent = make_session(char_id);
        if(on_create_session) on_create_session(char_id, ent);
        return ent;
    }

    void end_session(uint64_t char_id) {
        auto ent = sessions[char_id];
        if(on_session_end) on_session_end(char_id, ent);
        sessions.erase(char_id);
        core::registry.destroy(ent);
        closing.erase(char_id);
    }

    nlohmann::json save_session(uint64_t char_id) {
        auto ent = sessions[char_id];
        nlohmann::json j;
        j["char_id"] = char_id;
        if(on_save_session) on_save_session(char_id, ent, j);
        return j;
    }

    nlohmann::json save_sessions() {
        nlohmann::json j;
        for(auto &s : sessions) {
            j[std::to_string(s.first)] = save_session(s.first);
        }
        return j;
    }

    void load_session(uint64_t char_id, nlohmann::json& j) {
        auto ent = make_session(char_id);
        if(on_load_session) on_load_session(char_id, ent, j);
    }

    void load_sessions(nlohmann::json& j) {
        for(nlohmann::json::iterator it = j.begin(); it != j.end();it++) {
            uint64_t char_id = std::strtoull(it.key().c_str(), nullptr, 10);
            load_session(char_id, it.value());
        }
    }

}