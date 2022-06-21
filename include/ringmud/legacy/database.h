
//
// Created by volund on 6/21/22.
//

#ifndef RINGMUD_INCLUDE_RINGMUD_LEGACY_DATABASE
#define RINGMUD_INCLUDE_RINGMUD_LEGACY_DATABASE

#include "sysdep.h"

namespace ring::legacy {

    void load_database(const fs::path &old);

    void load_accounts(const fs::path &old);

    void load_zones(const fs::path &old);

    void load_rooms(const fs::path &old);

    void load_characters(const fs::path &old);

    void load_mobiles(const fs::path &old);

    void load_objects(const fs::path &old);

    void load_scripts(const fs::path &old);

    void load_guilds(const fs::path &old);

    void load_shops(const fs::path &old);

}

#endif //RINGMUD_INCLUDE_RINGMUD_LEGACY_DATABASE
