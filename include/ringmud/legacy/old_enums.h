//
// Created by volund on 6/20/22.
//

#ifndef CIRCLE_INCLUDE_OLD_ENUMS
#define CIRCLE_INCLUDE_OLD_ENUMS

#include "legacy/songs.h"


/* Fighting Preferences */
#define PREFERENCE_THROWING     1
#define PREFERENCE_H2H          2
#define PREFERENCE_KI           3
#define PREFERENCE_WEAPON       4

#include "legacy/recipes.h"

/* Fishing Defines */
#define FISH_NOFISH             0
#define FISH_BITE               1
#define FISH_HOOKED             2
#define FISH_REELING            3


/* Shadow Dragon Defines */

#define SHADOW_DRAGON1_VNUM 81
#define SHADOW_DRAGON2_VNUM 82
#define SHADOW_DRAGON3_VNUM 83
#define SHADOW_DRAGON4_VNUM 84
#define SHADOW_DRAGON5_VNUM 85
#define SHADOW_DRAGON6_VNUM 86
#define SHADOW_DRAGON7_VNUM 87

/* room-related defines *************************************************/

#include "legacy/map.h"

/* char and mob-related defines *****************************************/

#include "legacy/classes.h"


/* Gauntlet crap */
#define GAUNTLET_ZONE  24    /* The gauntlet zone vnum */
#define GAUNTLET_START 2403  /* The waiting room at the start of the gauntlet */
#define GAUNTLET_END   2404  /* The treasure room at the end of the gauntlet  */

/* Death Types for producing corpses with depth */
#define DTYPE_NORMAL      0    /* Default Death Type */
#define DTYPE_HEAD        1    /* Lost their head    */
#define DTYPE_HALF        2    /* Blown in half      */
#define DTYPE_VAPOR       3    /* Vaporized by attack*/
#define DTYPE_PULP        4    /* Beat to a pulp     */

#include "legacy/bonus.h"

#include "legacy/appearance.h"

/* Annual Sign Phase */

#define PHASE_PURITY            0
#define PHASE_BRAVERY           1
#define PHASE_HATRED            2
#define PHASE_DOMINANCE         3
#define PHASE_GUARDIAN          4
#define PHASE_LOVE              5
#define PHASE_STRENGTH          6

/* Races */
#define RACE_UNDEFINED        -1
#define RACE_HUMAN        0
#define RACE_SAIYAN        1
#define RACE_ICER        2
#define RACE_KONATSU        3
#define RACE_NAMEK        4
#define RACE_MUTANT        5
#define RACE_KANASSAN        6
#define RACE_HALFBREED        7
#define RACE_BIO        8
#define RACE_ANDROID        9
#define RACE_DEMON        10
#define RACE_MAJIN        11
#define RACE_KAI        12
#define RACE_TRUFFLE        13
#define RACE_GOBLIN        14
#define RACE_ANIMAL        15
#define RACE_SAIBA        16
#define RACE_SERPENT        17
#define RACE_OGRE        18
#define RACE_YARDRATIAN        19
#define RACE_ARLIAN        20
#define RACE_DRAGON        21
#define RACE_MECHANICAL        22
#define RACE_FAERIE        23

#define NUM_RACES        24

#define ALIGN_SAINT              0
#define ALIGN_VALIANT            1
#define ALIGN_HERO               2
#define ALIGN_DOGOOD             3
#define ALIGN_NEUTRAL            4
#define ALIGN_CROOK              5
#define ALIGN_VILLAIN            6
#define ALIGN_TERRIBLE           7
#define ALIGN_HORRIBLE           8

#define NUM_ALIGNS               9

/* Taken from the SRD under OGL, see ../doc/srd.txt for information */
#define SIZE_UNDEFINED    (-1)
#define SIZE_FINE    0
#define SIZE_DIMINUTIVE    1
#define SIZE_TINY    2
#define SIZE_SMALL    3
#define SIZE_MEDIUM    4
#define SIZE_LARGE    5
#define SIZE_HUGE    6
#define SIZE_GARGANTUAN    7
#define SIZE_COLOSSAL    8

