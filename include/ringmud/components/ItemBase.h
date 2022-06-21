//
// Created by volund on 6/20/22.
//

#ifndef CIRCLE_INCLUDE_COMPONENTS_ITEMBASE
#define CIRCLE_INCLUDE_COMPONENTS_ITEMBASE

#include "sysdep.h"

#include "old_enums.h"

namespace ring::components {

    struct obj_affected_type {
        int location;       /* Which ability to change (APPLY_XXX) */
        int specific;       /* Some locations have parameters      */
        int64_t modifier;       /* How much it changes by              */
    };

    struct ItemBase {
        std::array<int, NUM_OBJ_VAL_POSITIONS> values{};   /* Values of the item (see list)    */
        int8_t type_flag{};      /* Type of item                        */
        std::bitset<NUM_WEARS> wear_flags{}; /* Where you can wear it     */
        std::bitset<NUM_ITEM_FLAGS> extra_flags{}; /* If it hums, glows, etc.  */
        std::array<obj_affected_type, MAX_OBJ_AFFECT> affected{};  /* affects */

    };
}

#endif //CIRCLE_INCLUDE_COMPONENTS_ITEMBASE
