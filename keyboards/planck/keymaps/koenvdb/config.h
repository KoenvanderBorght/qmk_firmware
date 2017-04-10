

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

/* Tapping settings */
#define TAPPING_TERM 150

/* Mouse settings */
#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 5
#define MOUSEKEY_MAX_SPEED 5
#define MOUSEKEY_WHEEL_DELAY 0

#ifdef SUBPROJECT_rev3
    #include "rev3/config.h"
#endif
#ifdef SUBPROJECT_rev4
    #include "rev4/config.h"
#endif

#endif
