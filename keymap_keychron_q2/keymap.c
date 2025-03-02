#include QMK_KEYBOARD_H

// Tap Dance declarations
enum {
  TD_F9_F10 = 0,
  TD_F11_F12,
  TD_PLAY_NEXT,
  TD_SHIFT_F5,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
  [TD_SHIFT_F5] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_F5), // Tap/hold for Shift, twice for F5
  [TD_F9_F10] = ACTION_TAP_DANCE_DOUBLE(KC_F9, KC_F10), // Tap once for F9, twice for F10
  [TD_F11_F12] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_F12), // Tap once for F11, twice for F12
  [TD_PLAY_NEXT] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT), // Tap once for media play, twice for media next
};

// Custom Keycode aliases
#define MEH_TAB MEH_T(KC_TAB)
#define HYP_ESC HYPR_T(KC_ESC)
#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define C_ZOOM1 TD(TD_F9_F10) // Zoom control -- Tap once for F9, twice for F10
#define C_ZOOM2 TD(TD_F11_F12) // Zoom control -- Tap once for F11, twice for F12
#define C_MEDIA TD(TD_PLAY_NEXT) // Media control -- Tap once for media play, twice for media next
#define LAYER_C MO(_FN2) // Layer switch -- Momentarily turn on _FN2 layer
#define LAYER_F MO(FUNC_BASE) // Layer switch -- Momentarily turn on FUNC_BASE layer
#define L_SHIFT TD(TD_SHIFT_F5) // Handy Func key -- Tap/hold for Shift, twice for F5
#define L_CTRL  LCTL_T(KC_F6) // Hold for Ctrl, Tap for F6
#define L_ALT   LALT_T(KC_F7) // Hold for Alt/Option, Tap for F7
#define L_GUI   KC_LCMD

// Layers declarations
enum layers{
  MAC_BASE,
  COLEMAK_BASE,
  _FN2,
  FUNC_BASE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MAC_BASE] = LAYOUT_ansi_67(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          C_MEDIA,
    MEH_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          C_ZOOM1,
    HYP_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           C_ZOOM2,
    L_SHIFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,
    L_CTRL,  L_ALT,   L_GUI,                              KC_SPC,                             KC_RCMD, LAYER_F, KC_ROPT, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [COLEMAK_BASE] = LAYOUT_ansi_67(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,          C_MEDIA,
    MEH_TAB, KC_Q,    KC_W,    KC_F,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_O,    KC_SCLN, KC_LBRC,  KC_RBRC, KC_BSLS,          KC_DEL,
    HYP_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,           KC_ENT,           KC_HOME,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,           KC_RSFT, KC_UP,
    KC_LCTL, KC_LOPT, KC_LCMD,                            KC_SPC,                             KC_RCMD, LAYER_C, LAYER_F, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_FN2] = LAYOUT_ansi_67(
    KC_GRV,  KC_BRID, KC_BRIU, KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
    RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______, _______,  _______,  _______,          _______,
    _______, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______, _______,            _______,          _______,
    _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,            _______, _______,
    _______, _______, _______,                            _______,                            _______, _______,  _______,  _______, _______, _______
  ),

  [FUNC_BASE] = LAYOUT_ansi_67(
    KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,   _______,          _______,
    RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______, _______,  _______,  _______,          _______,
    _______, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______, _______,            _______,          _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______,
    _______, _______, _______,                            _______,                            _______, _______,  _______,  _______, _______, _______
  )
};

#if defined(COMBO_ENABLE)
const uint16_t PROGMEM qk_boot_combo[] = {KC_F11, KC_F12, COMBO_END};
const uint16_t PROGMEM cmd_q_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM cmd_w_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM cmd_l_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM cmd_f_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM cmd_lbracket_combo[] = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM cmd_rbracket_combo[] = {KC_RBRC, KC_BSLS, COMBO_END};
const uint16_t PROGMEM undo_combo_keys[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM cut_combo_keys[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM copy_combo_keys[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM paste_combo_keys[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM lock_mac_keys[] = {MEH_TAB, KC_Q, COMBO_END};
const uint16_t PROGMEM left_alt_combo[] = {KC_A, KC_S, COMBO_END};

combo_t key_combos[] = {
  COMBO(qk_boot_combo, QK_BOOT),
  COMBO(cmd_q_combo, LGUI(KC_Q)),
  COMBO(cmd_w_combo, LGUI(KC_W)),
  COMBO(cmd_l_combo, LGUI(KC_L)),
  COMBO(cmd_f_combo, LGUI(KC_F)),
  COMBO(cmd_lbracket_combo, LGUI(KC_LBRC)),
  COMBO(cmd_rbracket_combo, LGUI(KC_RBRC)),
  COMBO(undo_combo_keys, LGUI(KC_Z)),
  COMBO(cut_combo_keys, LGUI(KC_X)),
  COMBO(copy_combo_keys, LGUI(KC_C)),
  COMBO(paste_combo_keys, LGUI(KC_V)),
  COMBO(lock_mac_keys, LGUI(LCTL(KC_Q))),
  COMBO(left_alt_combo, KC_LOPT),
};
#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [MAC_BASE]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [COLEMAK_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [_FN2]         = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
  [FUNC_BASE]    = { ENCODER_CCW_CW(_______, _______) },
};
#endif

#if defined(TAPPING_TERM_PER_KEY)
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case C_MEDIA:
      return TAPPING_TERM + 500; // The rotary media button is very slow to press, so we need to increase the tapping term 

    case L_SHIFT:
      return TAPPING_TERM + 100; // My double shift tap is generally slow, so I need to increase the tapping term

    case L_CTRL:
    case L_ALT:
      return 90; // Frequently used modifier. Use a very short tapping term

    default:
      return TAPPING_TERM;
  }
}
#endif
