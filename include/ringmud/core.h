//
// Created by volund on 6/20/22.
//

#ifndef RINGMUD_INCLUDE_RINGMUD_CORE
#define RINGMUD_INCLUDE_RINGMUD_CORE

#include "sysdep.h"
#include "spdlog/spdlog.h"

extern entt::registry world;

extern std::unordered_map<unique_t, entity_t> entity_instances;

extern std::map<zone_vnum, entity_t> zone_table;
extern std::map<room_vnum, entity_t> room_table;
extern std::map<obj_vnum, entity_t> object_prototypes;
extern std::map<mob_vnum, entity_t> mobile_prototypes;
extern std::map<trig_vnum, entity_t> script_prototypes;
extern std::map<guild_vnum, entity_t> guild_table;
extern std::map<shop_vnum, entity_t> shop_table;
extern std::map<house_vnum, entity_t> house_table;

extern fs::path cwd, legacy_dir, asset_dir, log_dir, save_dir, backup_dir;

void setup_log(const std::string &filename);

#endif //RINGMUD_INCLUDE_RINGMUD_CORE
