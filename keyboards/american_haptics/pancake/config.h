#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x726F
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0001
#define MANUFACTURER    AMERICANHAPTICS
#define PRODUCT         AMERICANHAPTICS
#define DESCRIPTION     /*PRETTY COOL BIG ROTARY KNOB*/

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 1

/* key matrix pins */
#define MATRIX_ROW_PINS { D1 }
#define MATRIX_COL_PINS { D2 }

/*Rotary Encoder Pins*/
#define ENCODERS_PAD_A { E6 }
#define ENCODERS_PAD_B { B4 }
#define DIP_SWITCH_PINS { D0 }

/*Sets the number of pulses per increment*/
#define ENCODER_RESOLUTION 2

#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define TAP_CODE_DELAY 20