#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

// place overrides here
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 300

#define RGBW

/* ws2812 RGB LED */
#define RGB_DI_PIN B7
#define RGBLED_NUM 30
#define RGBLIGHT_ANIMATIONS

#endif
