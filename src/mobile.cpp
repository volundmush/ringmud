//
// Created by volund on 11/25/21.
//

#include "mobile.h"

namespace ring::mobile {
    std::map<vnum, entt::entity> mobiles;
    std::set<entt::entity> instances;

    std::function<void(vnum, entt::entity ent)> on_create_mobile, on_delete_mobile, on_make_mobile;
    std::function<void(vnum, entt::entity, nlohmann::json&)> on_save_mobile, on_load_mobile;
    std::function<void(entt::entity)> handle_mobile_input;
    std::function<void(entt::entity, const std::string&)> handle_mobile_command;

    std::function<void(vnum, entt::entity)> on_make_instance, on_create_instance;
    std::function<void(entt::entity, nlohmann::json&)> on_save_instance, on_load_instance;

    entt::entity make_instance(vnum new_mob) {
        auto pent = mobiles[new_mob];
        auto new_ent = ring::core::registry.create();
        auto &iprot = ring::core::registry.get<MobileProtoData>(pent);
        auto &idata = ring::core::registry.emplace<MobileInstanceData>(new_ent);
        idata.vn = new_mob;
        idata.entity = new_ent;
        iprot.instances.insert(new_ent);
        idata.prototype = pent;
        instances.insert(new_ent);
        if(on_make_instance) on_make_instance(new_mob, new_ent);
        return new_ent;
    }

    entt::entity make_mobile(vnum new_mob) {
        auto new_ent = ring::core::registry.create();
        auto &iprot = ring::core::registry.emplace<MobileProtoData>(new_ent);
        iprot.vn = new_mob;
        iprot.entity = new_ent;
        mobiles[new_mob] = new_ent;
        if(on_make_mobile) on_make_mobile(new_mob, new_ent);
        return new_ent;
    }

    entt::entity create_instance(vnum new_mob) {
        if(!mobiles.count(new_mob))
            throw std::runtime_error(fmt::format("Mobile {} does not exist!", new_mob));
        auto ent = make_instance(new_mob);
        if(on_create_instance) on_create_instance(new_mob, ent);
        return ent;
    }

    entt::entity create(vnum new_mob) {
        if(mobiles.count(new_mob))
            throw std::runtime_error(fmt::format("Mobile {} already exists!", new_mob));
        auto ent = make_mobile(new_mob);
        if(on_create_mobile) on_create_mobile(new_mob, ent);
        return ent;
    }

    nlohmann::json save_instance(entt::entity ent) {
        nlohmann::json j;
        // TODO: export the mobile instance.
        if(on_save_instance) on_save_instance(ent, j);
        return j;
    }

    nlohmann::json save_mobile(vnum mob) {
        auto ent = mobiles[mob];
        nlohmann::json j;
        // TODO: export the mobile
        if(on_save_mobile) on_save_mobile(mob, ent, j);
        return j;
    }

    entt::entity load_mobile(vnum mobile, nlohmann::json& j) {
        auto ent = make_mobile(mobile);
        auto &pdata = ring::core::registry.get<MobileProtoData>(ent);

        if(on_load_mobile) on_load_mobile(mobile, ent, j);
        return ent;
    }

    entt::entity load_instance(vnum item, nlohmann::json& j) {
        auto ent = make_instance(item);
        if(on_load_instance) on_load_instance(ent, j);
    }

    void load_mobiles(vnum zone, entt::entity zent, nlohmann::json& j) {
        for(nlohmann::json::iterator it = j.begin(); it != j.end();it++) {
            vnum vn = std::strtoull(it.key().c_str(), nullptr, 10);
            load_mobile(vn, it.value());
        }
    }

}