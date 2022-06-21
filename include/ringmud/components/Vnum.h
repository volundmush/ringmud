//
// Created by volund on 6/20/22.
//

#ifndef CIRCLE_VNUMCOMPONENT_H
#define CIRCLE_VNUMCOMPONENT_H

#include "sysdep.h"

namespace ring::components {
    enum VnumType : uint8_t {
        ROOM = 0,
        MOBILE = 1,
        OBJECT = 2,
        GUILD = 3,
        SHOP = 4,
        TRIGGER = 5
    };

    struct VnumComponent {
        vnum number;
        VnumType type;
    };
}


#endif //CIRCLE_VNUMCOMPONENT_H
