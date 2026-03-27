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

/* Ergodox layout structure (LAYOUT_ergodox_pretty, 76 keys):
 *
 * Row 1: 7L + 7R  (number row + inner cols)     ← all TRAN except BASE
 * Row 2: 7L + 7R  (outer col, 5 core, inner col)
 * Row 3: 5L + 6R  (5 core left, 5 core right + QUOTE=TRAN)
 * Row 4: 7L + 8R  (outer, 5 core, 2 inner | 2 inner, 5 core, outer)
 * Row 5: 5L + 5R  ← all TRAN
 * Thumb: 2+1+3 per side — inner top 2x2 + mid 1x1 + main 3x3
 *
 * Thumb main matches Planck bottom row active keys:
 *   L: MO(OTHER), LT(NUMPAD,SPACE), KC_LSHIFT
 *   R: LT(SYMB,BSPACE), MO(MOVE), KC_ENTER
 */

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_ergodox_pretty(
  // Row 1 — number row: transparent (TG game toggle kept on right inner)
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN, KC_TRAN,                TG(GAMEM_L), KC_TRAN, KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
  // Row 2 — outer=TRAN, 5 core keys, inner=TRAN
  KC_TRAN,             KC_Q,                KC_W,                KC_E,                KC_R,                KC_T,    KC_TRAN,                KC_TRAN,     KC_Y,    KC_U,                KC_I,                KC_O,                MT(MOD_LALT, KC_P),  KC_TRAN,
  // Row 3 — 5 core left | 5 core right + TRAN (quote col)
  MT(MOD_LCTL, KC_A),  MT(MOD_LGUI, KC_S),  MT(MOD_LSFT, KC_D),  LT(NUMPAD,KC_F),     KC_G,                                                              KC_H,    KC_J,                MT(MOD_RSFT,KC_K),   MT(MOD_RGUI, KC_L),  MT(MOD_RCTL, KC_SCOLON), KC_TRAN,
  // Row 4 — outer=TRAN, 5 core, 2 inner=TRAN | 2 inner=TRAN, 5 core, outer=TRAN
  KC_TRAN,             MT(MOD_LALT, KC_Z),  KC_X,                KC_C,                LT(SYMB,KC_V),       KC_B,    KC_TRAN,                KC_TRAN,     KC_TRAN, KC_N,                KC_M,                KC_COMMA,            KC_DOT,              LT(MOUSE_F,KC_SLASH), KC_TRAN,
  // Row 5 — all transparent
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,                                                                    KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
  // Thumb inner top + middle
                                                                                                           KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN,
                                                                                                                    KC_TRAN,                KC_TRAN,
  // Thumb main — matches Planck
                                                                               MO(OTHER), LT(NUMPAD,KC_SPACE), KC_LSHIFT,               LT(SYMB,KC_BSPACE), MO(MOVE), KC_ENTER
),

[MOVE] = LAYOUT_ergodox_pretty(
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
  KC_TRAN,             KC_TRAN,             KC_EXLM,             KC_LBRACKET,         KC_RBRACKET,         LSFT(KC_TAB), KC_TRAN,           KC_TRAN,     KC_PGUP, KC_PGDOWN,           KC_ENTER,            KC_DELETE,           LSFT(KC_F10),        KC_TRAN,
  KC_LCTRL,            LSFT(KC_LALT),       KC_LPRN,             KC_RPRN,             KC_TAB,                                                            KC_LEFT, KC_DOWN,             KC_UP,               KC_RIGHT,            MT(MOD_RCTL, KC_ENTER), KC_TRAN,
  KC_TRAN,             KC_LALT,             KC_TRAN,             KC_LCBR,             KC_RCBR,             KC_GRAVE, KC_TRAN,              KC_TRAN,     KC_TRAN, KC_HOME,             KC_END,              KC_WBAK,             KC_WFWD,             KC_INSERT,           KC_TRAN,
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,                                                                    KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
                                                                                                           KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN,
                                                                                                                    KC_TRAN,                KC_TRAN,
                                                                               KC_PRINT_SCREEN, KC_TRAN,   KC_TRAN,                         KC_TRAN,     KC_TRAN, KC_TRAN
),

[NUMPAD] = LAYOUT_ergodox_pretty(
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
  KC_TRAN,             KC_BSPACE,           KC_ESCAPE,           MS_BTN1,             MS_BTN2,             KC_TRAN, KC_TRAN,                KC_TRAN,     KC_PLUS, KC_7,                KC_8,                KC_9,                KC_SLASH,            KC_TRAN,
  KC_LCTRL,            KC_LGUI,             KC_LSHIFT,           KC_GRAVE,            KC_ENTER,                                                          KC_MINUS, KC_4,              KC_5,                KC_6,                MT(MOD_RCTL, KC_EQUAL), KC_TRAN,
  KC_TRAN,             KC_LALT,             KC_NUMLOCK,          KC_F13,              KC_TRAN,             KC_GRAVE, KC_TRAN,               KC_TRAN,     KC_TRAN, KC_COMMA,            KC_1,                KC_2,                KC_3,                KC_KP_DOT,           KC_TRAN,
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,                                                                    KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
                                                                                                           KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN,
                                                                                                                    KC_TRAN,                KC_TRAN,
                                                                               KC_NUMLOCK, KC_TRAN,        KC_TRAN,                         KC_TRAN,     KC_TRAN, KC_0
),

