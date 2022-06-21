//
// Created by volund on 6/20/22.
//

#ifndef RINGMUD_INCLUDE_RINGMUD_COMPONENTS_ZONE
#define RINGMUD_INCLUDE_RINGMUD_COMPONENTS_ZONE

#include "sysdep.h"
#include "legacy/map.h"
#include "legacy/admin.h"

namespace ring::components {

    extern const std::map<int, std::string> zone_flags;

    /* structure for the reset commands */
    struct zone_reset_instruct {
        explicit zone_reset_instruct();

        zone_reset_instruct(const nlohmann::json &j);

        char command;   /* current command                      */

        bool if_flag;    /* if TRUE: exe only if preceding exe'd */
        vnum arg1;        /*                                      */
        vnum arg2;        /* Arguments to the command             */
        vnum arg3;        /*                                      */
        vnum arg4;        /* room_max  default 0			*/
        vnum arg5;           /* percentages variable                 */
        int line;        /* line number this command appears on  */
        std::string sarg1;        /* string argument                      */
        std::string sarg2;        /* string argument                      */

        /*
         *  Commands:              *
         *  'M': Read a mobile     *
         *  'O': Read an object    *
         *  'G': Give obj to mob   *
         *  'P': Put obj in obj    *
         *  'G': Obj to char       *
         *  'E': Obj to char equip *
         *  'D': Set state of door *
         *  'T': Trigger command   *
             *  'V': Assign a variable *
        */
        nlohmann::json serialize();

        void loadJson(const nlohmann::json &j);
    };

    struct Zone {
        entity_t zone;
    };

    struct ZoneData {
        ZoneData();

        explicit ZoneData(const nlohmann::json &j);

        std::string name = "New ZoneData";            /* name of this zone                  */
        std::set<std::string> builders;          /* namelist of builders allowed to    */
        /* modify this zone.		  */
        int lifespan = 30;           /* how long between resets (minutes)  */
        int age;                /* current age of this zone (minutes) */
        vnum bot;           /* starting room number for this zone */
        vnum top;           /* upper limit for room_table in this zone */

        /*
         * Reset mode:
         *   0: Don't reset, and don't update age.
         *   1: Reset if no PC's are located in zone.
         *   2: Just reset.
         */

        int reset_mode = 2;         /* conditions for reset (see below)   */
        zone_vnum number;        /* virtual number of this zone	  */
        std::vector<zone_reset_instruct> cmd;   /* command table for reset	          */
        int min_level;           /* Minimum level to enter zone        */
        int max_level = ADMLVL_IMPL;           /* Max Mortal level to enter zone     */
        std::bitset<NUM_ZONE_FLAGS> zone_flags;          /* Flags for the zone.                */
        opt_type<entity_t> sphere;
        fs::path dir;
        std::map<room_vnum, entity_t> rooms;
        std::map<mob_vnum, entity_t> mobiles;
        std::map<obj_vnum, entity_t> objects;
        std::map<trig_vnum, entity_t> triggers;
        std::map<shop_vnum, entity_t> shops;
        std::map<guild_vnum, entity_t> guilds;

        void reset_lines();

        nlohmann::json serialize();

    };
}

#endif //RINGMUD_INCLUDE_RINGMUD_COMPONENTS_ZONE
