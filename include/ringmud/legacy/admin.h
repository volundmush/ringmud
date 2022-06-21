//
// Created by volund on 6/20/22.
//

#ifndef RINGMUD_INCLUDE_RINGMUD_LEGACY_ADMIN
#define RINGMUD_INCLUDE_RINGMUD_LEGACY_ADMIN

/*
 * ADMLVL_IMPL should always be the HIGHEST possible admin level, and
 * ADMLVL_IMMORT should always be the LOWEST immortal level.
 */
#define ADMLVL_NONE        0
#define ADMLVL_IMMORT        1
#define ADMLVL_BUILDER          2
#define ADMLVL_GOD        3
#define ADMLVL_VICE             4
#define ADMLVL_GRGOD        5
#define ADMLVL_IMPL        6

/* First puppet level that forces epic levels */
#define LVL_EPICSTART        101

/*
 * ADM flags - define admin privs for chars
 */
#define ADM_TELLALL        0    /* Can use 'tell all' to broadcast GOD */
#define ADM_SEEINV        1    /* Sees other chars inventory IMM */
#define ADM_SEESECRET        2    /* Sees secret doors IMM */
#define ADM_KNOWWEATHER        3    /* Knows details of weather GOD */
#define ADM_FULLWHERE        4    /* Full output of 'where' command IMM */
#define ADM_MONEY        5    /* Char has a bottomless wallet GOD */
#define ADM_EATANYTHING    6    /* Char can eat anything GOD */
#define ADM_NOPOISON        7    /* Char can't be poisoned IMM */
#define ADM_WALKANYWHERE    8    /* Char has unrestricted walking IMM */
#define ADM_NOKEYS        9    /* Char needs no keys for locks GOD */
#define ADM_INSTANTKILL        10    /* "kill" command is instant IMPL */
#define ADM_NOSTEAL        11    /* Char cannot be stolen from IMM */
#define ADM_TRANSALL        12    /* Can use 'trans all' GRGOD */
#define ADM_SWITCHMORTAL    13    /* Can 'switch' to a mortal PC body IMPL */
#define ADM_FORCEMASS        14    /* Can force room_table or all GRGOD */
#define ADM_ALLHOUSES        15    /* Can enter any house GRGOD */
#define ADM_NODAMAGE        16    /* Cannot be damaged IMM */
#define ADM_ALLSHOPS        17    /* Can use all shops GOD */
#define ADM_CEDIT        18    /* Can use cedit IMPL */

#define NUM_ADMFLAGS            19

/* Level of the 'freeze' command */
#define ADMLVL_FREEZE    ADMLVL_GRGOD

#endif //RINGMUD_INCLUDE_RINGMUD_LEGACY_ADMIN
