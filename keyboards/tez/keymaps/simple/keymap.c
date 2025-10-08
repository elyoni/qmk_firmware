#include "keycodes.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H



/* Layout
    KC_TRAN,  KC_TRAN,  KC_TRAN,  KC_TRAN,  KC_TRAN,               KC_TRAN,  KC_TRAN,  KC_TRAN,  KC_TRAN,  KC_TRAN,
    KC_TRAN,  KC_TRAN,  KC_TRAN,  KC_TRAN,  KC_TRAN,               KC_TRAN,  KC_TRAN,  KC_TRAN,  KC_TRAN,  KC_TRAN,
    KC_TRAN,  KC_TRAN,  KC_TRAN,  KC_TRAN,  KC_TRAN,               KC_TRAN,  KC_TRAN,  KC_TRAN,  KC_TRAN,  KC_TRAN,
    KC_TRAN,  KC_TRAN,  KC_TRAN,  KC_TRAN,  KC_TRAN,               KC_TRAN,  KC_TRAN,  KC_TRAN,  KC_TRAN,  KC_TRAN,
                                      KC_TRAN,  KC_TRAN,  KC_TRAN,               KC_TRAN,  KC_TRAN,  KC_TRAN,
*/

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
#define KC_CTLA LCTL(KC_A)

#define U_UND LCTL(KC_Z)
#define U_RDO LCTL(KC_Y)

#define MIC_MUTE KC_F20
#define SPK_MUTE KC_MUTE

// Combo definitions
enum combo_events {
    JF_ESC,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM jf_combo[] = {KC_J, LT(NUMPAD,KC_F), COMBO_END};

combo_t key_combos[] = {
    [JF_ESC] = COMBO(jf_combo, KC_ESC),
};

enum {
    TD_E_B,
    HEBREW_TOGGLE = SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_v3(
        KC_Q,                KC_W,                KC_E,                KC_R,                    KC_T,                       KC_Y,                KC_U,                KC_I,                KC_O,                MT(MOD_LALT, KC_P),
        MT(MOD_LCTL, KC_A),  MT(MOD_LGUI, KC_S),  MT(MOD_LSFT, KC_D),  LT(NUMPAD,KC_F),         KC_G,                       KC_H,                KC_J,                MT(MOD_RSFT,KC_K),   MT(MOD_RGUI, KC_L),  MT(MOD_RCTL, KC_SCOLON),
        MT(MOD_LALT, KC_Z),  KC_X,                KC_C,                LT(SYMB,KC_V),           KC_B,                       KC_N,                KC_M,                KC_COMMA,            KC_DOT,              LT(MOUSE_F,KC_SLASH),
                                                  MO(OTHER),           LT(NUMPAD,KC_SPACE),     KC_LSHIFT,                  LT(SYMB,KC_BSPACE),  MO(MOVE),            KC_ENTER
),
    [MOVE] = LAYOUT_v3(
        KC_TRAN,             KC_EXLM,             KC_LBRACKET,         KC_RBRACKET,             LSFT(KC_TAB),               KC_PGUP,             KC_PGDOWN,           KC_ENTER,            KC_DELETE,           LSFT(KC_F10),
        KC_LCTRL,            LSFT(KC_LALT),       KC_LPRN,             KC_RPRN,                 KC_TAB,                     KC_LEFT,             KC_DOWN,             KC_UP,               KC_RIGHT,            MT(MOD_RCTL, KC_ENTER),
        KC_LALT,             KC_TRAN,             KC_LCBR,             KC_RCBR,                 KC_GRAVE,                   KC_HOME,              KC_END,             KC_WBAK,             KC_WFWD,             KC_INSERT,
                                                  KC_PRINT_SCREEN,     KC_TRAN,                 KC_TRAN,                    KC_TRAN,             KC_TRAN,             KC_TRAN
    ),
    [NUMPAD] = LAYOUT_v3(
        KC_BSPACE,           KC_ESCAPE,           KC_ENTER,            KC_COPY,                 KC_PASTE,                   KC_PLUS,             KC_7,                KC_8,                KC_9,                KC_SLASH ,
        KC_LCTRL,            KC_LGUI,             KC_LSHIFT,           KC_GRAVE,                KC_CUT,                     KC_MINUS,            KC_4,                KC_5,                KC_6,                MT(MOD_RCTL, KC_EQUAL),
        KC_LALT,             KC_NUMLOCK,          KC_TRAN,             KC_TRAN,                 KC_GRAVE,                   KC_COMMA,            KC_1,                KC_2,                KC_3,                KC_KP_DOT,
                                                  KC_NUMLOCK,          KC_TRAN,                 KC_TRAN,                    KC_TRAN,             KC_TRAN,             KC_0
    ),
    [MOUSE_F] = LAYOUT_v3(
        KC_MS_WH_LEFT,       KC_MS_WH_DOWN,       KC_MS_UP,            KC_MS_WH_UP,             KC_MS_WH_RIGHT,             KC_F11,              KC_F7,               KC_F8,               KC_F9,               KC_F12,
        KC_MS_BTN1,          KC_MS_LEFT,          KC_MS_DOWN,          KC_MS_RIGHT,             RCTL(KC_RSHIFT),            KC_TRAN,             KC_F4,               KC_F5,               KC_F6,               KC_F10,
        KC_MS_BTN2,          KC_MS_BTN3,          KC_COPY,             KC_PASTE,                LCTL(KC_LSHIFT),            KC_TRAN,             KC_F1,               KC_F2,               KC_F3,               KC_TRAN,
                                                  KC_TRAN,             KC_MS_BTN1,              KC_MS_BTN2,                 KC_MS_BTN1,          KC_MS_BTN2,          KC_MS_BTN1
    ),
    [SYMB] = LAYOUT_v3(
        KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,                 KC_TRAN,                    KC_TRAN,             RSFT(KC_BSLASH),     KC_QUOTE,            KC_DQUO,             KC_BSLASH,
        KC_M_ALL,            KC_TRAN,             KC_TRAN,             KC_TRAN,                 KC_TRAN,                    KC_UNDS,             KC_ASTR,             KC_HASH,             KC_DLR,              KC_UNDS,
        RCTL(KC_Z),          KC_TRAN,             KC_TRAN,             KC_PASTE,                KC_TRAN,                    KC_TRAN,             KC_TILD,             RSFT(KC_BSLASH),     KC_F4,               KC_EQUAL,
                                                  KC_TRAN,             KC_TRAN,                 KC_TRAN,                    KC_TRAN,             KC_TRAN,             KC_TRAN
    ),
    [OTHER] = LAYOUT_v3(
        KC_VOLU,             SPK_MUTE,            KC_BRIU,             RGB_M_B,                 RGB_TOG,                    QK_BOOTLOADER,       KC_NO,               KC_NO,               KC_NO,               TO(GAMEM_L),
        KC_VOLD,             MIC_MUTE,            KC_BRID,             KC_NO,                   KC_NO,                      KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,
        KC_NO,               KC_NO,               KC_NO,               KC_NO,                   HEBREW_TOGGLE,              KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,
                                                  KC_NO,               KC_NO,                   KC_NO,                      KC_NO,               KC_NO,               KC_NO
    ),
    [GAMEM_L] = LAYOUT_v3(
        KC_ESC,              KC_Q,                KC_W,                KC_E,                    KC_R,                       KC_Y,                KC_U,                KC_I,                KC_O,                TO(BASE),
        KC_LCTRL,            KC_A,                KC_S,                KC_D,                    KC_F,                       KC_H,                KC_J,                KC_K,                KC_L,                KC_SCOLON,
        KC_LSHIFT,           KC_Z,                KC_X,                KC_C,                    KC_V,                       KC_N,                KC_M,                KC_COMMA,            KC_DOT,              KC_SLASH,
                                                  KC_B,                KC_SPACE,                MO(GAMEM_R),                LT(MOVE,KC_BSPACE),  MO(MOVE),            LT(OTHER,KC_TRAN)
    ),
    [GAMEM_R] = LAYOUT_v3(
        KC_1,                KC_2,                KC_3,                KC_4,                    KC_5,                       KC_ESCAPE,           KC_TRAN,             KC_TRAN,             KC_TRAN,             TO(BASE),
        KC_6,                KC_7,                KC_8,                KC_9,                    KC_0,                       KC_LEFT,             KC_DOWN,             KC_UP,               KC_RIGHT,            KC_TRAN,
        KC_LSHIFT,           KC_Z,                KC_X,                KC_C,                    KC_B,                       KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,             KC_TRAN,
                                                  KC_B,                KC_SPACE,                KC_TRAN,                    KC_TRAN,             KC_TRAN,             TO(BASE)
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
            rgblight_sethsv_noeeprom(170, 255, 50);  // Dim blue
            break;
        case NUMPAD:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+0);
            rgblight_sethsv_noeeprom(85, 255, 50);   // Dim green
            break;
        case MOUSE_F:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+0);
            rgblight_sethsv_noeeprom(128, 255, 50);  // Dim cyan
            break;
        case SYMB:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+0);
            rgblight_sethsv_noeeprom(43, 255, 50);   // Dim gold
            break;
        case GAMEM_L:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(0, 255, 255);  // Maximum brightness red for gaming
            break;
        case GAMEM_R:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+0);
            rgblight_sethsv_noeeprom(20, 255, 255); // Maximum brightness orange for gaming
            break;
        case OTHER:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(213, 255, 50);  // Dim purple
            break;
        default:
            break;
    }
    return state;
};
#endif

