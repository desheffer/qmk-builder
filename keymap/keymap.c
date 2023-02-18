/* Copyright 2021-2022 Doug Sheffer
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

const uint8_t RGBLED_RAINBOW_MOOD_INTERVALS[] PROGMEM = {255, 127, 64};

enum planck_layers {
    _COLEMAK,
    _QWERTY,
    _NAVIGATION,
    _SHIFT,
    _SYMBOL,
    _NUMBER,
    _FUNCTION,
};

enum planck_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
};

#define ALT_GR  LALT_T(KC_RALT)
#define CTL_ENT RCTL_T(KC_ENT)
#define CTL_ESC LCTL_T(KC_ESC)
#define FN      MO(_FUNCTION)
#define NAV_SPC LT(_NAVIGATION, KC_SPC)
#define NUMBER  MO(_NUMBER)
#define SHIFT   MO(_SHIFT)
#define SYMBOL  MO(_SYMBOL)
#define TMUX    LCTL(KC_B)
#define VIM_DN  LCTL(KC_D)
#define VIM_UP  LCTL(KC_U)
#define ___X___ XXXXXXX

/* Legend
 * ┌────────┐
 * │ Esc    │ <- what happens when the key is tapped
 * │[Ctrl]  │ <- what happens when the key is held
 * ├────────┤
 * │        │ <- this key does nothing
 * │        │
 * ├────────┤
 * │   --   │ <- this key is transparent
 * │   --   │
 * ├────────┤
 * │########│ <- this key is being held
 * │########│
 * └────────┘
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
 * │ Tab    │ q      │ w      │ f      │ p      │ g      │ j      │ l      │ u      │ y      │ '      │ Bkspc  │
 * │        │        │        │        │        │        │        │        │        │        │        │        │
 * ├────────╔════════╦════════╦════════╦════════╗────────┼────────╔════════╦════════╦════════╦════════╗────────┤
 * │ Esc    ║ a      ║ r      ║ s      ║ t      ║ d      │ h      ║ n      ║ e      ║ i      ║ o      ║ Enter  │
 * │[Ctrl]  ║        ║        ║        ║        ║        │        ║        ║        ║        ║        ║[Ctrl]  │
 * ├────────╚════════╩════════╩════════╩════════╝────────┼────────╚════════╩════════╩════════╩════════╝────────┤
 * │        │ z      │ x      │ c      │ v      │ b      │ k      │ m      │ ,      │ .      │ /      │ AltGr  │
 * │[Alt]   │        │        │        │        │        │        │        │        │        │        │[Alt]   │
 * ├────────┼────────┼────────┼────────╔════════╦═════════════════╦════════╗────────┼────────┼────────┼────────┤
 * │        │        │ Colemak│ Qwerty ║        ║ Space           ║        ║ ←      │ ↓      │ ↑      │ →      │
 * │[GUI]   │[Fn]    │        │        ║[Symbol]║[Navigation]     ║[Shift] ║        │        │        │        │
 * └────────┴────────┴────────┴────────╚════════╩═════════════════╩════════╝────────┴────────┴────────┴────────┘
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSPC,
    CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    CTL_ENT,
    KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ALT_GR,
    KC_LGUI, FN,      ___X___, QWERTY,  SYMBOL,  NAV_SPC, NAV_SPC, SHIFT,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Qwerty
 * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
 * │ Tab    │ q      │ w      │ e      │ r      │ t      │ y      │ u      │ i      │ o      │ p      │ Bkspc  │
 * │        │        │        │        │        │        │        │        │        │        │        │        │
 * ├────────╔════════╦════════╦════════╦════════╗────────┼────────╔════════╦════════╦════════╦════════╗────────┤
 * │ Esc    ║ a      ║ s      ║ d      ║ f      ║ g      │ h      ║ j      ║ k      ║ l      ║ ;      ║ Enter  │
 * │        ║        ║        ║        ║        ║        │        ║        ║        ║        ║        ║        │
 * ├────────╚════════╩════════╩════════╩════════╝────────┼────────╚════════╩════════╩════════╩════════╝────────┤
 * │        │ z      │ x      │ c      │ v      │ b      │ n      │ m      │ ,      │ .      │ /      │        │
 * │[Shift] │        │        │        │        │        │        │        │        │        │        │[Shift] │
 * ├────────┼────────┼────────┼────────╔════════╦═════════════════╦════════╗────────┼────────┼────────┼────────┤
 * │        │ AltGr  │ Colemak│ Qwerty ║        ║ Space           ║        ║ ←      │ ↓      │ ↑      │ →      │
 * │[Ctrl]  │[Alt]   │        │        ║[Symbol]║                 ║[Shift] ║        │        │        │        │
 * └────────┴────────┴────────┴────────╚════════╩═════════════════╩════════╝────────┴────────┴────────┴────────┘
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, ALT_GR,  COLEMAK, ___X___, SYMBOL,  KC_SPC,  KC_SPC,  SHIFT,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Navigation
 * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
 * │        │        │        │        │        │        │        │        │ Ctrl+d │ Ctrl+u │        │ Bkspc  │
 * │        │        │        │        │        │        │        │        │        │        │        │        │
 * ├────────╔════════╦════════╦════════╦════════╗────────┼────────╔════════╦════════╦════════╦════════╗────────┤
 * │ Esc    ║        ║        ║        ║        ║        │ Tmux   ║ ←      ║ ↓      ║ ↑      ║ →      ║ Del    │
 * │[Ctrl]  ║        ║        ║        ║        ║        │        ║        ║        ║        ║        ║        │
 * ├────────╚════════╩════════╩════════╩════════╝────────┼────────╚════════╩════════╩════════╩════════╝────────┤
 * │        │        │        │        │        │        │        │ PgUp   │ Home   │ End    │ PgDown │ MNext  │
 * │[Alt]   │        │        │        │        │        │        │        │        │        │        │        │
 * ├────────┼────────┼────────┼────────╔════════╦═════════════════╦════════╗────────┼────────┼────────┼────────┤
 * │   --   │   --   │   --   │   --   ║   --   ║#################║   --   ║ Mute   │ Vol-   │ Vol+   │ MPlay  │
 * │   --   │   --   │   --   │   --   ║   --   ║#################║   --   ║        │        │        │        │
 * └────────┴────────┴────────┴────────╚════════╩═════════════════╩════════╝────────┴────────┴────────┴────────┘
 */
