//
// Created by volund on 6/20/22.
//

#include "core.h"
#include "spdlog/sinks/daily_file_sink.h"


entt::registry world;

std::unordered_map<unique_t, entity_t> entity_instances;

std::map<zone_vnum, entity_t> zone_table;
std::map<room_vnum, entity_t> room_table;
std::map<obj_vnum, entity_t> object_prototypes;
std::map<mob_vnum, entity_t> mobile_prototypes;
std::map<trig_vnum, entity_t> script_prototypes;
std::map<guild_vnum, entity_t> guild_table;
std::map<shop_vnum, entity_t> shop_table;
std::map<house_vnum, entity_t> house_table;

fs::path cwd, bin_dir, legacy_dir, asset_dir, log_dir, save_dir, backup_dir;

/* Prefer the file over the descriptor. */
void setup_log(const std::string &filename)
{

    auto fname = log_dir / filename;

    auto logger = spdlog::daily_logger_mt("ringmud", fname.relative_path(), 0, 0);
    logger->set_level(spdlog::level::debug);

    spdlog::set_default_logger(logger);

}