/*void keyboard_post_init_user(void) {*/
/*#ifdef RGBLIGHT_ENABLE*/
    /*// Boot sequence: brief color indication*/
    /*rgblight_enable();*/
    /*rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);*/

    /*// Flash green for 500ms to indicate successful boot*/
    /*rgblight_sethsv(HSV_GREEN);*/
    /*wait_ms(500);*/

    /*// Then turn off for normal BASE layer behavior*/
    /*rgblight_sethsv(HSV_OFF);*/
/*#endif*/
/*}*/

static bool hebrew_mode = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HEBREW_TOGGLE:
            if (record->event.pressed) {
                hebrew_mode = !hebrew_mode;
                // Optional: Add visual feedback with RGB
                #ifdef RGBLIGHT_ENABLE
                if (hebrew_mode) {
                    rgblight_sethsv_noeeprom(30, 255, 100);  // Orange indicator for Hebrew mode
                } else {
                    rgblight_sethsv_noeeprom(HSV_OFF);       // Turn off when back to English
                }
                #endif
            }
            return false;
    }
    return true;
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // Disable jf combo when in Hebrew mode
    if (combo_index == JF_ESC && hebrew_mode) {
        return false;
    }
    return true;
}

// Apply HOLD_ON_OTHER_KEY_PRESS only to specific layer-tap keys
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(NUMPAD, KC_SPACE):
        case LT(NUMPAD, KC_F):
        case LT(SYMB, KC_BSPACE):
            return true;  // Enable for frequently used layer-tap keys
        default:
            return false; // Disable for mod-tap keys and letter-based layer-taps
    }
}
