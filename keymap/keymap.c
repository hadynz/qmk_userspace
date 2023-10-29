#include QMK_KEYBOARD_H

// Keycodes
#define ____ KC_NO

#define HOME_A LT(_MOUSE, KC_A)
#define HOME_R LCTL_T(KC_R)
#define HOME_S LALT_T(KC_S)
#define HOME_T LGUI_T(KC_T)
#define HOME_N RGUI_T(KC_N)
#define HOME_E RALT_T(KC_E)
#define HOME_I RCTL_T(KC_I)
#define HOME_O LT(_MOUSE, KC_O)

#define THMB_L1 LSFT_T(KC_BSPC)
#define THMB_L2 LT(_VIM, KC_DEL)
#define THMB_LA LCAG(KC_F)
#define THMB_LB HYPR(KC_UP)
#define THMB_LC HYPR(KC_LEFT)
#define THMB_LD TG(_MOUSE)

#define THMB_R1 LSFT_T(KC_SPC)
#define THMB_R2 KC_ENT

// Layers
enum layer_names {
  _BASE_COLEMAK_DH = 0,
  _VIM,
  _MOUSE
};

// Combo Keycodes
const uint16_t PROGMEM undo_combo_keys[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM cut_combo_keys[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM copy_combo_keys[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM paste_combo_keys[] = {KC_D, KC_V, COMBO_END};

combo_t key_combos[] = {
  COMBO(undo_combo_keys, LGUI(KC_Z)),
  COMBO(cut_combo_keys, LGUI(KC_X)),
  COMBO(copy_combo_keys, LGUI(KC_C)),
  COMBO(paste_combo_keys, LGUI(KC_V)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE_COLEMAK_DH] = LAYOUT(
    KC_CAPS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SCRL, KC_PAUS, RGB_TOG, TG(_BASE_COLEMAK_DH),
    
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                 KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
    KC_ESC,  HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,                 KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,  KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                 KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
             KC_GRV,  KC_BSLS, KC_LEFT, KC_RGHT,                                KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,
    
                                        THMB_LA, THMB_LB,              HYPR(KC_DOWN), LCAG(KC_TAB),
                                                 THMB_LC,              HYPR(KC_RGHT),
                               THMB_L1, THMB_L2, THMB_LD,              QK_LEAD, THMB_R2, THMB_R1
  ),
  [_VIM] = LAYOUT(
    ____, ____, ____, ____, ____, ____, ____, ____, ____,              ____, ____, ____, ____, ____, ____, ____, ____, ____,
    
    ____,    ____,    ____,    ____,    ____,    ____,                 ____,    ____,    ____,    ____,    ____,    ____,
    ____,    ____,    ____,    ____,    ____,    ____,                 ____,    ____,    ____,    ____,    ____,    ____,
    ____,    ____,    ____,    ____,    ____,    ____,                 ____,    KC_H,    KC_J,    KC_K,    KC_L,    ____,
    ____,    ____,    ____,    ____,    ____,    ____,                 ____,    ____,    ____,    ____,    ____,    ____,
             ____,    ____,    ____,    ____,                                   ____,    ____,    ____,    ____,
    
                                        ____,    ____,                 ____,    ____,
                                                 ____,                 ____,
                               ____,    ____,    ____,                 ____,    ____,    ____
  ),
  [_MOUSE] = LAYOUT(
    ____, ____, ____, ____, ____, ____, ____, ____, ____,              QK_BOOT, ____, ____, ____, KC_PSCR, ____, ____, ____, QK_BOOT,
    ____, LCTL(KC_DOWN), LCTL(KC_UP), KC_MPRV, KC_MPLY, KC_MNXT,       KC_MUTE, KC_VOLD, KC_VOLU, KC_F11, RGUI(KC_0), ____,
    LGUI(KC_LBRC), LGUI(KC_Q), LGUI(KC_W), KC_WH_U, LGUI(KC_P),        ____, ____, KC_RGUI, KC_MS_U, ____, ____, RGUI(KC_RBRC),
    KC_ESC, LGUI(KC_A), KC_WH_L, KC_WH_D, KC_WH_R, LGUI(KC_D),         ____, KC_MS_L, KC_MS_D, KC_MS_R, RGUI(KC_O), ____,
    KC_LSFT, LGUI(KC_Z), KC_ACL0, LGUI(KC_C), LGUI(KC_V), LGUI(KC_B), RGUI(KC_K), RGUI(KC_M), ____, ____, ____, KC_RSFT,
    KC_SPC, LGUI(KC_GRV), KC_LEFT, KC_RGHT, KC_UP, KC_DOWN, KC_MINS, KC_EQL,
    LCAG(KC_LEFT), LCAG(KC_TAB), KC_BTN1, KC_BTN2,
    MEH(KC_LEFT), MEH(KC_RGHT),
    KC_BTN1, KC_TAB, KC_TRNS, ____, KC_ENT, KC_BTN2
  )
};

// Leader key configuration
void leader_end_user(void) {
  bool did_leader_succeed = false;

  if (leader_sequence_one_key(KC_F)) {
      SEND_STRING("Leader F");
      did_leader_succeed = true;
  if (leader_sequence_one_key(KC_D)) {
      SEND_STRING("Leader D");
      did_leader_succeed = true;
  } else if (leader_sequence_two_keys(KC_D, KC_D)) {
      SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
      did_leader_succeed = true;
  } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
      SEND_STRING("https://start.duckduckgo.com\n");
      did_leader_succeed = true;
  } else if (leader_sequence_two_keys(KC_A, KC_S)) {
      tap_code16(LGUI(KC_S));
      did_leader_succeed = true;
  }

  if (did_leader_succeed) {
    SEND_STRING("s");
  } else {
    SEND_STRING("f");
  }
}
