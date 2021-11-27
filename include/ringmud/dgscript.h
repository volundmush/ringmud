//
// Created by volund on 11/25/21.
//

#ifndef RINGMUD_DGSCRIPT_H
#define RINGMUD_DGSCRIPT_H

#include "core.h"

namespace ring::dgscript {
    extern std::map<vnum, entt::entity> dgscripts;
    extern std::function<void(vnum v, entt::entity ent)> on_create_dgscript, on_delete_dgscript, on_make_dgscript;
    extern std::function<void(vnum v, entt::entity ent, nlohmann::json &j)> on_save_dgscript, on_load_dgscript;

    struct DgScriptData {
        std::string name{};
        uint64_t trigger_type = 0;
        uint8_t attach_type = 0, data_type = 0;
        std::vector<std::string> cmdlist;
    };

    enum DgScriptVarType : uint8_t {
        Text = 0,
        Float = 1,
        Uint = 2,
        Int = 3,
        Vnum = 4
    };

    struct DgScriptVar {
        DgScriptVarType varType = Text;
        std::string str;
        double fl = 0;
        uint64_t unumber = 0;
        int64_t number = 0;
        vnum vnum = 0;
        bool valid = false;
    };

    struct DgScriptEnv {
        explicit DgScriptEnv(entt::entity ent);
        entt::entity script;  // Points at the DgScript entity.
        uint8_t narg = 0, depth = 0, loops = 0;
        bool purged = false;
        std::map<std::string, DgScriptVar> vars{};
        uint64_t wait_pulses = 0;
        std::size_t cur_line = 0;
    };

    entt::entity make_dgscript(vnum new_dgscript);

    entt::entity create(vnum new_dgscript);

    nlohmann::json save_dgscript(vnum dg);

    void load_dgscript(vnum dgvnum, nlohmann::json &j);

    void load_dgscripts(vnum zone, entt::entity zent, nlohmann::json &j);

}

#endif //RINGMUD_DGSCRIPT_H
