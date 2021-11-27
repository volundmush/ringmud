//
// Created by volund on 11/25/21.
//

#ifndef RINGMUD_ROOM_H
#define RINGMUD_ROOM_H

#include "core.h"

namespace ring::room {
    extern std::map<vnum, entt::entity> rooms;

    extern std::function<void(vnum v, entt::entity ent)> on_create_room, on_delete_room, on_make_room;
    extern std::function<void(vnum v, entt::entity ent, nlohmann::json &j)> on_save_room, on_load_room;

    struct ExitData {
        std::string keyword, description;
        uint16_t exit_info = 0;
        opt_type<vnum> key, to_room, failroom, totalfailroom;
        int dclock = 0, dhide = 0, dcskill = 0, dcmove = 0, failsavetype = 0, dcfailsave = 0;
    };

    struct RoomData {
        vnum zone, vn;
        entt::entity entity;
        std::string name = "Unnamed Room", description = "It looks unfinished...";
        std::map<std::string, std::string> ex_descriptions;
        std::map<uint8_t, ExitData> exits;
        std::set<flag> flags;
        std::set<vnum> objects, mobiles;
    };

    entt::entity make_room(vnum zone, vnum new_room);

    entt::entity create(vnum new_room);

    nlohmann::json save_room(vnum room);

    void load_room(vnum zone, vnum room, nlohmann::json &j);

    void load_rooms(vnum zone, entt::entity zent, nlohmann::json &j);
}

#endif //RINGMUD_ROOM_H
