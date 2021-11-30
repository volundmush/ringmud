//
// Created by volund on 11/25/21.
//

#include "room.h"
#include "zone.h"

namespace ring::room {
    std::map<vnum, entt::entity> rooms;
    std::function<void(vnum v, entt::entity ent)> on_create_room, on_delete_room, on_make_room;
    std::function<void(vnum v, entt::entity ent, nlohmann::json &j)> on_save_room, on_load_room;

    std::map<Direction, Direction> opposite_dir = {
            {North, South},
            {South, North},

            {East, West},
            {West, East},

            {Up, Down},
            {Down, Up},

            {Northwest, Southeast},
            {Southeast, Northwest},

            {Northeast, Southwest},
            {Southwest, Northeast},

            {Inside, Outside},
            {Outside, Inside}
    };

    entt::entity make_room(vnum zone, vnum new_room) {
        auto new_ent = ring::core::registry.create();
        auto &rdata = ring::core::registry.emplace<RoomData>(new_ent);
        rdata.entity = new_ent;
        rdata.vn = new_room;
        rdata.zone = zone;
        rooms[new_room] = new_ent;
        auto zent = ring::zone::zones[zone];
        auto &zindex = ring::core::registry.get<zone::ZoneIndex>(zent);
        zindex.rooms[new_room] = new_ent;
        if(on_make_room) on_make_room(new_room, new_ent);
        return new_ent;
    }

    entt::entity create(vnum new_room) {
        if(rooms.count(new_room)) throw std::runtime_error(fmt::format("Room {} already exists!", new_room));
        auto zone = ring::zone::zone_for(new_room);
        if(!zone.has_value()) throw std::runtime_error(fmt::format("Vnum {} lies outside any zone.", new_room));
        auto ent = make_room(zone.value(), new_room);
        if(on_create_room) on_create_room(new_room, ent);
        return ent;
    }

    nlohmann::json save_room(vnum room) {
        auto ent = rooms[room];
        nlohmann::json j;
        // TODO: export the room
        if(on_save_room) on_save_room(room, ent, j);
        return j;
    }

    void load_room(vnum zone, vnum room, nlohmann::json &j) {
        auto ent = make_room(zone, room);
        auto &rdata = ring::core::registry.get<RoomData>(ent);

        // TODO: read from json here.

        if(on_load_room) on_load_room(room, ent, j);
    }

    void load_rooms(vnum zone, entt::entity zent, nlohmann::json &j) {
        for(nlohmann::json::iterator it = j.begin(); it != j.end();it++) {
            vnum rvnum = std::strtoull(it.key().c_str(), nullptr, 10);
            load_room(zone, rvnum, it.value());
        }
    }


}