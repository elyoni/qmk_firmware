#include "keycodes.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H



/* Layout
    KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,               KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,
    KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,               KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,
    KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,               KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,
    KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,               KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,
                                      KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,               KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,
*/

enum layer_names {
    BASE,
    MOVE,
    NUMPAD,
    MOUSE_F,
    SYMB,
    OTHER,
    GAMEM_L,
    GAMEM_R,
    GAME_NUM,
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
#define KC_PC_CUT KC_CUT
#define KC_PC_COPY KC_COPY
#define KC_PC_PASTE KC_PASTE
#define KC_NUMLOCK KC_NUM_LOCK
#define KC_BSLASH KC_BACKSLASH
#define KC_PC_UNDO KC_UNDO

#define KC_CH_LNG LALT(KC_LSHIFT)

#define KC_COPY LCTL(KC_C)
#define KC_COPY2 LCTL(KC_INSERT)
#define KC_PASTE LCTL(KC_V)
#define KC_PASTE2 LSFT(KC_INSERT)
#define KC_CUT LCTL(KC_X)
#define KC_M_ALL LCTL(KC_A)

#define U_UND LCTL(KC_Z)
#define U_RDO LCTL(KC_Y)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_v3(
            KC_Q,                KC_W,                KC_E,                KC_R,                KC_T,                       KC_Y,                KC_U,                KC_I,                KC_O,                MT(MOD_LALT, KC_P),
            MT(MOD_LCTL, KC_A),  MT(MOD_LGUI, KC_S),  MT(MOD_LSFT, KC_D),  LT(NUMPAD,KC_F),     KC_G,                       KC_H,                KC_J,                MT(MOD_RSFT,KC_K),   MT(MOD_RGUI, KC_L),  MT(MOD_RCTL, KC_SCOLON),
            MT(MOD_LALT, KC_Z),  KC_X,                KC_C,                LT(SYMB,KC_V),       KC_B,                       KC_N,                KC_M,                KC_COMMA,            KC_DOT,              LT(MOUSE_F,KC_SLASH),
                                                      MO(OTHER),           LT(NUMPAD,KC_SPACE), KC_LSHIFT,                  LT(SYMB,KC_BSPACE),  LT(MOVE,KC_ENTER),   TT(OTHER)
),
    [MOVE] = LAYOUT_v3(
            KC_TRANSPARENT,      KC_EXLM,             KC_LBRACKET,         KC_RBRACKET,         LSFT(KC_TAB),               KC_HOME,             KC_PGDOWN,           KC_PGUP,             KC_DELETE,           LSFT(KC_F10),
            KC_LCTRL,            LSFT(KC_LALT),       KC_LPRN,             KC_RPRN,             KC_TAB,                     KC_LEFT,             KC_DOWN,             KC_UP,               KC_RIGHT,            KC_RCTRL,
            KC_LALT,             KC_TRANSPARENT,      KC_LCBR,             KC_RCBR,             KC_GRAVE,                   KC_END,              KC_INSERT,           KC_WBAK,             KC_WFWD,             KC_ENTER,
                                                      KC_PRINT_SCREEN,     KC_TRANSPARENT,      KC_TRANSPARENT,             KC_TRANSPARENT,      KC_TRANSPARENT,      KC_NO
    ),
    [NUMPAD] = LAYOUT_v3(
            KC_BSPACE,           KC_ESCAPE,           KC_ENTER,            KC_COPY,      KC_PASTE,                                KC_PLUS,             KC_7,                MT(MOD_RSFT, KC_8),  KC_9,                KC_SLASH ,
            KC_LCTRL,            KC_LGUI,             KC_LSHIFT,           KC_GRAVE,     KC_CUT,                                  KC_MINUS,            KC_4,                KC_5,                KC_6,                MT(MOD_RCTL, KC_EQUAL),
            KC_LALT,             KC_NUMLOCK,          KC_TRAN,             KC_TRAN,      KC_GRAVE,                                KC_COMMA,            KC_1,                KC_2,                KC_3,                KC_KP_DOT,
                                                      KC_NUMLOCK,          KC_TRAN,      KC_TRAN,                                 KC_TRAN,      KC_TRAN,      KC_0
    ),
    [MOUSE_F] = LAYOUT_v3(
            KC_MS_WH_LEFT,       KC_MS_WH_DOWN,       KC_MS_UP,            KC_MS_WH_UP,         KC_MS_WH_RIGHT,                   KC_F11,             KC_F7,               KC_F8,               KC_F9,               KC_F12,
            KC_MS_BTN1,          KC_MS_LEFT,          KC_MS_DOWN,          KC_MS_RIGHT,         RCTL(KC_RSHIFT),                  KC_TRANSPARENT,     KC_F4,               KC_F5,               KC_F6,               KC_F10,
            KC_MS_BTN2,          KC_MS_BTN3,          KC_COPY,             KC_PASTE,            LCTL(KC_LSHIFT),                  KC_TRANSPARENT,     KC_F1,               KC_F2,               KC_F3,               KC_TRANSPARENT,
                                                      KC_TRANSPARENT,      KC_MS_BTN1,          KC_MS_BTN2,                       KC_MS_BTN1,         KC_MS_BTN2,          KC_MS_BTN1
    ),
    [SYMB] = LAYOUT_v3(
            KC_BSLASH,           KC_ESCAPE,           KC_ENTER,            KC_TRANSPARENT,      KC_TRANSPARENT,                    KC_TRANSPARENT,      RSFT(KC_BSLASH),     KC_QUOTE,            KC_DQUO,             KC_BSLASH,
            KC_M_ALL,            KC_TRANSPARENT,      KC_TRAN,             KC_TRANSPARENT,      KC_TRANSPARENT,                    KC_UNDS,             KC_ASTR,             KC_HASH,             KC_DLR,              KC_UNDS,
            RCTL(KC_Z),          KC_CUT,              KC_COPY,             KC_PASTE,            KC_TRANSPARENT,                    KC_TRANSPARENT,      KC_TILD,             RSFT(KC_BSLASH),           KC_F4,         KC_EQUAL,
                                                      KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,                    KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT
    ),
    [OTHER] = LAYOUT_v3(
            KC_VOLU,             KC_MUTE,             KC_BRIU,             RGB_M_B,             RGB_TOG,                    KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,
            KC_VOLD,             KC_NO,               KC_BRID,             KC_NO,               KC_NO,                      KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,
            KC_NO,               KC_NO,               KC_NO,               KC_NO,               QK_BOOTLOADER,              QK_BOOTLOADER,       KC_NO,               KC_NO,               KC_NO,               TG(GAMEM_L),
                                                      KC_NO,               KC_NO,               KC_NO,                      KC_NO,               KC_NO,               KC_NO
    ),
    [GAMEM_L] = LAYOUT_v3(
            KC_ESCAPE,          KC_Q,                KC_W,                KC_E,                KC_R,                       KC_ESCAPE,           KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,      TG(BASE),
            KC_LCTRL,           KC_A,                KC_S,                KC_D,                KC_F,                       KC_LEFT,             KC_DOWN,             KC_UP,               KC_RIGHT,            KC_TRANSPARENT,
            KC_LSHIFT,          KC_Z,                KC_X,                KC_C,                KC_V,                       KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,
                                                     KC_B,                KC_SPACE,            KC_G,                       KC_BSPACE,           KC_ENTER,            KC_TRANSPARENT
    ),
    [GAMEM_R] = LAYOUT_v3(
            KC_ESCAPE,          KC_Q,                KC_W,                KC_E,                KC_R,                       KC_ESCAPE,           KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,      TG(BASE),
            KC_LCTRL,           KC_A,                KC_S,                KC_D,                KC_F,                       KC_LEFT,             KC_DOWN,             KC_UP,               KC_RIGHT,            KC_TRANSPARENT,
            KC_LSHIFT,          KC_Z,                KC_X,                KC_C,                KC_V,                       KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,
                                                     KC_B,                KC_SPACE,            KC_G,                       KC_TRANSPARENT,      KC_TRANSPARENT,      TO(BASE)
    ),

};

