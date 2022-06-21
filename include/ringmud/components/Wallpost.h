//
// Created by volund on 6/20/22.
//

#ifndef CIRCLE_INCLUDE_COMPONENTS_WALLPOST
#define CIRCLE_INCLUDE_COMPONENTS_WALLPOST

#include "sysdep.h"

namespace ring::components {
    struct Wallpost {
        int posttype{};
        struct obj_data *posted_to{};
        struct obj_data *fellow_wall{};
    };
}

#endif //CIRCLE_INCLUDE_COMPONENTS_WALLPOST
