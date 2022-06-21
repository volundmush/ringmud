//
// Created by volund on 6/20/22.
//

#ifndef CIRCLE_INCLUDE_LEGACY_WEAR
#define CIRCLE_INCLUDE_LEGACY_WEAR

/* Character equipment positions: used as index for char_data.equipment[] */
/* NOTE: Don't confuse these constants with the ITEM_ bitvectors
   which control the valid places you can wear a piece of equipment */
#define WEAR_UNUSED0    0
#define WEAR_FINGER_R   1
#define WEAR_FINGER_L   2
#define WEAR_NECK_1     3
#define WEAR_NECK_2     4
#define WEAR_BODY       5
#define WEAR_HEAD       6
#define WEAR_LEGS       7
#define WEAR_FEET       8
#define WEAR_HANDS      9
#define WEAR_ARMS      10
#define WEAR_UNUSED1   11
#define WEAR_ABOUT     12
#define WEAR_WAIST     13
#define WEAR_WRIST_R   14
#define WEAR_WRIST_L   15
#define WEAR_WIELD1    16
#define WEAR_WIELD2    17
#define WEAR_BACKPACK  18
#define WEAR_EAR_R     19
#define WEAR_EAR_L     20
#define WEAR_SH        21
#define WEAR_EYE       22

#define NUM_WEARS      23    /* This must be the # of eq positions!! */

#endif //CIRCLE_INCLUDE_LEGACY_WEAR
