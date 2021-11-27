//
// Created by volund on 11/25/21.
//

#include "item.h"

namespace ring::item {

    std::map<vnum, entt::entity> items;
    std::set<entt::entity> instances;

    std::function<void(vnum v, entt::entity ent)> on_create_item, on_delete_item, on_make_item;
    std::function<void(vnum v, entt::entity ent, nlohmann::json &j)> on_save_item, on_load_item;

    std::function<void(vnum v, entt::entity ent)> on_make_instance;
    std::function<void(entt::entity ent, nlohmann::json &j)> on_save_instance, on_load_instance;

    entt::entity make_instance(vnum new_item) {
        auto pent = items[new_item];
        auto new_ent = ring::core::registry.create();
        auto &iprot = ring::core::registry.get<ItemProtoData>(pent);
        auto &idata = ring::core::registry.emplace<ItemInstanceData>(new_ent);
        idata.vn = new_item;
        idata.entity = new_ent;
        iprot.instances.insert(new_ent);
        idata.prototype = pent;
        instances.insert(new_ent);
        if(on_make_instance) on_make_instance(new_item, new_ent);
        return new_ent;
    }

    entt::entity make_item(vnum new_item) {
        auto new_ent = ring::core::registry.create();
        auto &iprot = ring::core::registry.emplace<ItemProtoData>(new_ent);
        iprot.vn = new_item;
        iprot.entity = new_ent;
        items[new_item] = new_ent;
        if(on_make_item) on_make_item(new_item, new_ent);
        return new_ent;
    }

    entt::entity create_instance(vnum new_item) {
        if(!items.count(new_item))
            throw std::runtime_error(fmt::format("Item {} does not exist!", new_item));
        auto ent = make_instance(new_item);
        if(on_create_instance) on_create_instance(new_item, ent);
        return ent;
    }

    entt::entity create(vnum new_item) {
        if(items.count(new_item))
            throw std::runtime_error(fmt::format("Item {} already exists!", new_item));
        auto ent = make_item(new_item);
        if(on_create_item) on_create_item(new_item, ent);
        return ent;
    }

    nlohmann::json save_instance(entt::entity ent) {
        nlohmann::json j;
        // TODO: export the item instance.
        if(on_save_instance) on_save_instance(ent, j);
        return j;
    }

    nlohmann::json save_item(vnum item) {
        auto ent = items[item];
        nlohmann::json j;
        // TODO: export the item
        if(on_save_item) on_save_item(item, ent, j);
        return j;
    }

    entt::entity load_item(vnum item, nlohmann::json& j) {
        auto ent = make_item(item);
        auto &pdata = ring::core::registry.get<ItemProtoData>(ent);

        if(on_load_item) on_load_item(item, ent, j);
        return ent;
    }

    entt::entity load_instance(vnum item, nlohmann::json& j) {
        auto ent = make_instance(item);
        if(on_load_instance) on_load_instance(ent, j);
    }

    void load_items(vnum zone, entt::entity zent, nlohmann::json& j) {
        for(nlohmann::json::iterator it = j.begin(); it != j.end();it++) {
            vnum vn = std::strtoull(it.key().c_str(), nullptr, 10);
            load_item(vn, it.value());
        }
    }

}