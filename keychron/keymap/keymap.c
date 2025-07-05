#include QMK_KEYBOARD_H

// Layer 0 is the "Mac" layer
// Layer 2 is the "Win" layer
enum layers {
    _COLEMAK,
    _COLEMAK_FN,
    _QWERTY,
    _QWERTY_FN,
    _NAVIGATION,
    _SHIFT,
    _SYMBOL,
    _NUMBER,
};

#define CTL_ENT RCTL_T(KC_ENT)
#define CTL_ESC LCTL_T(KC_ESC)
#define FN      MO(_COLEMAK_FN)
#define FN_Q    MO(_QWERTY_FN)
#define NAV_SPC LT(_NAVIGATION, KC_SPC)
#define NUMBER  MO(_NUMBER)
#define SHIFT   MO(_SHIFT)
#define SYMBOL  MO(_SYMBOL)
#define TMUX    LCTL(KC_B)
#define VIM_DN  LCTL(KC_D)
#define VIM_UP  LCTL(KC_U)
#define ___X___ XXXXXXX

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_ansi_82(
    KC_ESC,  KC_BRID, KC_BRIU, KC_NO,   KC_NO,   RM_VALD, RM_VALU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,           KC_MUTE,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PGUP,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGDN,
    CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN,          CTL_ENT,          KC_HOME,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT, KC_UP,
    KC_LGUI, KC_LALT, SYMBOL,                    NAV_SPC,                            SHIFT,   FN,      KC_RALT,          KC_LEFT, KC_DOWN, KC_RGHT
),

[_COLEMAK_FN] = LAYOUT_ansi_82(
    QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___X___,          ___X___,
    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          ___X___,
    RM_TOGG, RM_NEXT, RM_VALU, RM_HUEU, RM_SATU, RM_SPDU, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          ___X___,
    ___X___, RM_PREV, RM_VALD, RM_HUED, RM_SATD, RM_SPDD, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          KC_PSCR,          ___X___,
    KC_CAPS, ___X___, ___X___, ___X___, ___X___, ___X___, NK_TOGG, ___X___, ___X___, ___X___, ___X___,                   KC_CAPS, ___X___,
    ___X___, ___X___, ___X___,                   ___X___,                            ___X___, ___X___, ___X___,          ___X___, ___X___, ___X___
),

[_QWERTY] = LAYOUT_ansi_82(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PGUP,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGDN,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_HOME,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT, KC_UP,
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, FN_Q,    KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
),

[_QWERTY_FN] = LAYOUT_ansi_82(
    QK_BOOT, KC_BRID, KC_BRIU, KC_NO,   KC_NO,   RM_VALD, RM_VALU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, ___X___,          ___X___,
    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          ___X___,
    RM_TOGG, RM_NEXT, RM_VALU, RM_HUEU, RM_SATU, RM_SPDU, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          ___X___,
    ___X___, RM_PREV, RM_VALD, RM_HUED, RM_SATD, RM_SPDD, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          KC_PSCR,          ___X___,
    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, NK_TOGG, ___X___, ___X___, ___X___, ___X___,                   ___X___, ___X___,
    ___X___, ___X___, ___X___,                   ___X___,                            ___X___, ___X___, ___X___,          ___X___, ___X___, ___X___
),

[_NAVIGATION] = LAYOUT_ansi_82(
    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          ___X___,
    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          ___X___,
    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, VIM_DN,  VIM_UP,  ___X___, ___X___, ___X___, ___X___,          ___X___,
    CTL_ESC, ___X___, ___X___, ___X___, ___X___, ___X___, TMUX,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ___X___,          ___X___,          ___X___,
    KC_LALT, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_PGUP, KC_HOME, KC_END,  KC_PGDN,                   ___X___, ___X___,
    ___X___, ___X___, ___X___,                   ___X___,                            ___X___, ___X___, ___X___,          ___X___, ___X___, ___X___
),

[_SHIFT] = LAYOUT_ansi_82(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______,
    _______, _______, _______,                   _______,                            _______, _______, _______,          _______, _______, _______
),

[_SYMBOL] = LAYOUT_ansi_82(
    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          ___X___,
    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_BSPC,          ___X___,
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, ___X___, KC_DQT,  ___X___, ___X___, ___X___,          ___X___,
    KC_TILD, KC_BSLS, KC_LPRN, KC_RPRN, KC_EQL,  ___X___, ___X___, KC_MINS, KC_LCBR, KC_RCBR, KC_SCLN, KC_COLN,          ___X___,          ___X___,
    ___X___, KC_PIPE, KC_LBRC, KC_RBRC, KC_PLUS, ___X___, ___X___, KC_UNDS, KC_LT,   KC_GT,   KC_QUES,                   ___X___, ___X___,
    _______, _______, _______,                   _______,                            _______, ___X___, ___X___,          ___X___, ___X___, ___X___
),

[_NUMBER] = LAYOUT_ansi_82(
    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          ___X___,
    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_BSPC,          ___X___,
    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,          ___X___,
    ___X___, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    ___X___,          ___X___,          ___X___,
    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_UNDS, KC_COMM, KC_DOT,  KC_SLSH,                   ___X___, ___X___,
    _______, _______, _______,                   _______,                            _______, ___X___, ___X___,          ___X___, ___X___, ___X___
),

};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_COLEMAK]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_COLEMAK_FN] = { ENCODER_CCW_CW(RM_VALD, RM_VALU) },
    [_QWERTY]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_QWERTY_FN]  = { ENCODER_CCW_CW(RM_VALD, RM_VALU) },
    [_NAVIGATION] = { ENCODER_CCW_CW(QK_MOUSE_WHEEL_UP, QK_MOUSE_WHEEL_DOWN) },
    [_SHIFT]      = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_SYMBOL]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NUMBER]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};

layer_state_t layer_state_set_user(layer_state_t state) {
    // Holding SHIFT on the _SYMBOL layer enables the _NUMBER layer.
    state = update_tri_layer_state(state, _SHIFT, _SYMBOL, _NUMBER);

    // The _SHIFT layer applies a shift modifier to any layers beneath it.
    if (get_highest_layer(state) == _SHIFT) {
        register_code(KC_LSFT);
    } else {
        unregister_code(KC_LSFT);
    }

    return state;
}