#define NUM_SIZES         9

#define WIELD_NONE        0
#define WIELD_LIGHT       1
#define WIELD_ONEHAND     2
#define WIELD_TWOHAND     3

/* Number of weapon types */
#define MAX_WEAPON_TYPES            26

/* Critical hit types */
#define CRIT_X2        0
#define CRIT_X3        1
#define CRIT_X4        2

#define MAX_CRIT_TYPE    CRIT_X4
#define NUM_CRIT_TYPES 3

/* Sex */
#define SEX_NEUTRAL   0
#define SEX_MALE      1
#define SEX_FEMALE    2

#define NUM_SEX       3

/* Positions */
#define POS_DEAD       0    /* dead			*/
#define POS_MORTALLYW  1    /* mortally wounded	*/
#define POS_INCAP      2    /* incapacitated	*/
#define POS_STUNNED    3    /* stunned		*/
#define POS_SLEEPING   4    /* sleeping		*/
#define POS_RESTING    5    /* resting		*/
#define POS_SITTING    6    /* sitting		*/
#define POS_FIGHTING   7    /* fighting		*/
#define POS_STANDING   8    /* standing		*/

#define NUM_POSITIONS  9

/* AUCTIONING STATES */
#define AUC_NULL_STATE        0   /* not doing anything */
#define AUC_OFFERING        1   /* object has been offfered */
#define AUC_GOING_ONCE        2    /* object is going once! */
#define AUC_GOING_TWICE        3    /* object is going twice! */
#define AUC_LAST_CALL        4    /* last call for the object! */
#define AUC_SOLD        5
/* AUCTION CANCEL STATES */
#define AUC_NORMAL_CANCEL    6    /* normal cancellation of auction */
#define AUC_QUIT_CANCEL        7    /* auction canclled because player quit */
#define AUC_WIZ_CANCEL        8    /* auction cancelled by a god */
/* OTHER JUNK */
#define AUC_STAT        9
#define AUC_BID            10

#include "legacy/player_flags.h"

#include "legacy/mob_flags.h"

#include "legacy/preference.h"

/* Player autoexit levels: used as an index to exitlevels           */
#define EXIT_OFF        0       /* Autoexit off                     */
#define EXIT_NORMAL     1       /* Brief display (stock behaviour)  */
#define EXIT_NA         2       /* Not implemented - do not use     */
#define EXIT_COMPLETE   3       /* Full display                     */

#define _exitlevel(ch) (ch->isPlayer() ? (PRF_FLAGGED((ch),PRF_AUTOEXIT) ? 1 : 0 ) + (PRF_FLAGGED((ch),PRF_FULL_EXIT) ? 2 : 0 ) : 0 )
#define EXIT_LEV(ch) (_exitlevel(ch))

#include "legacy/affects.h"

#include "legacy/conn_state.h"


/* Colors that the player can define */
#define COLOR_NORMAL            0
#define COLOR_ROOMNAME            1
#define COLOR_ROOMOBJS            2
#define COLOR_ROOMPEOPLE        3
#define COLOR_HITYOU            4
#define COLOR_YOUHIT            5
#define COLOR_OTHERHIT            6
#define COLOR_CRITICAL            7
#define COLOR_HOLLER            8
#define COLOR_SHOUT            9
#define COLOR_GOSSIP            10
#define COLOR_AUCTION            11
#define COLOR_CONGRAT            12
#define COLOR_TELL            13
#define COLOR_YOUSAY            14
#define COLOR_ROOMSAY            15

#define NUM_COLOR            16

#include "legacy/wear.h"

#include "legacy/magic.h"

/* Combat feats that apply to a specific weapon type */
#define CFEAT_IMPROVED_CRITICAL            0
#define CFEAT_WEAPON_FINESSE            1
#define CFEAT_WEAPON_FOCUS            2
#define CFEAT_WEAPON_SPECIALIZATION        3
#define CFEAT_GREATER_WEAPON_FOCUS        4
#define CFEAT_GREATER_WEAPON_SPECIALIZATION    5

#define CFEAT_MAX                5