[MOUSE_F] = LAYOUT_ergodox_pretty(
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
  KC_TRAN,             MS_WHLL,             MS_WHLD,             MS_UP,               MS_WHLU,             MS_WHLR, KC_TRAN,                KC_TRAN,     KC_F11,  KC_F7,               KC_F8,               KC_F9,               KC_F12,              KC_TRAN,
  MS_BTN1,             MS_LEFT,             MS_DOWN,             MS_RGHT,             RCTL(KC_RSHIFT),                                                   KC_TRAN, KC_F4,               KC_F5,               KC_F6,               KC_F10,              KC_TRAN,
  KC_TRAN,             MS_BTN2,             MS_BTN3,             KC_COPY,             KC_PASTE,            LCTL(KC_LSHIFT), KC_TRAN,        KC_TRAN,     KC_TRAN, KC_TRAN,             KC_F1,               KC_F2,               KC_F3,               KC_TRAN,             KC_TRAN,
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,                                                                    KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
                                                                                                           KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN,
                                                                                                                    KC_TRAN,                KC_TRAN,
                                                                               KC_TRAN, MS_BTN1,           MS_BTN2,                         MS_BTN1,     MS_BTN2, MS_BTN1
),

[SYMB] = LAYOUT_ergodox_pretty(
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, RSFT(KC_BSLASH),     KC_QUOTE,            KC_DQUO,             KC_BSLASH,           KC_TRAN,
  KC_M_ALL,            KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,                                                           KC_UNDS, KC_ASTR,             KC_HASH,             KC_DLR,              KC_UNDS,             KC_TRAN,
  KC_TRAN,             U_UND,               KC_TRAN,             KC_TRAN,             KC_PASTE,            KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, KC_TRAN,             KC_TILD,             RSFT(KC_BSLASH),     KC_F4,               KC_EQUAL,            KC_TRAN,
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,                                                                    KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
                                                                                                           KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN,
                                                                                                                    KC_TRAN,                KC_TRAN,
                                                                               KC_TRAN, KC_TRAN,           KC_TRAN,                         KC_TRAN,     KC_TRAN, KC_TRAN
),

[OTHER] = LAYOUT_ergodox_pretty(
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
  KC_TRAN,             KC_VOLU,             SPK_MUTE,            KC_BRIU,             RGB_M_B,             RGB_TOGGLE, KC_TRAN,             KC_TRAN,     QK_BOOTLOADER, KC_NO,         KC_NO,               KC_NO,               TO(GAMEM_L),         KC_TRAN,
  KC_VOLD,             MIC_MUTE,            KC_BRID,             KC_NO,               KC_NO,                                                             KC_NO,   KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_TRAN,
  KC_TRAN,             KC_NO,               KC_NO,               KC_NO,               KC_NO,               HEBREW_TOGGLE, KC_TRAN,          KC_TRAN,     KC_TRAN, KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_TRAN,
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,                                                                    KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
                                                                                                           KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN,
                                                                                                                    KC_TRAN,                KC_TRAN,
                                                                               KC_TRAN, KC_TRAN,           KC_TRAN,                         KC_TRAN,     KC_TRAN, KC_TRAN
),

[GAMEM_L] = LAYOUT_ergodox_pretty(
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
  KC_TRAN,             KC_ESC,              KC_Q,                KC_W,                KC_E,                KC_R,    KC_TRAN,                KC_TRAN,     KC_Y,    KC_U,                KC_I,                KC_O,                TO(BASE),            KC_TRAN,
  KC_LCTRL,            KC_A,                KC_S,                KC_D,                KC_F,                                                              KC_H,    KC_J,                KC_K,                KC_L,                KC_SCOLON,           KC_TRAN,
  KC_TRAN,             KC_LSHIFT,           KC_Z,                KC_X,                KC_C,                KC_V,    KC_TRAN,                KC_TRAN,     KC_TRAN, KC_N,                KC_M,                KC_COMMA,            KC_DOT,              KC_SLASH,            KC_TRAN,
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,                                                                    KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
                                                                                                           KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN,
                                                                                                                    KC_TRAN,                KC_TRAN,
                                                                               MO(OTHER), KC_SPACE,        MO(GAMEM_R),                     KC_BSPACE,   LT(MOVE,KC_ENTER), LT(OTHER,KC_TRAN)
),

[GAMEM_R] = LAYOUT_ergodox_pretty(
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN, KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
  KC_TRAN,             KC_1,                KC_2,                KC_3,                KC_4,                KC_5,    KC_TRAN,                KC_TRAN,     KC_ESCAPE, KC_TRAN,           KC_TRAN,             KC_TRAN,             TO(BASE),            KC_TRAN,
  KC_6,                KC_7,                KC_8,                KC_9,                KC_0,                                                              KC_LEFT, KC_DOWN,             KC_UP,               KC_RIGHT,            KC_TRAN,             KC_TRAN,
  KC_TRAN,             KC_LSHIFT,           KC_Z,                KC_X,                KC_C,                KC_B,    KC_TRAN,                KC_TRAN,     KC_TRAN, KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
  KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,                                                                    KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
                                                                                                           KC_TRAN, KC_TRAN,                KC_TRAN,     KC_TRAN,
                                                                                                                    KC_TRAN,                KC_TRAN,
                                                                               KC_TRAN, KC_TRAN,           KC_TRAN,                         KC_TRAN,     KC_TRAN, TO(BASE)
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(NUMPAD, KC_F):
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (get_highest_layer(state)) {
        case MOVE:      ergodox_right_led_1_on(); break;
        case NUMPAD:    ergodox_right_led_2_on(); break;
        case MOUSE_F:   ergodox_right_led_3_on(); break;
        case SYMB:      ergodox_right_led_1_on(); ergodox_right_led_2_on(); break;
        case OTHER:     ergodox_right_led_1_on(); ergodox_right_led_3_on(); break;
        case GAMEM_L:   ergodox_right_led_1_on(); ergodox_right_led_2_on(); ergodox_right_led_3_on(); break;
        case GAMEM_R:   ergodox_right_led_2_on(); ergodox_right_led_3_on(); break;
        default: break;
    }

    return state;
}
