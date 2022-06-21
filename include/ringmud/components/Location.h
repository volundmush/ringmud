//
// Created by volund on 6/20/22.
//

#ifndef CIRCLE_LOCATION_COMPONENT_H
#define CIRCLE_LOCATION_COMPONENT_H

#include "sysdep.h"

enum LocationType : uint8_t {
    INVENTORY = 0,
    EQUIPMENT = 1,
    MAP = 2,
    SPACE = 3,
    LEGACY_ROOM = 4
};

struct Coordinates {
    coordinate_t x = 0;
    coordinate_t y = 0;
    coordinate_t z = 0;
};

struct ContentsComponent {
    std::map<LocationType, std::list<entity_t>> contents;
};

struct LocationComponent {
    entity_t holder;
    LocationType loc_type;
    Coordinates coordinates;
};

#endif //CIRCLE_LOCATION_COMPONENT_H