/* Spell feats that apply to a specific school of spells */
#define CFEAT_SPELL_FOCUS            0
#define CFEAT_GREATER_SPELL_FOCUS        1

#define SFEAT_MAX                1

/* object-related defines ********************************************/

#include "legacy/item.h"

#include "legacy/apply.h"

/* Container flags - value[1] */
#define CONT_CLOSEABLE      (1 << 0)    /* Container can be closed	*/
#define CONT_PICKPROOF      (1 << 1)    /* Container is pickproof	*/
#define CONT_CLOSED         (1 << 2)    /* Container is closed		*/
#define CONT_LOCKED         (1 << 3)    /* Container is locked		*/

#define NUM_CONT_FLAGS 4

#include "legacy/material.h"

/* other miscellaneous defines *******************************************/


/* Player conditions */
#define DRUNK        0
#define HUNGER       1
#define THIRST       2


/* Sun state for weather_data */
#define SUN_DARK    0
#define SUN_RISE    1
#define SUN_LIGHT    2
#define SUN_SET        3


/* Sky conditions for weather_data */
#define SKY_CLOUDLESS    0
#define SKY_CLOUDY    1
#define SKY_RAINING    2
#define SKY_LIGHTNING    3


/* Rent codes */
#define RENT_UNDEF      0
#define RENT_CRASH      1
#define RENT_RENTED     2
#define RENT_CRYO       3
#define RENT_FORCED     4
#define RENT_TIMEDOUT   5


/* for the 128bits */
#define RF_ARRAY_MAX    4
#define PM_ARRAY_MAX    4
#define PR_ARRAY_MAX    4
#define AF_ARRAY_MAX    4
#define TW_ARRAY_MAX    4
#define EF_ARRAY_MAX    4
#define AD_ARRAY_MAX    4
#define FT_ARRAY_MAX    4
#define ZF_ARRAY_MAX    4


/* History */
#define HIST_ALL       0
#define HIST_SAY       1
#define HIST_GOSSIP    2
#define HIST_WIZNET    3
#define HIST_TELL      4
#define HIST_SHOUT     5
#define HIST_GRATS     6
#define HIST_HOLLER    7
#define HIST_AUCTION   8
#define HIST_SNET      9

#define NUM_HIST      10

/* other #defined constants **********************************************/

#include "legacy/admin.h"

#define NUM_OF_DIRS    12    /* number of directions in a room (nsewud) */

/*
 * OPT_USEC determines how many commands will be processed by the MUD per
 * second and how frequently it does socket I/O.  A low setting will cause
 * actions to be executed more frequently but will increase overhead due to
 * more cycling to check.  A high setting (e.g. 1 Hz) may upset your players
 * as actions (such as large speedwalking chains) take longer to be executed.
 * You shouldn't need to adjust this.
 */
#define OPT_USEC    100000        /* 10 passes per second */
#define PASSES_PER_SEC    (1000000 / OPT_USEC)
#define RL_SEC        * PASSES_PER_SEC
#define CD_TICK         * PASSES_PER_SEC

#define PULSE_ZONE    (CONFIG_PULSE_ZONE RL_SEC)
#define PULSE_MOBILE    (CONFIG_PULSE_MOBILE RL_SEC)
#define PULSE_VIOLENCE  (CONFIG_PULSE_VIOLENCE RL_SEC)
#define PULSE_AUCTION    (15 RL_SEC)
#define PULSE_AUTOSAVE    (CONFIG_PULSE_AUTOSAVE RL_SEC)
#define PULSE_IDLEPWD    (CONFIG_PULSE_IDLEPWD RL_SEC)
#define PULSE_SANITY    (CONFIG_PULSE_SANITY RL_SEC)
#define PULSE_USAGE    (CONFIG_PULSE_SANITY * 60 RL_SEC)   /* 5 mins */
#define PULSE_TIMESAVE    (CONFIG_PULSE_TIMESAVE * 300 RL_SEC) /* should be >= SECS_PER_MUD_HOUR */
#define PULSE_CURRENT    (CONFIG_PULSE_CURRENT RL_SEC)
#define PULSE_1SEC      (1 RL_SEC)
#define PULSE_2SEC      (2 RL_SEC)
#define PULSE_3SEC      (3 RL_SEC)
#define PULSE_4SEC      (4 RL_SEC)
#define PULSE_5SEC      (5 RL_SEC)
#define PULSE_6SEC      (6 RL_SEC)
#define PULSE_7SEC      (7 RL_SEC)

