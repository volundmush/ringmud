//
// Created by volund on 6/20/22.
//

#ifndef CIRCLE_INCLUDE_COMPONENTS_PHYSICS
#define CIRCLE_INCLUDE_COMPONENTS_PHYSICS

#include "sysdep.h"

namespace ring::components {

    enum Sizes : int8_t {
        Undefined = -1,
        Fine = 0,
        Diminutive = 1,
        Tiny = 2,
        Small = 3,
        Medium = 4,
        Large = 5,
        Huge = 6,
        Gargantuan = 7,
        Colossal = 8
    };

    struct Physics {
        weight_t weight = 0;
        height_t height = 0;
        Sizes size = Undefined;
    };
}

#endif //CIRCLE_INCLUDE_COMPONENTS_PHYSICS
