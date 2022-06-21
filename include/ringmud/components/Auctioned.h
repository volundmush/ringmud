//
// Created by volund on 6/20/22.
//

#ifndef CIRCLE_INCLUDE_COMPONENTS_AUCTIONED
#define CIRCLE_INCLUDE_COMPONENTS_AUCTIONED

#include "sysdep.h"

namespace ring::components {
    struct Auctioned {
        int32_t aucter{};
        int32_t curBidder{};
        time_t aucTime{};
        int bid{};
        int startbid{};
        char *auctname{};
    };
}

#endif //CIRCLE_INCLUDE_COMPONENTS_AUCTIONED
