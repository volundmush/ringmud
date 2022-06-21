//
// Created by volund on 6/20/22.
//

#ifndef CIRCLE_INCLUDE_COMPONENTS_AFFECTS
#define CIRCLE_INCLUDE_COMPONENTS_AFFECTS

#include "sysdep.h"
#include "legacy/affects.h"

namespace ring::components {

    extern const std::map<int, std::string> affects;

    struct Affects {

        std::bitset<NUM_AFF_FLAGS> affected_by;
    };
}

#endif //CIRCLE_INCLUDE_COMPONENTS_AFFECTS
