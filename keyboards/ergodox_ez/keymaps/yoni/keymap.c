/* Ergodox EZ keymap aligned with Tez keyboard layout
 *
 * This keymap mirrors the Tez/Planck layout for consistency across keyboards.
 * Extra keys on the Ergodox are used for additional functionality.
 */

#include QMK_KEYBOARD_H

enum layer_names {
    BASE,
    GAMEM_L,
    GAMEM_R,
    MOVE,
    NUMPAD,
    MOUSE_F,
    SYMB,
    OTHER,
    GAME_NUM,
};

enum custom_keycodes {
    HEBREW_TOGGLE = SAFE_RANGE,
    RGB_TOGGLE,
};

#define KC_TRAN KC_TRANSPARENT
#define KC_LSHIFT KC_LEFT_SHIFT
#define KC_RSHIFT KC_RIGHT_SHIFT
#define KC_LCTRL KC_LEFT_CTRL
#define KC_RCTRL KC_RIGHT_CTRL
#define KC_PGDOWN KC_PAGE_DOWN
#define KC_PGUP KC_PAGE_UP

#define KC_LBRACKET KC_LEFT_BRACKET
#define KC_RBRACKET KC_RIGHT_BRACKET
#define KC_SCOLON KC_SEMICOLON
#define KC_BSPACE KC_BACKSPACE
#define KC_NUMLOCK KC_NUM_LOCK
#define KC_BSLASH KC_BACKSLASH

#define KC_COPY LCTL(KC_C)
#define KC_PASTE LCTL(KC_V)
#define KC_CUT LCTL(KC_X)
#define KC_M_ALL LCTL(KC_A)

#define U_UND LCTL(KC_Z)
#define U_RDO LCTL(KC_Y)

#define MIC_MUTE KC_F20
#define SPK_MUTE KC_MUTE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE Layer - Main typing layer (aligned with Tez)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | ESC  |           | Game |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl/A | Gui/S|Shft/D|Num/F |   G  |------|      |           |      |------|   H  |   J  |Shft/K| Gui/L|Ctrl/;  |
 * |--------+------+------+------+------+------| HOME |           | END  |------+------+------+------+------+--------|
 * | Alt/Z  |   X  |   C  |Sym/V |   B  |      |      |           |      |   N  |   M  |   ,  |   .  |Mous/ | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |OTHER |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |Space |LShift|------|       |------| Bksp |Enter |
 *                                 |/Num  |      |OTHER |       | MOVE |/Sym  |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand                                                    // right hand
  KC_GRAVE,            KC_1,                KC_2,                KC_3,                KC_4,                KC_5,    KC_ESC,                 TG(GAMEM_L), KC_6,    KC_7,                KC_8,                KC_9,                KC_0,                KC_MINS,
  KC_TAB,              KC_Q,                KC_W,                KC_E,                KC_R,                KC_T,    KC_LBRACKET,            KC_RBRACKET, KC_Y,    KC_U,                KC_I,                KC_O,                MT(MOD_LALT, KC_P),  KC_BSLASH,
  MT(MOD_LCTL, KC_A),  MT(MOD_LGUI, KC_S),  MT(MOD_LSFT, KC_D),  LT(NUMPAD,KC_F),     KC_G,                                                              KC_H,    KC_J,                MT(MOD_RSFT,KC_K),   MT(MOD_RGUI, KC_L),  MT(MOD_RCTL, KC_SCOLON), KC_QUOTE,
  MT(MOD_LALT, KC_Z),  KC_X,                KC_C,                LT(SYMB,KC_V),       KC_B,                KC_HOME, KC_NO,                  KC_NO,       KC_END,  KC_N,                KC_M,                KC_COMMA,            KC_DOT,              LT(MOUSE_F,KC_SLASH), KC_RSHIFT,
  MO(OTHER),           KC_NO,               KC_NO,               KC_NO,               KC_NO,                                                                      KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,
                                                                                                           KC_NO,   KC_NO,                  KC_NO,       KC_NO,
                                                                                                                    KC_NO,                  KC_NO,
                                                                               LT(NUMPAD,KC_SPACE), KC_LSHIFT, MO(OTHER),                  MO(MOVE),    LT(SYMB,KC_BSPACE), KC_ENTER
),

/* MOVE Layer - Navigation
 */
