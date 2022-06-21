//
// Created by volund on 6/20/22.
//

#ifndef CIRCLE_INCLUDE_COMPONENTS_SPELLBOOK
#define CIRCLE_INCLUDE_COMPONENTS_SPELLBOOK

#include "sysdep.h"

namespace ring::components {
    struct Spellbook {
        std::map<int, int> sbinfo;  /* For spellbook info */
    };
}

#endif //CIRCLE_INCLUDE_COMPONENTS_SPELLBOOK
