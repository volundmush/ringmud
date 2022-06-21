//
// Created by volund on 6/20/22.
//

#ifndef RINGMUD_INCLUDE_RINGMUD_COMPONENTS_DGSCRIPTHOLDER
#define RINGMUD_INCLUDE_RINGMUD_COMPONENTS_DGSCRIPTHOLDER

#include "sysdep.h"

namespace ring::components {

    struct DgScriptProto {
        explicit DgScriptProto();
        DgScriptProto(const nlohmann::json &j);
        int8_t attach_type;			/* mob/obj/wld intentions          */
        int8_t data_type;		        /* type of game_data for trig      */
        std::string name;			        /* name of trigger                 */
        long trigger_type;			/* type of trigger (for bitvector) */
        std::vector<std::string> cmdlist;	/* top of command list             */
        int narg;				/* numerical argument              */
        std::string arglist;			/* argument list                   */
        std::set<entt::entity> instances;

        nlohmann::json serialize();
    };

    enum TrigState : uint8_t {
        dormant = 0,
        running = 1,
        waiting = 2,
        error = 3,
        done = 4,
        purged = 5
    };


    enum NestType : uint8_t {
        IF = 0,
        WHILE = 1,
        SWITCH = 2
    };

    struct DgScriptState {
        entity_t proto;
        entity_t actor;
        TrigState state = dormant;
        std::size_t curr_line = 0; /* ptr to current line of trigger  */
        std::list<std::pair<NestType, std::size_t>> depth; /* depth into nest ifs/whiles/etc  */
        int loops = 0;				/* loop iteration counter          */
        uint64_t when;   	/* pulse the trigger will resume      */
        std::map<std::string, std::string> var_list;	/* list of local vars for trigger  */
    };

    struct DgScriptHolder {
        explicit DgScriptHolder();
        DgScriptHolder(const nlohmann::json &j);
        long types;				/* bitvector of trigger types */
        std::list<entity_t> scripts; /* list of active scripts  */
        std::map<std::string, std::string> variables;	/* list of entity variables   */
    };
}

#endif //RINGMUD_INCLUDE_RINGMUD_COMPONENTS_DGSCRIPTHOLDER
