//
// Created by volund on 6/20/22.
//

#ifndef CIRCLE_INCLUDE_COMPONENTS_SEEKER
#define CIRCLE_INCLUDE_COMPONENTS_SEEKER

#include "sysdep.h"

namespace ring::components {
    struct Seeker {
        int kitype;
        entity_t user;
        entity_t target;
        int64_t kicharge{};
    };
}

#endif //CIRCLE_INCLUDE_COMPONENTS_SEEKER