#ifdef RGBLIGHT_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case BASE:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv(HSV_OFF);
            break;
        case MOVE:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+0);
            rgblight_sethsv(HSV_BLUE);
            break;
        case NUMPAD:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+0);
            rgblight_sethsv(HSV_GREEN);
            break;
        case MOUSE_F:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+0);
            rgblight_sethsv(HSV_CYAN);
            break;
        case SYMB:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+0);
            rgblight_sethsv(HSV_GOLD);
            break;
        case GAMEM_L:
        case GAMEM_R:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
            rgblight_sethsv(HSV_BLUE);
            break;
        default:
            break;
    }
    return state;
};
#endif

const uint16_t PROGMEM game_esc[] = {KC_SPACE, KC_T, COMBO_END};
const uint16_t PROGMEM game1[] = {KC_G, KC_ESCAPE, COMBO_END};
const uint16_t PROGMEM game2[] = {KC_G, KC_Q, COMBO_END};
const uint16_t PROGMEM game3[] = {KC_G, KC_W, COMBO_END};
const uint16_t PROGMEM game4[] = {KC_G, KC_E, COMBO_END};
const uint16_t PROGMEM game5[] = {KC_G, KC_R, COMBO_END};

const uint16_t PROGMEM game01[] = {KC_B, KC_ESCAPE, COMBO_END};
const uint16_t PROGMEM game02[] = {KC_B, KC_Q, COMBO_END};
const uint16_t PROGMEM game03[] = {KC_B, KC_W, COMBO_END};
const uint16_t PROGMEM game04[] = {KC_B, KC_E, COMBO_END};
const uint16_t PROGMEM game05[] = {KC_B, KC_R, COMBO_END};

