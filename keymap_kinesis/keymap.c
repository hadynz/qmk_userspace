#include QMK_KEYBOARD_H

// Tap Dance Declarations
enum {
 CT_CLN = 0,
 TD_BSPC,
};

// Custom Keycodes
#define ____ KC_NO
#define _______ KC_NO

#define HOME_A LCTL_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LGUI_T(KC_S)
#define HOME_T LSFT_T(KC_T)

#define HOME_N RSFT_T(KC_N)
#define HOME_E RGUI_T(KC_E)
#define HOME_I RALT_T(KC_I)
#define HOME_O RCTL_T(KC_O)

#define HYP_ESC HYPR_T(KC_ESC)

#define THMB_L1 LT(_NAV, KC_BSPC)
#define THMB_L2 LT(_MOUSE, KC_DEL)
#define THMB_LA KC_NO
#define THMB_LB KC_NO
#define THMB_LC KC_NO
#define THMB_LD TG(_MOUSE)

#define THMB_R1 LSFT_T(KC_SPC)
#define THMB_R2 KC_ENT
#define THMB_RA KC_NO
#define THMB_RB KC_NO
#define THMB_RC KC_NO
#define THMB_RD QK_LEAD

// Layers
enum layer_names {
  _BASE_COLEMAK_DH = 0,
  _NAV,
  _MOUSE
};


// Combo Keycodes
const uint16_t PROGMEM undo_combo_keys[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM cut_combo_keys[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM copy_combo_keys[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM paste_combo_keys[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM esc_left_combo_keys[] = {HOME_S, HOME_T, COMBO_END};
const uint16_t PROGMEM esc_right_combo_keys[] = {HOME_N, HOME_E, COMBO_END};
const uint16_t PROGMEM delete_word_combo_keys[] = {THMB_L1, THMB_R1, COMBO_END};

combo_t key_combos[] = {
  COMBO(undo_combo_keys, LGUI(KC_Z)),
  COMBO(cut_combo_keys, LGUI(KC_X)),
  COMBO(copy_combo_keys, LGUI(KC_C)),
  COMBO(paste_combo_keys, LGUI(KC_V)),
  COMBO(esc_left_combo_keys, KC_ESC),
  COMBO(esc_right_combo_keys, KC_ESC),
  COMBO(delete_word_combo_keys, LALT(KC_BSPC)),
};

// Keyboard 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE_COLEMAK_DH] = LAYOUT(
    KC_CAPS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SCRL, KC_PAUS, RGB_TOG, TG(_BASE_COLEMAK_DH),
    
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                 KC_J,    KC_L,    KC_U,    KC_Y,    TD(CT_CLN),  KC_BSLS,
    HYP_ESC, HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,                 KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,  KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                 KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
             KC_GRV,  KC_BSLS, KC_LEFT, KC_RGHT,                                KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,
    
                                        THMB_LA, THMB_LB,              THMB_LA, THMB_LB,
                                                 THMB_LC,              THMB_LC,
                               THMB_L1, THMB_L2, THMB_LD,              THMB_LD, THMB_R2, THMB_R1
  ),
  [_NAV] = LAYOUT(
    ____, ____, ____, ____, ____, ____, ____, ____, ____,              ____, ____, ____, ____, ____, ____, ____, ____, ____,
    _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,              KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, _______,
    _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______,              KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______,              KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
             _______, _______, _______, _______,                                _______, _______, _______, _______,
    
                                        KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS,
                                                 KC_TRNS,              KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS, KC_BSPC
  ),
  [_MOUSE] = LAYOUT(
    ____, ____, ____, ____, ____, ____, ____, ____, ____,              ____, ____, ____, ____, ____, ____, ____, ____, ____,
    _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______,
    _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______,              KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
    _______, _______, _______, _______, _______, _______,              KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
             _______, _______, _______, _______,                                _______, _______, _______, _______,
    
                                        KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS,
                                                 KC_TRNS,              KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS, KC_BTN2, KC_BTN1
  )
};

// Leader key configuration
void leader_end_user(void) {
  bool did_leader_succeed = false;

  if (leader_sequence_one_key(KC_F)) {
    SEND_STRING("Leader F");
    did_leader_succeed = true;
  } else if (leader_sequence_one_key(KC_D)) {
    SEND_STRING("Leader D");
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

void dance_cln_finished (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RSFT);
    register_code (KC_SCLN);
  } else {
    register_code (KC_SCLN);
  }
}

void dance_cln_reset (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RSFT);
    unregister_code (KC_SCLN);
  } else {
    unregister_code (KC_SCLN);
  }
}

// Backspace tap dance - backspace on tap, alt+backspace on hold (delete word)
void backspace_finished (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1 && !state->interrupted) {
    register_code (KC_BSPC);
  } else {
    register_code (KC_LALT);
    register_code (KC_BSPC);
  }
}

void backspace_reset (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1 && !state->interrupted) {
    unregister_code (KC_BSPC);
  } else {
    unregister_code (KC_LALT);
    unregister_code (KC_BSPC);
  }
}

// All tap dance functions would go here. Only showing this one.
tap_dance_action_t tap_dance_actions[] = {
 [CT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset),
 [TD_BSPC] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, backspace_finished, backspace_reset)
};
