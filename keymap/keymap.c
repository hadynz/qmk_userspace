#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_CAPS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SCRL, KC_PAUS, RGB_TOG, TG(1), KC_SLEP, LCTL(KC_DOWN), LCTL(KC_UP), KC_MRWD, KC_MPLY, KC_MFFD, KC_MUTE, KC_VOLD, KC_VOLU, KC_F11, RGUI(KC_0), KC_EJCT, KC_LBRC, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_RBRC, KC_ESC, LT(4,KC_A), LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_T), KC_D, KC_H, RGUI_T(KC_N), RALT_T(KC_E), RCTL_T(KC_I), LT(4,KC_O), KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_BSLS, KC_GRV, KC_LEFT, KC_RGHT, KC_UP, KC_DOWN, KC_MINS, KC_EQL, LCAG(KC_F), HYPR(KC_UP), HYPR(KC_DOWN), LCAG(KC_TAB), HYPR(KC_LEFT), HYPR(KC_RGHT), LSFT_T(KC_BSPC), LT(2,KC_TAB), TG(4), RGB_MOD, LT(3,KC_ENT), LSFT_T(KC_SPC)),
	[1] = LAYOUT(KC_CAPS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SCRL, KC_PAUS, KC_CALC, KC_TRNS, LCA(KC_DEL), RGB_TOG, LGUI(KC_TAB), KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, RGB_RMOD, RGB_MOD, RGUI(KC_L), KC_LBRC, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_RBRC, KC_ESC, LT(4,KC_A), LGUI_T(KC_R), LALT_T(KC_S), LCTL_T(KC_T), KC_D, KC_H, RCTL_T(KC_N), RALT_T(KC_E), RGUI_T(KC_I), LT(4,KC_O), KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_BSLS, KC_GRV, KC_LEFT, KC_RGHT, KC_UP, KC_DOWN, KC_MINS, KC_EQL, LGUI(KC_ENT), LGUI(KC_LEFT), RGUI(KC_RGHT), RGUI(KC_DEL), LCA(KC_HOME), LCA(KC_PGUP), LSFT_T(KC_BSPC), LT(2,KC_TAB), LCA(KC_END), LCA(KC_PGDN), LT(3,KC_ENT), RSFT_T(KC_SPC)),
	[2] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1, LCTL_T(KC_2), LALT_T(KC_3), LGUI_T(KC_4), KC_NO, KC_NO, RGUI_T(KC_7), RALT_T(KC_8), RCTL_T(KC_9), KC_0, KC_NO, KC_NO, KC_NO, KC_PAST, KC_NO, KC_5, KC_NO, KC_NO, KC_6, KC_COMM, KC_PDOT, KC_PSLS, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_RGHT, KC_UP, KC_DOWN, KC_PMNS, KC_PPLS, KC_NO, KC_NO, MEH(KC_RGHT), LCAG(KC_RGHT), KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_ENT, RSFT_T(KC_SPC)),
	[3] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LGUI(KC_ESC), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_NO, KC_NO, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PERC, KC_NO, KC_NO, KC_CIRC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LCAG(KC_LEFT), MEH(KC_LEFT), KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO),
	[4] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LCTL(KC_DOWN), LCTL(KC_UP), KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_F11, RGUI(KC_0), KC_NO, LGUI(KC_LBRC), LGUI(KC_Q), LGUI(KC_W), KC_WH_U, LGUI(KC_P), KC_NO, KC_NO, KC_RGUI, KC_MS_U, KC_NO, KC_NO, RGUI(KC_RBRC), KC_ESC, LGUI(KC_A), KC_WH_L, KC_WH_D, KC_WH_R, LGUI(KC_D), KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, RGUI(KC_O), KC_NO, KC_LSFT, LGUI(KC_Z), KC_ACL0, LGUI(KC_C), LGUI(KC_V), LGUI(KC_B), RGUI(KC_K), RGUI(KC_M), KC_NO, KC_NO, KC_NO, KC_RSFT, KC_SPC, LGUI(KC_GRV), KC_LEFT, KC_RGHT, KC_UP, KC_DOWN, KC_MINS, KC_EQL, LCAG(KC_LEFT), LCAG(KC_TAB), KC_BTN1, KC_BTN2, MEH(KC_LEFT), MEH(KC_RGHT), KC_BTN1, KC_TAB, KC_TRNS, KC_NO, KC_ENT, KC_BTN2)
};
