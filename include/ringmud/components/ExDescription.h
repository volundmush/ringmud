//
// Created by volund on 6/20/22.
//

#ifndef CIRCLE_INCLUDE_COMPONENTS_EXDESCRIPTION
#define CIRCLE_INCLUDE_COMPONENTS_EXDESCRIPTION

#include "sysdep.h"

namespace ring::components {

    struct extra_descr_data {
        std::string keyword;                 /* Keyword in look/examine          */
        std::string description;             /* What to see                      */
    };

    struct ExDescription {
        std::vector<extra_descr_data> ex_description{}; /* extra descriptions     */
    };
}

#endif //CIRCLE_INCLUDE_COMPONENTS_EXDESCRIPTION
