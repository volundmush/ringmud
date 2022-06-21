//
// Created by volund on 6/20/22.
//

#ifndef RINGMUD_INCLUDE_RINGMUD_COMPONENTS_ACCOUNT
#define RINGMUD_INCLUDE_RINGMUD_COMPONENTS_ACCOUNT

#include "sysdep.h"

namespace ring::net {
    class MudConnection;
}

namespace ring::components {
    struct Account {
        Account();
        explicit Account(const nlohmann::json &j);
        std::string name;
        std::string email;
        std::string pass;
        std::string account_id;
        uint64_t rpp = 0, total = 0;
        int slots = 3, level;
        std::vector<entity_t> characters;
        std::set<std::weak_ptr<ring::net::MudConnection>> connections;
        std::set<entity_t> online_as;
        bool custom = false;
        void loadJson(const nlohmann::json &j);
        nlohmann::json serialize() const;
    };
}

#endif //RINGMUD_INCLUDE_RINGMUD_COMPONENTS_ACCOUNT
