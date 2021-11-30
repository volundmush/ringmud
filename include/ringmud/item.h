//
// Created by volund on 11/25/21.
//

#ifndef RINGMUD_ITEM_H
#define RINGMUD_ITEM_H

#include "core.h"

namespace ring::item {

    extern std::map<vnum, entt::entity> items;
    extern std::set<entt::entity> instances;

    extern std::function<void(vnum, entt::entity)> on_create_item, on_delete_item, on_make_item;
    extern std::function<void(vnum, entt::entity, nlohmann::json&)> on_save_item, on_load_item;

    extern std::function<void(vnum, entt::entity)> on_make_instance, on_create_instance;
    extern std::function<void(entt::entity, nlohmann::json&)> on_save_instance, on_load_instance;

    struct ItemProtoData {
        entt::entity entity;
        vnum vn;
        std::set<entt::entity> instances;
        std::vector<std::string> keywords;
        std::string name = "Unfinished Item", short_desc = "An Unfinished Item", action_desc = "Vaguely Does Something";
        std::string description = "An Unfinished Item";
        std::set<flag> extra, wear, perm;
        uint8_t item_type;
        std::map<uint8_t, int64_t> values;
        uint64_t weight, cost, rent, level;
        uint8_t size;
    };

    struct ItemInstanceData {
        entt::entity entity;
        vnum vn;
        entt::entity prototype;
    };

    entt::entity make_instance(vnum new_item);

    entt::entity create_instance(vnum new_item);

    entt::entity load_instance(vnum item, nlohmann::json& j);

    entt::entity make_item(vnum new_item);

    entt::entity create(vnum new_item);

    nlohmann::json save_item(vnum item);

    nlohmann::json save_instance(entt::entity ent);

    entt::entity load_item(vnum item, nlohmann::json& j);

    void load_items(vnum zone, entt::entity zent, nlohmann::json& j);

}

#endif //RINGMUD_ITEM_H
