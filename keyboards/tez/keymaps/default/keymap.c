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
                                                      MO(OTHER),           LT(NUMPAD,KC_SPACE), KC_LSHIFT,                  LT(SYMB,KC_BSPACE),  LT(MOVE,KC_ENTER),   KC_NO
),
    [MOVE] = LAYOUT_v3(
            KC_TRANSPARENT,      KC_EXLM,             KC_LBRACKET,         KC_RBRACKET,         LSFT(KC_TAB),               KC_HOME,             KC_PGDOWN,           KC_PGUP,             KC_DELETE,           LSFT(KC_F10),
            KC_LCTRL,            LSFT(KC_LALT),       KC_LPRN,             KC_RPRN,             KC_TAB,                     KC_LEFT,             KC_DOWN,             KC_UP,               KC_RIGHT,            KC_RCTRL,
            KC_LALT,             KC_TRANSPARENT,      KC_LCBR,             KC_RCBR,             KC_GRAVE,                   KC_END,              KC_INSERT,           KC_WBAK,             KC_WFWD,             KC_ENTER,
                                                      KC_PRINT_SCREEN,     KC_TRANSPARENT,      KC_TRANSPARENT,             KC_TRANSPARENT,      KC_TRANSPARENT,      KC_NO
    ),
    [NUMPAD] = LAYOUT_v3(
            KC_BSPACE,           KC_ESCAPE,           KC_ENTER,            KC_COPY,      KC_PASTE,                   KC_PLUS,             KC_7,                MT(MOD_RSFT, KC_8),  KC_9,                KC_SLASH ,
            KC_LCTRL,            KC_LGUI,             KC_LSHIFT,           KC_GRAVE,     KC_CUT,                     KC_MINUS,            KC_3,                KC_5,                KC_6,                MT(MOD_RCTL, KC_EQUAL),
            KC_LALT,             KC_NUMLOCK,          KC_TRAN,             KC_TRAN,      KC_GRAVE,                   KC_COMMA,            KC_1,                KC_2,                KC_3,                KC_KP_DOT,
                                                      KC_NUMLOCK,          KC_TRAN,      QK_BOOTLOADER,              KC_TRAN,      KC_TRAN,      KC_0
    ),
    [MOUSE_F] = LAYOUT_v3(
            KC_MS_WH_LEFT,       KC_MS_WH_DOWN,       KC_MS_UP,            KC_MS_WH_UP,         KC_MS_WH_RIGHT,              KC_F11,             KC_F7,               KC_F8,               KC_F9,               KC_F12,
            KC_MS_BTN1,          KC_MS_LEFT,          KC_MS_DOWN,          KC_MS_RIGHT,         RCTL(KC_RSHIFT),             KC_TRANSPARENT,     KC_F4,               KC_F5,               KC_F6,               KC_F10,
            KC_MS_BTN2,          KC_MS_BTN3,          KC_COPY,             KC_PASTE,            LCTL(KC_LSHIFT),             KC_TRANSPARENT,     KC_F1,               KC_F2,               KC_F3,               KC_TRANSPARENT,
                                                      KC_TRANSPARENT,      KC_MS_BTN1,          KC_MS_BTN2,                  KC_MS_BTN1,         KC_MS_BTN2,          KC_MS_BTN1
    ),
    [SYMB] = LAYOUT_v3(
            KC_BSLASH,           KC_ESCAPE,           KC_ENTER,            KC_TRANSPARENT,      KC_TRANSPARENT,              KC_TRANSPARENT,      RSFT(KC_BSLASH),     KC_QUOTE,            KC_DQUO,             KC_BSLASH,
            KC_M_ALL,            KC_TRANSPARENT,      KC_TRAN,             KC_TRANSPARENT,      KC_TRANSPARENT,             KC_UNDS,             KC_ASTR,             KC_HASH,             KC_DLR,              KC_UNDS,
            KC_PC_UNDO,          KC_CUT,              KC_COPY,             KC_PASTE,            KC_TRANSPARENT,             KC_TRANSPARENT,      KC_TILD,             RSFT(KC_BSLASH),           KC_F4,         KC_EQUAL,
                                                      KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,             KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT
    ),
    [OTHER] = LAYOUT_v3(
            KC_VOLU,             KC_MUTE,             KC_BRIU,             RGB_M_B,             RGB_TOG,                    KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,
            KC_VOLD,             KC_NO,               KC_BRID,             KC_NO,               KC_NO,                      KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,
            KC_NO,               KC_NO,               KC_NO,               KC_NO,               QK_BOOTLOADER,              KC_NO,               KC_NO,               KC_NO,               KC_NO,               TG(GAMEM_L),
                                                      KC_NO,               KC_NO,               KC_NO,                      KC_NO,               KC_NO,               KC_NO
    ),
    [GAMEM_L] = LAYOUT_v3(
            KC_ESCAPE,           KC_Q,                KC_W,                KC_E,                KC_R,                       KC_ESCAPE,           KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,
            KC_LSHIFT,           KC_A,                KC_S,                KC_D,                KC_F,                       KC_LEFT,             KC_DOWN,             KC_UP,               KC_RIGHT,            KC_TRANSPARENT,
            KC_LCTRL,            KC_Z,                KC_X,                KC_C,                KC_V,                       KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT,
                                                      KC_B,                KC_SPACE,            KC_G,                       KC_TRANSPARENT,      KC_TRANSPARENT,      KC_TRANSPARENT
    ),

};


#ifdef RGBLIGHT_ENABLE
#define LED_BRIGHTNESS 10
#define HSV_LED_ORANGE 28, 255, 16
#define HSV_LED_OFF 0, 0, 0
#define HSV_LED_RED 0, 255, LED_BRIGHTNESS
#define HSV_LED_GREEN 85, 255, LED_BRIGHTNESS
#define HSV_LED_CYAN 128, 255, LED_BRIGHTNESS
#define HSV_LED_YELLOW 63, 100, LED_BRIGHTNESS
#define HSV_LED_TEST 100, 50, LED_BRIGHTNESS
#endif

#ifdef RGBLIGHT_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case BASE:
          rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
          rgblight_sethsv(HSV_LED_OFF);
        break;
      case MOVE:
          rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+3);
          rgblight_sethsv(HSV_LED_RED);
        break;
      case NUMPAD:
          rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+3);
          rgblight_sethsv(HSV_LED_GREEN);
        break;
      case MOUSE_F:
          rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+3);
          rgblight_sethsv(HSV_LED_CYAN);
        break;
      case SYMB:
          rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+3);
          rgblight_sethsv(HSV_LED_YELLOW);
        break;
  case GAMEM_L:
  case GAMEM_R:
          rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT);
          rgblight_sethsv(HSV_LED_TEST);
        break;
      default:
        break;
    }
  return state;
};
#endif