// First, define your combo indexes
enum combo_events {
    GAME1_COMBO,
    GAME2_COMBO,
    GAME3_COMBO,
    GAME4_COMBO,
    GAME5_COMBO,
    GAME01_COMBO,
    GAME02_COMBO,
    GAME03_COMBO,
    GAME04_COMBO,
    GAME05_COMBO,
    GAME_ESC_COMBO,
};

// Your combo definitions with the enum indexes
combo_t key_combos[] = {
    [GAME1_COMBO] = COMBO(game1, KC_1),
    [GAME2_COMBO] = COMBO(game2, KC_2),
    [GAME3_COMBO] = COMBO(game3, KC_3),
    [GAME4_COMBO] = COMBO(game4, KC_4),
    [GAME5_COMBO] = COMBO(game5, KC_5),
    [GAME01_COMBO] = COMBO(game01, KC_1),
    [GAME02_COMBO] = COMBO(game02, KC_2),
    [GAME03_COMBO] = COMBO(game03, KC_3),
    [GAME04_COMBO] = COMBO(game04, KC_4),
    [GAME05_COMBO] = COMBO(game05, KC_5),
    [GAME_ESC_COMBO] = COMBO(game_esc, KC_ESCAPE),
};

// Combo trigger function that checks both combo index and layer
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    return layer_state_is(GAMEM_L) || layer_state_is(GAMEM_R);
    /*switch (combo_index) {*/
    /*    // First set of game combos (1-5)*/
    /*    case GAME1_COMBO:*/
    /*    case GAME2_COMBO:*/
    /*    case GAME3_COMBO:*/
    /*    case GAME4_COMBO:*/
    /*    case GAME5_COMBO:*/
    /*    case GAME01_COMBO:*/
    /*    case GAME02_COMBO:*/
    /*    case GAME03_COMBO:*/
    /*    case GAME04_COMBO:*/
    /*    case GAME05_COMBO:*/
    /*    case GAME_ESC_COMBO:*/

    /*    default:*/
    /*        return true; // Allow other combos to work normally*/
    /*}*/
}