[MOVE] = LAYOUT_ergodox_pretty(
  // left hand                                                    // right hand
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
  KC_TRAN,             KC_TRAN,             KC_EXLM,             KC_LBRACKET,         KC_RBRACKET,         LSFT(KC_TAB), KC_TRAN,           KC_TRAN,     KC_PGUP, KC_PGDOWN,           KC_ENTER,            KC_DELETE,           LSFT(KC_F10),        KC_TRAN,
  KC_LCTRL,            LSFT(KC_LALT),       KC_LPRN,             KC_RPRN,             KC_TAB,                                                            KC_LEFT, KC_DOWN,             KC_UP,               KC_RIGHT,            MT(MOD_RCTL, KC_ENTER), KC_TRAN,
  KC_LALT,             KC_TRAN,             KC_LCBR,             KC_RCBR,             KC_GRAVE,            KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, KC_HOME,             KC_END,              KC_WBAK,             KC_WFWD,             KC_INSERT,           KC_TRAN,
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_PRINT_SCREEN,     KC_TRAN,                                                                    KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
                                                                                                           KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN,
                                                                                                                    KC_TRAN,                KC_TRAN,
                                                                                      KC_TRAN, KC_TRAN,    KC_TRAN,                         KC_TRAN,     KC_TRAN, KC_TRAN
),

/* NUMPAD Layer - Numbers and mouse buttons
 */
[NUMPAD] = LAYOUT_ergodox_pretty(
  // left hand                                                    // right hand
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
  KC_TRAN,             KC_BSPACE,           KC_ESCAPE,           MS_BTN1,             MS_BTN2,             KC_TRAN, KC_TRAN,                KC_TRAN,     KC_PLUS, KC_7,                KC_8,                KC_9,                KC_SLASH,            KC_TRAN,
  KC_LCTRL,            KC_LGUI,             KC_LSHIFT,           KC_GRAVE,            KC_ENTER,                                                          KC_MINUS, KC_4,               KC_5,                KC_6,                MT(MOD_RCTL, KC_EQUAL), KC_TRAN,
  KC_LALT,             KC_NUMLOCK,          KC_F13,              KC_TRAN,             KC_GRAVE,            KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, KC_COMMA,            KC_1,                KC_2,                KC_3,                KC_KP_DOT,           KC_TRAN,
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_NUMLOCK,          KC_TRAN,                                                                    KC_0,                KC_0,                KC_DOT,              KC_TRAN,             KC_TRAN,
                                                                                                           KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN,
                                                                                                                    KC_TRAN,                KC_TRAN,
                                                                                      KC_TRAN, KC_TRAN,    KC_TRAN,                         KC_TRAN,     KC_TRAN, KC_0
),

/* MOUSE_F Layer - Mouse and function keys
 */
[MOUSE_F] = LAYOUT_ergodox_pretty(
  // left hand                                                    // right hand
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
  KC_TRAN,             MS_WHLL,             MS_WHLD,             MS_UP,               MS_WHLU,             MS_WHLR, KC_TRAN,                KC_TRAN,     KC_F11,  KC_F7,               KC_F8,               KC_F9,               KC_F12,              KC_TRAN,
  MS_BTN1,             MS_LEFT,             MS_DOWN,             MS_RGHT,             RCTL(KC_RSHIFT),                                                   KC_TRAN, KC_F4,               KC_F5,               KC_F6,               KC_F10,              KC_TRAN,
  MS_BTN2,             MS_BTN3,             KC_COPY,             KC_PASTE,            LCTL(KC_LSHIFT),     KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, KC_TRAN,             KC_F1,               KC_F2,               KC_F3,               KC_TRAN,             KC_TRAN,
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             MS_BTN1,                                                                    KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
                                                                                                           KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN,
                                                                                                                    KC_TRAN,                KC_TRAN,
                                                                                      MS_BTN1, MS_BTN2,    KC_TRAN,                         KC_TRAN,     MS_BTN1, MS_BTN2
),

/* SYMB Layer - Symbols
 */
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand                                                    // right hand
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, RSFT(KC_BSLASH),     KC_QUOTE,            KC_DQUO,             KC_BSLASH,           KC_TRAN,
  KC_M_ALL,            KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,                                                           KC_UNDS, KC_ASTR,             KC_HASH,             KC_DLR,              KC_UNDS,             KC_TRAN,
  RCTL(KC_Z),          KC_TRAN,             KC_TRAN,             KC_PASTE,            KC_TRAN,             KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, KC_TRAN,             KC_TILD,             RSFT(KC_BSLASH),     KC_F4,               KC_EQUAL,            KC_TRAN,
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,                                                                    KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
                                                                                                           KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN,
                                                                                                                    KC_TRAN,                KC_TRAN,
                                                                                      KC_TRAN, KC_TRAN,    KC_TRAN,                         KC_TRAN,     KC_TRAN, KC_TRAN
),

/* OTHER Layer - System controls
 */
