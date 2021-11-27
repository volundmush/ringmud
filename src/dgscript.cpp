//
// Created by volund on 11/25/21.
//

#include "dgscript.h"

namespace ring::dgscript {

    DgScriptEnv::DgScriptEnv(entt::entity ent) : script(ent) {}

    entt::entity make_dgscript(vnum new_dgscript) {
        auto new_ent = ring::core::registry.create();
        ring::core::registry.emplace<DgScriptData>(new_ent);
        dgscripts[new_dgscript] = new_ent;
        if(on_make_dgscript) on_make_dgscript(new_dgscript, new_ent);
        return new_ent;
    }

    entt::entity create(vnum new_dgscript) {
        if(dgscripts.count(new_dgscript))
            throw std::runtime_error(fmt::format("DgScript {} already exists!", new_dgscript));
        auto ent = make_dgscript(new_dgscript);
        if(on_create_dgscript) on_create_dgscript(new_dgscript, ent);
        return ent;
    }

    nlohmann::json save_dgscript(vnum dg) {
        auto ent = dgscripts[dg];
        nlohmann::json j;
        // TODO: export the dgscripts
        if(on_save_dgscript) on_save_dgscript(dg, ent, j);
        return j;
    }

    void load_dgscript(vnum dgvnum, nlohmann::json &j) {
        auto ent = make_dgscript(dgvnum);
        auto &dgdata = ring::core::registry.get<DgScriptData>(ent);

        if(on_load_dgscript) on_load_dgscript(dgvnum, ent, j);
    }

    void load_dgscripts(vnum zone, entt::entity zent, nlohmann::json &j) {
        for(nlohmann::json::iterator it = j.begin(); it != j.end();it++) {
            vnum dgvnum = std::strtoull(it.key().c_str(), nullptr, 10);
            load_dgscript(dgvnum, it.value());
        }
    }

}