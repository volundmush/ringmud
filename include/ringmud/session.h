//
// Created by volund on 11/25/21.
//

#ifndef RINGMUD_SESSION_H
#define RINGMUD_SESSION_H

#include "core.h"

namespace ring::session {
    // the key of sessions is the character id being played.
    extern std::map<uint64_t, entt::entity> sessions;
    extern std::set<uint64_t> closing;

    // Since prompts are very game-specific, this is handled via a function pointer.
    extern std::function<std::string(int64_t, entt::entity)> render_prompt, on_make_session, on_create_session;
    extern std::function<std::string(int64_t, entt::entity)> on_session_start, on_session_end, handle_output;
    extern std::function<void(int64_t, entt::entity, nlohmann::json&)> on_save_session, on_load_session;
    extern std::function<void(int64_t, entt::entity, const std::string &txt)> handle_command;

    class Parser {
    public:
        Parser(entt::entity sess);
        virtual void parse(const std::string &txt) = 0;
        virtual void start();
        virtual void close();
        virtual bool isPlaying() = 0;
    protected:
        entt::entity sess;
    };

    struct SessionData {
        uint64_t char_id;
        entt::entity entity;
        std::set<entt::entity> connections;
        std::list<std::string> output, input;
        std::time_t start_time;
        entt::entity character, puppet;

        void send_text(const std::string &txt);
        void writeToOutput(const char *txt, ...);
        void vwriteToOutput(const char *format, va_list args);
        void process_input();
        void process_output();
    };


    entt::entity make_session(uint64_t char_id);

    entt::entity create_session(uint64_t char_id);

    void end_session(uint64_t char_id);

    nlohmann::json save_session(uint64_t char_id);

    nlohmann::json save_sessions();

    void load_session(uint64_t char_id, nlohmann::json &j);

    void load_sessions(nlohmann::json& j);

}

#endif //RINGMUD_SESSION_H
