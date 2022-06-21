//
// Created by volund on 6/20/22.
//

#ifndef CIRCLE_INCLUDE_COMPONENTS_ALIGNMENT
#define CIRCLE_INCLUDE_COMPONENTS_ALIGNMENT

#include "sysdep.h"

namespace ring::components {
    struct Alignment {
        const std::string& getAlignmentName();
        void setAlignment(alignment_t val);
        void modAlignment(alignment_t val);
        appearance_t getAlignmentTier() const;
        bool isGood() const;
        bool isEvil() const;
        bool isNeutral() const;
        alignment_t alignment = 0;
    };
}

#endif //CIRCLE_INCLUDE_COMPONENTS_ALIGNMENT