[_NAVIGATION] = LAYOUT_planck_grid(
    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, VIM_DN,  VIM_UP,  ___X___, KC_BSPC,
    CTL_ESC, ___X___, ___X___, ___X___, ___X___, ___X___, TMUX,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,
    KC_LALT, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_PGUP, KC_HOME, KC_END,  KC_PGDN, KC_MNXT,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Shift
 * This is a transparent layer with a shift modifier. Modifier logic is handled
 * by the `layer_state_set_user` function.
 * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
 * │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │
 * │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │
 * ├────────╔════════╦════════╦════════╦════════╗────────┼────────╔════════╦════════╦════════╦════════╗────────┤
 * │   --   ║   --   ║   --   ║   --   ║   --   ║   --   │   --   ║   --   ║   --   ║   --   ║   --   ║   --   │
 * │   --   ║   --   ║   --   ║   --   ║   --   ║   --   │   --   ║   --   ║   --   ║   --   ║   --   ║   --   │
 * ├────────╚════════╩════════╩════════╩════════╝────────┼────────╚════════╩════════╩════════╩════════╝────────┤
 * │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │
 * │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │   --   │
 * ├────────┼────────┼────────┼────────╔════════╦═════════════════╦════════╗────────┼────────┼────────┼────────┤
 * │   --   │   --   │   --   │   --   ║   --   ║   --       --   ║########║   --   │   --   │   --   │   --   │
 * │   --   │   --   │   --   │   --   ║   --   ║   --       --   ║########║   --   │   --   │   --   │   --   │
 * └────────┴────────┴────────┴────────╚════════╩═════════════════╩════════╝────────┴────────┴────────┴────────┘
 */
[_SHIFT] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Symbol
 * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
 * │ `      │ !      │ @      │ #      │ $      │ %      │ ^      │ &      │ *      │        │ "      │ Bkspc  │
 * │        │        │        │        │        │        │        │        │        │        │        │        │
 * ├────────╔════════╦════════╦════════╦════════╗────────┼────────╔════════╦════════╦════════╦════════╗────────┤
 * │ ~      ║ \      ║ (      ║ )      ║ =      ║        │        ║ -      ║ {      ║ }      ║ ;      ║ :      │
 * │        ║        ║        ║        ║        ║        │        ║        ║        ║        ║        ║        │
 * ├────────╚════════╩════════╩════════╩════════╝────────┼────────╚════════╩════════╩════════╩════════╝────────┤
 * │        │ |      │ [      │ ]      │ +      │        │        │ _      │ <      │ >      │ ?      │        │
 * │        │        │        │        │        │        │        │        │        │        │        │        │
 * ├────────┼────────┼────────┼────────╔════════╦═════════════════╦════════╗────────┼────────┼────────┼────────┤
 * │   --   │   --   │   --   │   --   ║########║   --       --   ║   --   ║        │        │        │        │
 * │   --   │   --   │   --   │   --   ║########║   --       --   ║   --   ║        │        │        │        │
 * └────────┴────────┴────────┴────────╚════════╩═════════════════╩════════╝────────┴────────┴────────┴────────┘
 */
[_SYMBOL] = LAYOUT_planck_grid(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, ___X___, KC_DQT,  KC_BSPC,
    KC_TILD, KC_BSLS, KC_LPRN, KC_RPRN, KC_EQL,  ___X___, ___X___, KC_MINS, KC_LCBR, KC_RCBR, KC_SCLN, KC_COLN,
    ___X___, KC_PIPE, KC_LBRC, KC_RBRC, KC_PLUS, ___X___, ___X___, KC_UNDS, KC_LT,   KC_GT,   KC_QUES, ___X___,
    _______, _______, _______, _______, _______, _______, _______, _______, ___X___, ___X___, ___X___, ___X___
),

/* Number
 * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
 * │        │        │        │        │        │        │        │        │        │        │        │ Bkspc  │
 * │        │        │        │        │        │        │        │        │        │        │        │        │
 * ├────────╔════════╦════════╦════════╦════════╗────────┼────────╔════════╦════════╦════════╦════════╗────────┤
 * │        ║ 1      ║ 2      ║ 3      ║ 4      ║ 5      │ 6      ║ 7      ║ 8      ║ 9      ║ 0      ║        │
 * │        ║        ║        ║        ║        ║        │        ║        ║        ║        ║        ║        │
 * ├────────╚════════╩════════╩════════╩════════╝────────┼────────╚════════╩════════╩════════╩════════╝────────┤
 * │        │        │        │        │        │        │        │ _      │ ,      │ .      │        │        │
 * │        │        │        │        │        │        │        │        │        │        │        │        │
 * ├────────┼────────┼────────┼────────╔════════╦═════════════════╦════════╗────────┼────────┼────────┼────────┤
 * │   --   │   --   │   --   │   --   ║########║   --       --   ║########║        │        │        │        │
 * │   --   │   --   │   --   │   --   ║########║   --       --   ║########║        │        │        │        │
 * └────────┴────────┴────────┴────────╚════════╩═════════════════╩════════╝────────┴────────┴────────┴────────┘
 */
[_NUMBER] = LAYOUT_planck_grid(
    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_BSPC,
    ___X___, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    ___X___,
    ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, ___X___, KC_UNDS, KC_COMM, KC_DOT,  ___X___, ___X___,
    _______, _______, _______, _______, _______, _______, _______, _______, ___X___, ___X___, ___X___, ___X___
),

/* Function
 * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
 * │        │ Qwerty │ Colemak│        │        │        │        │ F1     │ F2     │ F3     │ F4     │        │
 * │        │        │        │        │        │        │        │        │        │        │        │        │
 * ├────────╔════════╦════════╦════════╦════════╗────────┼────────╔════════╦════════╦════════╦════════╗────────┤
 * │ Reset  ║ RGB Mod║ RGB H+ ║ RGB S+ ║ RGB V+ ║        │        ║ F5     ║ F6     ║ F7     ║ F8     ║ PrtSc  │
 * │        ║        ║        ║        ║        ║        │        ║        ║        ║        ║        ║        │
 * ├────────╚════════╩════════╩════════╩════════╝────────┼────────╚════════╩════════╩════════╩════════╝────────┤
 * │        │        │ RGB H- │ RGB S- │ RGB V- │        │        │ F9     │ F10    │ F11    │ F12    │        │
 * │        │        │        │        │        │        │        │        │        │        │        │        │
 * ├────────┼────────┼────────┼────────╔════════╦═════════════════╦════════╗────────┼────────┼────────┼────────┤
 * │   --   │########│   --   │   --   ║   --   ║   --       --   ║   --   ║        │        │        │        │
 * │   --   │########│   --   │   --   ║   --   ║   --       --   ║   --   ║        │        │        │        │
 * └────────┴────────┴────────┴────────╚════════╩═════════════════╩════════╝────────┴────────┴────────┴────────┘
 */
[_FUNCTION] = LAYOUT_planck_grid(
    ___X___, QWERTY,  COLEMAK, ___X___, ___X___, ___X___, ___X___, KC_F1,   KC_F2,   KC_F3,   KC_F4,   ___X___,
    RESET,   RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, ___X___, ___X___, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_PSCR,
    ___X___, ___X___, RGB_HUD, RGB_SAD, RGB_VAD, ___X___, ___X___, KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___X___,
    _______, _______, _______, _______, _______, _______, _______, _______, ___X___, ___X___, ___X___, ___X___
),

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
    }

    return true;
}
