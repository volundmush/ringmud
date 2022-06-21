//
// Created by volund on 6/20/22.
//

#ifndef CIRCLE_INCLUDE_COMPONENTS_PRICE
#define CIRCLE_INCLUDE_COMPONENTS_PRICE

#include "sysdep.h"

namespace ring::components {
    struct Price {
        money_clamped_t cost = 0;           /* Value when sold (gp.)               */
        money_clamped_t cost_per_day = 0;   /* Cost to keep pr. real day           */
    };
}

#endif //CIRCLE_INCLUDE_COMPONENTS_PRICE
