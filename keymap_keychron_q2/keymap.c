#include QMK_KEYBOARD_H

// Tap Dance declarations
enum {
  TD_F9_F10 = 0,
  TD_F11_F12,
  TD_PLAY_NEXT,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
  [TD_F9_F10] = ACTION_TAP_DANCE_DOUBLE(KC_F9, KC_F10), // Tap once for F9, twice for F10
  [TD_F11_F12] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_F12), // Tap once for F11, twice for F12
  [TD_PLAY_NEXT] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT), // Tap once for media play, twice for media next
};

// Custom Keycodes
#define MEH_TAB MEH_T(KC_TAB)
#define HYP_ESC HYPR_T(KC_ESC)
#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define C_ZOOM1 TD(TD_F9_F10)
#define C_ZOOM2 TD(TD_F11_F12)
#define C_MEDIA TD(TD_PLAY_NEXT)

// Layers declarations
enum layers{
  MAC_BASE,
  COLEMAK_BASE,
  _FN1,
  _FN2,
  _FN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MAC_BASE] = LAYOUT_ansi_67(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,          C_MEDIA,
    MEH_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,          C_ZOOM1,
    HYP_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,           C_ZOOM2,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT, KC_UP,
    KC_LCTL, KC_LOPT, KC_LCMD,                            KC_SPC,                             KC_RCMD, MO(_FN1), MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [COLEMAK_BASE] = LAYOUT_ansi_67(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,          C_MEDIA,
    MEH_TAB, KC_Q,    KC_W,    KC_F,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_O,    KC_SCLN, KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
    HYP_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,            KC_ENT,           KC_HOME,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT, KC_UP,
    KC_LCTL, KC_LOPT, KC_LCMD,                            KC_SPC,                             KC_RCMD, MO(_FN2), MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_FN1] = LAYOUT_ansi_67(
    KC_GRV,  KC_BRID, KC_BRIU, _______, _______, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
    RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______, _______,  _______,  _______,          _______,
    _______, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______, _______,            _______,          _______,
    _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,            _______, _______,
    _______, _______, _______,                            _______,                            _______, _______,  _______,  _______, _______, _______
  ),

  [_FN2] = LAYOUT_ansi_67(
    KC_GRV,  KC_BRID, KC_BRIU, KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
    RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______, _______,  _______,  _______,          _______,
    _______, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______, _______,            _______,          _______,
    _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,            _______, _______,
    _______, _______, _______,                            _______,                            _______, _______,  _______,  _______, _______, _______
  ),

  [_FN3] = LAYOUT_ansi_67(
    KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   QK_BOOT,  _______,          _______,
    RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______, _______,  _______,  _______,          _______,
    _______, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______, _______,            _______,          _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______,
    _______, _______, _______,                            _______,                            _______, _______,  _______,  _______, _______, _______
  )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [MAC_BASE]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [COLEMAK_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [_FN1]         = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
  [_FN2]         = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
  [_FN3]         = { ENCODER_CCW_CW(_______, _______) },
};
#endif

#if defined(TAPPING_TERM_PER_KEY)
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case C_MEDIA:
      return TAPPING_TERM + 500;
    default:
      return TAPPING_TERM;
  }
}
#endif
