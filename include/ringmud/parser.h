//
// Created by volund on 6/10/22.
//

#ifndef CIRCLE_PARSER_H
#define CIRCLE_PARSER_H

#include "sysdep.h"

namespace parser {

    class BaseParser {
    public:
        BaseParser(entity_t ent);
        virtual void onStart();
        virtual void onClose();
        virtual void onHeartbeat();
        virtual void parse(input_data &in);
        virtual void loadJson(const nlohmann::json &j);
        virtual nlohmann::json serialize();
    protected:
        entity_t owner;
    };

    // Connection parsers below this.
    class ConnectionParser : public BaseParser { // still abstract.
    public:
        using BaseParser::BaseParser;
        void send(const std::string &str);

    };

    enum LoginState : uint8_t {
        l_getname = 0,
        l_confname = 1,
        l_pass = 2,
        l_confpass = 3,
        l_email = 4,
        l_emailconf = 5
    };

    // parser_id 0
    class LoginParser : public ConnectionParser {
    public:
        using ConnectionParser::ConnectionParser;
        virtual void onStart() override;
        virtual void parse(input_data &in) override;
    protected:
        entity_t user;
        bool new_user = false;
        LoginState state = l_getname;
        void parse_getname(input_data &in);
        void parse_confname(input_data &in);
        void parse_pass(input_data &in);
        void parse_confpass(input_data &in);
        void parse_email(input_data &in);
        void parse_emailconf(input_data &in);
    };

    enum UserMenuState : uint8_t {
        u_main = 0,
        u_getpass = 1,
        u_confpass = 2,
        u_getname = 3,
        u_confname = 4,
        u_getemail = 5,
        u_confemail = 6,
        u_delete = 7,
        u_delconf = 8
    };

    // parser id 1
    class UserMenu : public ConnectionParser {
    public:
        using ConnectionParser::ConnectionParser;
        virtual void onStart() override;
        //virtual void onClose() override;
        virtual void parse(input_data &in) override;
    protected:
        UserMenuState state = u_main;
        std::string new_entry;
        void doLook();
        void parse_main(input_data &in);
        void parse_getname(input_data &in);
        void parse_confname(input_data &in);
        void parse_getemail(input_data &in);
        void parse_confemail(input_data &in);
        void parse_getpass(input_data &in);
        void parse_confpass(input_data &in);
        void parse_delete(input_data &in);
        void parse_delconf(input_data &in);
    };

    enum CharMenuState : uint8_t {
        c_main = 0,
        c_desc = 1,
        c_delete = 2
    };

    class CharMenu : public ConnectionParser {
    public:
        using ConnectionParser::ConnectionParser;
        virtual void onStart() override;
        virtual void parse(input_data &in) override;
    protected:
    };

    // parser id 3
    class ConnSession : public ConnectionParser {
    public:
        using ConnectionParser::ConnectionParser;
        virtual void parse(input_data &in) override;
    };

    // Descriptor/session parsers below this.
    // parser id 0
    class SessionParser : public BaseParser {
    public:
        using BaseParser::BaseParser;
        virtual void parse(input_data &in) override;
        virtual void onHeartbeat() override;
    protected:
        std::list<input_data> input;
    };

    // Characters/mobile parsers below this.
    // parser id 0
    class MobileParser : public BaseParser {
    public:
        using BaseParser::BaseParser;
        virtual void parse(input_data &in) override;
        void clearInput();
        virtual void onHeartbeat() override;
        virtual void onClose() override;
    protected:
        std::list<input_data> input;
    };
}

#endif //CIRCLE_PARSER_H
