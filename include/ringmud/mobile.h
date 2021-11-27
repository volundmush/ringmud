//
// Created by volund on 11/25/21.
//

#ifndef RINGMUD_MOBILE_H
#define RINGMUD_MOBILE_H

#include "core.h"

namespace ring::mobile {
    extern std::map<vnum, entt::entity> mobiles;
    extern std::set<entt::entity> instances;

    extern std::function<void(vnum, entt::entity)> on_create_mobile, on_delete_mobile, on_make_mobile;
    extern std::function<void(vnum, entt::entity, nlohmann::json&)> on_save_mobile, on_load_mobile;
    extern std::function<void(entt::entity)> handle_mobile_input;
    extern std::function<void(entt::entity, const std::string&)> handle_mobile_command;

    extern std::function<void(vnum, entt::entity)> on_make_instance, on_create_instance;
    extern std::function<void(entt::entity, nlohmann::json&)> on_save_instance, on_load_instance;

    struct MobileProtoData {
        entt::entity entity;
        vnum vn;
        std::set<entt::entity> instances;
    };

    struct MobileInstanceData {
        entt::entity entity;
        vnum vn;
        entt::entity prototype;
        std::list<std::string> input;
        opt_type<entt::entity> session;
    };

    entt::entity make_instance(vnum new_mob);

    entt::entity create_instance(vnum new_mob);

    entt::entity load_instance(vnum mob, nlohmann::json& j);

    entt::entity make_mobile(vnum new_mob);

    entt::entity create(vnum new_mob);

    nlohmann::json save_instance(entt::entity ent);

    nlohmann::json save_mobile(vnum mob);

    entt::entity load_mobile(vnum mobile, nlohmann::json& j);

    void load_mobiles(vnum zone, entt::entity zent, nlohmann::json& j);
}

#endif //RINGMUD_MOBILE_H
