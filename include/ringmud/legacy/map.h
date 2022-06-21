//
// Created by volund on 6/20/22.
//

#ifndef CIRCLE_INCLUDE_LEGACY_MAP
#define CIRCLE_INCLUDE_LEGACY_MAP


/* The cardinal directions: used as index to room_data.dir_option[] */
#define NORTH          0
#define EAST           1
#define SOUTH          2
#define WEST           3
#define UP             4
#define DOWN           5
#define NORTHWEST      6
#define NORTHEAST      7
#define SOUTHEAST      8
#define SOUTHWEST      9
#define INDIR         10
#define OUTDIR        11

/* Room flags: used in room_data.room_flags */
/* WARNING: In the room_table files, NEVER set the bits marked "R" ("Reserved") */
#define ROOM_DARK        0   /* Dark			*/
#define ROOM_DEATH        1   /* Death trap		*/
#define ROOM_NOMOB        2   /* MOBs not allowed		*/
#define ROOM_INDOORS    3   /* Indoors			*/
#define ROOM_PEACEFUL    4   /* Violence not allowed	*/
#define ROOM_SOUNDPROOF    5   /* Shouts, gossip blocked	*/
#define ROOM_NOTRACK    6   /* Track won't go through	*/
#define ROOM_NOINSTANT    7   /* IT not allowed		*/
#define ROOM_TUNNEL        8   /* room for only 1 pers	*/
#define ROOM_PRIVATE    9   /* Can't teleport in		*/
#define ROOM_GODROOM    10  /* LVL_GOD+ only allowed	*/
#define ROOM_HOUSE        11  /* (R) Room is a house	*/
#define ROOM_HOUSE_CRASH 12  /* (R) House needs saving	*/
#define ROOM_ATRIUM        13  /* (R) The door to a house	*/
#define ROOM_OLC        14  /* (R) Modifyable/!compress	*/
#define ROOM_BFS_MARK    15  /* (R) breath-first srch mrk	*/
#define ROOM_VEHICLE    16  /* Requires a vehicle to pass       */
#define ROOM_UNDERGROUND        17  /* Room is below ground      */
#define ROOM_CURRENT        18  /* Room move with random currents	*/
#define ROOM_TIMED_DT        19  /* Room has a timed death trap  	*/
#define ROOM_EARTH              20  /* Room is on Earth */
#define ROOM_VEGETA             21  /* Room is on Vegeta */
#define ROOM_FRIGID             22  /* Room is on Frigid */
#define ROOM_KONACK             23  /* Room is on Konack */
#define ROOM_NAMEK              24  /* Room is on Namek */
#define ROOM_NEO                25  /* Room is on Neo */
#define ROOM_AL                 26  /* Room is on AL */
#define ROOM_SPACE              27  /* Room is on Space */
#define ROOM_HELL               28  /* Room is Punishment Hell*/
#define ROOM_REGEN              29  /* Better regen */
#define ROOM_RHELL              30  /* Room is HELLLLLLL */
#define ROOM_GRAVITYX10         31  /* For room_table that have 10x grav */
#define ROOM_AETHER        32  /* Room is on Aether */
#define ROOM_HBTC               33  /* Room is extra special training area */
#define ROOM_PAST               34  /* Inside the pendulum room */
#define ROOM_CBANK              35  /* This room is a clan bank */
#define ROOM_SHIP               36  /* This room is a private ship room */
#define ROOM_YARDRAT            37  /* This room is on planet Yardrat   */
#define ROOM_KANASSA            38  /* This room is on planet Kanassa   */
#define ROOM_ARLIA              39  /* This room is on planet Arlia     */
#define ROOM_AURA               40  /* This room has an aura around it  */
#define ROOM_EORBIT             41  /* Earth Orbit                      */
#define ROOM_FORBIT             42  /* Frigid Orbit                     */
#define ROOM_KORBIT             43  /* Konack Orbit                     */
#define ROOM_NORBIT             44  /* Namek  Orbit                     */
#define ROOM_VORBIT             45  /* Vegeta Orbit                     */
#define ROOM_AORBIT             46  /* Aether Orbit                     */
#define ROOM_YORBIT             47  /* Yardrat Orbit                    */
#define ROOM_KANORB             48  /* Kanassa Orbit                    */
#define ROOM_ARLORB             49  /* Arlia Orbit                      */
#define ROOM_NEBULA             50  /* Nebulae                          */
#define ROOM_ASTERO             51  /* Asteroid                         */
#define ROOM_WORMHO             52  /* Wormhole                         */
#define ROOM_STATION            53  /* Space Station                    */
#define ROOM_STAR               54  /* Is a star                        */
#define ROOM_CERRIA             55  /* This room is on planet Cerria    */
#define ROOM_CORBIT             56  /* This room is in Cerria's Orbit   */
#define ROOM_BEDROOM            57  /* +25% regen                       */
#define ROOM_WORKOUT            58  /* Workout Room                     */
#define ROOM_GARDEN1            59  /* 8 plant garden                   */
#define ROOM_GARDEN2            60  /* 20 plant garden                  */
#define ROOM_FERTILE1           61
#define ROOM_FERTILE2           62
#define ROOM_FISHING            63
#define ROOM_FISHFRESH          64
#define ROOM_CANREMODEL         65

#define NUM_ROOM_FLAGS          66

/* ZoneData info: Used in zone_data.zone_flags */
#define ZONE_CLOSED        0
#define ZONE_NOIMMORT        1
#define ZONE_QUEST        2
#define ZONE_DBALLS        3

#define NUM_ZONE_FLAGS 4

/* Exit info: used in room_data.dir_option.exit_info */
#define EX_ISDOOR        (1 << 0)   /* Exit is a door		*/
#define EX_CLOSED        (1 << 1)   /* The door is closed	*/
#define EX_LOCKED        (1 << 2)   /* The door is locked	*/
#define EX_PICKPROOF        (1 << 3)   /* Lock can't be picked	*/
#define EX_SECRET        (1 << 4)   /* The door is hidden        */

#define NUM_EXIT_FLAGS 5

/* Sector types: used in room_data.sector_type */
#define SECT_INSIDE          0           /* Indoors			*/
#define SECT_CITY            1           /* In a city			*/
#define SECT_FIELD           2           /* In a field		*/
#define SECT_FOREST          3           /* In a forest		*/
#define SECT_HILLS           4           /* In the hills		*/
#define SECT_MOUNTAIN        5           /* On a mountain		*/
#define SECT_WATER_SWIM      6           /* Swimmable water		*/
#define SECT_WATER_NOSWIM    7           /* Water - need a boat	*/
#define SECT_FLYING         8           /* Wheee!			*/
#define SECT_UNDERWATER         9           /* Underwater		*/
#define SECT_SHOP            10            /* Shop                      */
#define SECT_IMPORTANT       11            /* Important Rooms           */
#define SECT_DESERT          12            /* A desert                  */
#define SECT_SPACE           13            /* This is a space room      */
#define SECT_LAVA            14            /* This room always has lava */

#define NUM_ROOM_SECTORS     15


#endif //CIRCLE_INCLUDE_LEGACY_MAP
