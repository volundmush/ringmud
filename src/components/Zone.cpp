//
// Created by volund on 6/20/22.
//

#include "components/Zone.h"

namespace ring::components {

    const std::map<int, std::string> zone_flags = {
            {ZONE_CLOSED,   "CLOSED"},
            {ZONE_NOIMMORT, "NOIMMORT"},
            {ZONE_QUEST,    "QUEST"},
            {ZONE_DBALLS,   "DBALLS"}
    };

    nlohmann::json zone_reset_instruct::serialize() {
        nlohmann::json j;
        std::string comm;
        comm.push_back(command);
        j["command"] = comm;
        if (if_flag) j["if_flag"] = if_flag;
        if (arg1) j["arg1"] = arg1;
        if (arg2) j["arg2"] = arg2;
        if (arg3) j["arg3"] = arg3;
        if (arg4) j["arg4"] = arg4;
        if (arg5) j["arg5"] = arg5;
        j["line"] = line;
        if (!sarg1.empty()) j["sarg1"] = sarg1;
        if (!sarg2.empty()) j["sarg2"] = sarg2;
        return j;
    }

    zone_reset_instruct::zone_reset_instruct() = default;

    zone_reset_instruct::zone_reset_instruct(const nlohmann::json &j) {
        if (j.contains("command")) {
            std::string comm = j["command"];
            command = !comm.empty() ? comm[0] : ' ';
        }
        if (j.contains("if_flag")) if_flag = j["if_flag"];
        if (j.contains("arg1")) arg1 = j["arg1"];
        if (j.contains("arg2")) arg2 = j["arg2"];
        if (j.contains("arg3")) arg3 = j["arg3"];
        if (j.contains("arg4")) arg4 = j["arg4"];
        if (j.contains("arg5")) arg5 = j["arg5"];
        if (j.contains("line")) line = j["line"];
        if (j.contains("sarg1")) sarg1 = j["sarg1"];
        if (j.contains("sarg2")) sarg1 = j["sarg2"];
    }

    ZoneData::ZoneData() = default;

    ZoneData::ZoneData(const nlohmann::json &j) {
        number = j["number"];
        if (j.contains("name")) name = j["name"];
        if (j.contains("builders")) for (std::string j2: j["builders"]) builders.insert(j2);
        if (j.contains("lifespan")) lifespan = j["lifespan"];
        if (j.contains("bot")) bot = j["bot"];
        if (j.contains("top")) top = j["top"];
        if (j.contains("reset_mode")) reset_mode = j["reset_mode"];
        if (j.contains("min_level")) min_level = j["min_level"];
        if (j.contains("max_level")) max_level = j["max_level"];
        if (j.contains("zone_flags")) for (int i: j["zone_flags"]) zone_flags[i] = true;
        if (j.contains("cmd")) for (const auto &j4: j["cmd"]) cmd.emplace_back(j4);
    }

    void ZoneData::reset_lines() {
        int i = 0;
        for (auto &c: cmd) {
            c.line = i++;
        }
    }

    nlohmann::json ZoneData::serialize() {
        nlohmann::json j;
        if (!name.empty()) j["name"] = name;
        if (lifespan) j["lifespan"] = lifespan;
        if (bot) j["bot"] = bot;
        if (top) j["top"] = top;
        if (reset_mode) j["reset_mode"] = reset_mode;
        if (min_level) j["min_level"] = min_level;
        if (max_level) j["max_level"] = max_level;
        if (number) j["number"] = number;

        if (!builders.empty()) j["builders"] = builders;

        reset_lines();
        for (auto &c: cmd) j["cmd"].push_back(c.serialize());

        for (int i = 0; i < zone_flags.size(); i++) if (zone_flags[i]) j["zone_flags"].push_back(i);

        return j;
    }

}