//
// Created by volund on 6/20/22.
//

#ifndef RINGMUD_INCLUDE_RINGMUD_COMPONENTS_SPHERE
#define RINGMUD_INCLUDE_RINGMUD_COMPONENTS_SPHERE

#include "sysdep.h"

namespace ring::components {

    struct Sphere {
        entity_t sphere;
    };

    struct SphereData {
        std::string id;
        gravity_t gravity = 1;
        std::set<int> claim_flags;
        std::set<zone_vnum> claim_zones;
        std::list<entity_t> rooms;
    };
}

#endif //RINGMUD_INCLUDE_RINGMUD_COMPONENTS_SPHERE