[OTHER] = LAYOUT_ergodox_pretty(
  // left hand                                                    // right hand
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
  KC_TRAN,             KC_VOLU,             SPK_MUTE,            KC_BRIU,             RGB_M_B,             RGB_TOGGLE, KC_TRAN,             KC_TRAN,     QK_BOOTLOADER, KC_NO,          KC_NO,               KC_NO,               TO(GAMEM_L),         KC_TRAN,
  KC_VOLD,             MIC_MUTE,            KC_BRID,             KC_NO,               KC_NO,                                                             KC_NO,   KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_TRAN,
  KC_NO,               KC_NO,               KC_NO,               KC_NO,               HEBREW_TOGGLE,       KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_TRAN,
  KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,                                                                      KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,
                                                                                                           KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN,
                                                                                                                    KC_TRAN,                KC_TRAN,
                                                                                      KC_NO,   KC_NO,      KC_TRAN,                         KC_TRAN,     KC_NO,   KC_NO
),

/* GAMEM_L Layer - Gaming left hand
 */
[GAMEM_L] = LAYOUT_ergodox_pretty(
  // left hand                                                    // right hand
  KC_ESC,              KC_1,                KC_2,                KC_3,                KC_4,                KC_5,    KC_6,                   TO(BASE),    KC_7,    KC_8,                KC_9,                KC_0,                KC_MINS,             KC_EQL,
  KC_TAB,              KC_ESC,              KC_Q,                KC_W,                KC_E,                KC_R,    KC_T,                   KC_TRAN,     KC_Y,    KC_U,                KC_I,                KC_O,                KC_P,                KC_BSLASH,
  KC_LCTRL,            KC_A,                KC_S,                KC_D,                KC_F,                                                              KC_H,    KC_J,                KC_K,                KC_L,                KC_SCOLON,           KC_QUOTE,
  KC_LSHIFT,           KC_Z,                KC_X,                KC_C,                KC_V,                KC_B,    KC_G,                   KC_TRAN,     KC_TRAN, KC_N,                KC_M,                KC_COMMA,            KC_DOT,              KC_SLASH,            KC_RSHIFT,
  KC_LALT,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,                                                                    KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             TO(BASE),
                                                                                                           KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN,
                                                                                                                    KC_TRAN,                KC_TRAN,
                                                                                      KC_SPACE, MO(GAMEM_R), KC_TRAN,                       KC_TRAN,     LT(MOVE,KC_BSPACE), KC_ENTER
),

/* GAMEM_R Layer - Gaming right hand (numbers)
 */
[GAMEM_R] = LAYOUT_ergodox_pretty(
  // left hand                                                    // right hand
  KC_TRAN,             KC_F1,               KC_F2,               KC_F3,               KC_F4,               KC_F5,   KC_F6,                  TO(BASE),    KC_F7,   KC_F8,               KC_F9,               KC_F10,              KC_F11,              KC_F12,
  KC_TRAN,             KC_1,                KC_2,                KC_3,                KC_4,                KC_5,    KC_TRAN,                KC_TRAN,     KC_ESCAPE, KC_TRAN,           KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
  KC_6,                KC_7,                KC_8,                KC_9,                KC_0,                                                              KC_LEFT, KC_DOWN,             KC_UP,               KC_RIGHT,            KC_TRAN,             KC_TRAN,
  KC_LSHIFT,           KC_Z,                KC_X,                KC_C,                KC_B,                KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,                                                                    KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             TO(BASE),
                                                                                                           KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN,
                                                                                                                    KC_TRAN,                KC_TRAN,
                                                                                      KC_SPACE, KC_TRAN,   KC_TRAN,                         KC_TRAN,     KC_TRAN, TO(BASE)
),

};
// clang-format on

static bool hebrew_mode = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HEBREW_TOGGLE:
            if (record->event.pressed) {
                hebrew_mode = !hebrew_mode;
                #ifdef RGBLIGHT_ENABLE
                if (hebrew_mode) {
                    rgblight_sethsv_noeeprom(30, 255, 100);
                } else {
                    rgblight_sethsv_noeeprom(HSV_OFF);
                }
                #endif
            }
            return false;
        case RGB_TOGGLE:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                if (rgblight_is_enabled()) {
                    rgblight_disable();
                } else {
                    rgblight_enable();
                }
                #endif
            }
            return false;
    }
    return true;
}

// Apply HOLD_ON_OTHER_KEY_PRESS only to specific layer-tap keys
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(NUMPAD, KC_SPACE):
        case LT(SYMB, KC_BSPACE):
        case LT(NUMPAD, KC_F):
            return true;
        default:
            return false;
    }
}

// Increase tapping term for F key to prevent accidental NUMPAD activation during fast typing
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(NUMPAD, KC_F):
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

// LED layer indication
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case BASE:
            break;
        case MOVE:
            ergodox_right_led_1_on();
            break;
        case NUMPAD:
            ergodox_right_led_2_on();
            break;
        case MOUSE_F:
            ergodox_right_led_3_on();
            break;
        case SYMB:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case OTHER:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case GAMEM_L:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case GAMEM_R:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

    return state;
};