/* Cool Down Ticks */
#define PULSE_CD1       (1 CD_TICK)
#define PULSE_CD2       (2 CD_TICK)
#define PULSE_CD3       (3 CD_TICK)
#define PULSE_CD4       (4 CD_TICK) /* This and the 3 above are for safety */
#define PULSE_CD5       (5 CD_TICK) /* Punch */
#define PULSE_CD6       (6 CD_TICK)
#define PULSE_CD7       (7 CD_TICK)
#define PULSE_CD8       (8 CD_TICK)
#define PULSE_CD9       (9 CD_TICK)
#define PULSE_CD10      (10 CD_TICK)
#define PULSE_CD11      (11 CD_TICK)
#define PULSE_CD12      (12 CD_TICK)
/* End CD Ticks    */


/* Variables for the output buffering system */
#define MAX_SOCK_BUF            (96 * 1024) /* Size of kernel's sock buf   */
#define MAX_PROMPT_LENGTH       1024          /* Max length of prompt        */
#define GARBAGE_SPACE        512          /* Space for **OVERFLOW** etc  */
#define SMALL_BUFSIZE        6020        /* Static output buffer size   */
/* Max amount of output that can be buffered */
#define LARGE_BUFSIZE       (MAX_SOCK_BUF - GARBAGE_SPACE - MAX_PROMPT_LENGTH)

#define HISTORY_SIZE        5    /* Keep last 5 commands. */
#define MAX_STRING_LENGTH    64936
#define MAX_INPUT_LENGTH    2048    /* Max length per *line* of
input */
#define MAX_RAW_INPUT_LENGTH    4096    /* Max size of *raw* input */
#define MAX_MESSAGES        100
#define MAX_NAME_LENGTH        20
#define MAX_PWD_LENGTH        30
#define MAX_TITLE_LENGTH    120
#define HOST_LENGTH        40
#define EXDSCR_LENGTH        16384
#define MAX_TONGUE        3
#define MAX_SKILLS        200
#define MAX_AFFECT        32
#define MAX_OBJ_AFFECT        6
#define MAX_NOTE_LENGTH        6000    /* arbitrary */
#define SKILL_TABLE_SIZE    1000
#define SPELLBOOK_SIZE        50
#define MAX_FEATS            750
#define MAX_HELP_KEYWORDS       256
#define MAX_HELP_ENTRY          MAX_STRING_LENGTH
#define NUM_FEATS_DEFINED       252
#define MAX_ARMOR_TYPES         5
#define NUM_CONFIG_SECTIONS     7
#define NUM_CREATION_METHODS    5
#define NUM_ATTACK_TYPES        15
#define NUM_MTRIG_TYPES         20
#define NUM_OTRIG_TYPES         20
#define NUM_WTRIG_TYPES         20
#define NUM_TRADERS             78
#define NUM_SHOP_FLAGS          3
#define NUM_DOOR_CMD            5
#define MAX_ASSM                11
#define NUM_FULLNESS        5
#define NUM_WEEK_DAYS        7
#define NUM_MONTHS        12
#define NUM_CONDITIONS        3
#define NUM_WIELD_NAMES        4

/* define the largest set of commands for a trigger */
#define MAX_CMD_LENGTH          16384 /* 16k should be plenty and then some */


/*
 * A MAX_PWD_LENGTH of 10 will cause BSD-derived systems with MD5 passwords
 * and GNU libc 2 passwords to be truncated.  On BSD this will enable anyone
 * with a name longer than 5 puppet to log in with any password.  If you
 * have such a system, it is suggested you change the limit to 20.
 *
 * Please note that this will erase your player files.  If you are not
 * prepared to do so, simply erase these lines but heed the above warning.
 */





#endif //CIRCLE_INCLUDE_OLD_ENUMS
