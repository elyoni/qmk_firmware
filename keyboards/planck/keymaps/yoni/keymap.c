/* Copyright 2015-2021 Jack Humbert
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

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

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


#define KC_BOOT QK_BOOTLOADER

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

#define MIC_MUTE KC_F20
#define SPK_MUTE KC_MUTE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[BASE] = LAYOUT_planck_grid(
    KC_Q,               KC_W,               KC_E,               KC_R,                KC_T,                _______,   TG(GAMEM_L),        KC_Y,               KC_U,              KC_I,               KC_O,               MT(MOD_LALT, KC_P),
    MT(MOD_LCTL, KC_A), MT(MOD_LGUI, KC_S), MT(MOD_LSFT, KC_D), LT(NUMPAD,KC_F),     KC_G,                _______,   _______,            KC_H,               KC_J,              MT(MOD_RSFT,KC_K),  MT(MOD_RGUI, KC_L), MT(MOD_RCTL, KC_SCOLON),
    MT(MOD_LALT, KC_Z), KC_X,               KC_C,               LT(SYMB,KC_V),       KC_B,                _______,   _______,            KC_N,               KC_M,              KC_COMM,            KC_DOT,             LT(MOUSE_F,KC_SLASH),
    _______,            _______,            _______,            MO(OTHER),           LT(NUMPAD,KC_SPACE), KC_LSHIFT, LT(SYMB,KC_BSPACE), MO(MOVE),           KC_ENTER,          _______,            _______,            _______
),


[MOVE] = LAYOUT_planck_grid(
    KC_TRAN,            KC_EXLM,            KC_LBRACKET,         KC_RBRACKET,         LSFT(KC_TAB),       _______,   KC_BOOT,            KC_PGUP,            KC_PGDOWN,         KC_ENTER,           KC_DELETE,          LSFT(KC_F10),
    KC_LCTRL,           LSFT(KC_LALT),      KC_LPRN,             KC_RPRN,             KC_TAB,             _______,   _______,            KC_LEFT,            KC_DOWN,           KC_UP,              KC_RIGHT,           KC_RCTRL,
    KC_LALT,            KC_TRAN,            KC_LCBR,             KC_RCBR,             KC_GRAVE,           _______,   _______,            KC_END,             KC_HOME,           KC_WBAK,            KC_WFWD,            KC_INSERT,
    _______,            _______,            KC_PRINT_SCREEN,     KC_TRAN,             KC_TRAN,            KC_TRAN,   KC_TRAN,            KC_TRAN,            KC_TRAN,           KC_NO,              _______,            _______
),

[NUMPAD] = LAYOUT_planck_grid(
    KC_BSPACE,           KC_ESCAPE,         KC_ENTER,            KC_COPY,             KC_PASTE,           _______,   _______,            KC_PLUS,            KC_7,              MT(MOD_RSFT, KC_8), KC_9,                KC_SLASH ,
    KC_LCTRL,            KC_LGUI,           KC_LSHIFT,           KC_GRAVE,            KC_CUT,             _______,   _______,            KC_MINUS,           KC_4,              KC_5,               KC_6,                MT(MOD_RCTL, KC_EQUAL),
    KC_LALT,             KC_NUMLOCK,        KC_TRAN,             KC_TRAN,             KC_GRAVE,           _______,   _______,            KC_COMMA,           KC_1,              KC_2,               KC_3,                KC_KP_DOT,
    _______,             _______,           _______,             KC_NUMLOCK,          KC_TRAN,            KC_TRAN,   KC_TRAN,            KC_TRAN,            KC_0,              _______,             _______,            _______
),
[MOUSE_F] = LAYOUT_planck_grid(
    KC_MS_WH_LEFT,       KC_MS_WH_DOWN,     KC_MS_UP,            KC_MS_WH_UP,         KC_MS_WH_RIGHT,     _______,   _______,            KC_F11,              KC_F7,               KC_F8,               KC_F9,               KC_F12,
    KC_MS_BTN1,          KC_MS_LEFT,        KC_MS_DOWN,          KC_MS_RIGHT,         RCTL(KC_RSHIFT),    _______,   _______,            KC_TRAN,             KC_F4,               KC_F5,               KC_F6,               KC_F10,
    KC_MS_BTN2,          KC_MS_BTN3,        KC_COPY,             KC_PASTE,            LCTL(KC_LSHIFT),    _______,   _______,            KC_TRAN,             KC_F1,               KC_F2,               KC_F3,               KC_TRAN,
    _______,             _______,           _______,             KC_TRAN,             KC_MS_BTN1,         KC_MS_BTN2,KC_MS_BTN1,         KC_MS_BTN2,          KC_MS_BTN1,          _______,             _______,             _______
),
[SYMB] = LAYOUT_planck_grid(
    KC_BSLASH,           KC_ESCAPE,           KC_ENTER,            KC_TRAN,            KC_TRAN,           _______,   _______,            KC_TRAN,             RSFT(KC_BSLASH),     KC_QUOTE,            KC_DQUO,             KC_BSLASH,
    KC_M_ALL,            KC_TRAN,             KC_TRAN,             KC_TRAN,            KC_TRAN,           _______,   _______,            KC_UNDS,             KC_ASTR,             KC_HASH,             KC_DLR,              KC_UNDS,
    RCTL(KC_Z),          KC_CUT,              KC_COPY,             KC_PASTE,           KC_TRAN,           _______,   _______,            KC_TRAN,             KC_TILD,             RSFT(KC_BSLASH),     KC_F4,               KC_EQUAL,
    _______,             _______,             _______,             KC_TRAN,            KC_TRAN,           KC_TRAN,   KC_TRAN,            KC_TRAN,             KC_TRAN,             _______,             _______,             _______
),
[OTHER] = LAYOUT_planck_grid(
    KC_VOLU,             SPK_MUTE,            KC_BRIU,             RGB_M_B,            RGB_TOG,           _______,   _______,            KC_NO,               KC_NO,               KC_NO,               KC_NO,               TG(GAMEM_L),
    KC_VOLD,             MIC_MUTE,            KC_BRID,             KC_NO,              KC_NO,             _______,   _______,            KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,
    KC_NO,               KC_NO,               KC_NO,               KC_NO,              KC_TRAN,           _______,   _______,            KC_TRAN,             KC_NO,               KC_NO,               KC_NO,               KC_NO,
    _______,             _______,             _______,             KC_TRAN,            KC_TRAN,           KC_TRAN,   KC_TRAN,            KC_TRAN,             KC_TRAN,             _______,             _______,             _______
),
[GAMEM_L] = LAYOUT_planck_grid(
    KC_ESC,              KC_Q,                KC_W,                KC_E,               KC_R,              KC_T,        _______,            KC_Y,                KC_U,              KC_I,               KC_O,               KC_P,
    KC_LCTRL,            KC_A,                KC_S,                KC_D,               KC_F,              KC_G,        _______,            KC_H,                KC_J,              KC_K,               KC_L,               KC_SCOLON,
    KC_LSHIFT,           KC_Z,                KC_X,                KC_C,               KC_V,              KC_B,        _______,            KC_N,                KC_M,              KC_COMM,            KC_DOT,             KC_SLASH,
    KC_LALT,             _______,             KC_TRAN,            OTHER,               KC_SPACE,          MO(GAMEM_R), KC_BSPACE,          LT(MOVE,KC_ENTER),   LT(OTHER,KC_TRAN), _______,            _______,            _______
),
[GAMEM_R] = LAYOUT_planck_grid(
    KC_1,                KC_2,                KC_3,                KC_4,                    KC_5,          _______,    TO(BASE),           KC_ESCAPE,           KC_TRAN,           KC_TRAN,            KC_TRAN,            TO(BASE),
    KC_6,                KC_7,                KC_8,                KC_9,                    KC_0,          _______,    _______,            KC_LEFT,             KC_DOWN,           KC_UP,              KC_RIGHT,           KC_TRAN,
    KC_LSHIFT,           KC_Z,                KC_X,                KC_C,                    KC_B,          _______,    _______,            KC_TRAN,             KC_TRAN,           KC_TRAN,            KC_TRAN,            KC_TRAN,
    _______,             _______,             _______,             KC_TRAN,                 KC_TRAN,       KC_TRAN,    KC_TRAN,            KC_TRAN,             KC_TRAN,           _______,            _______,            _______
),


/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/*[_ADJUST] = LAYOUT_planck_grid(*/
    /*_______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,*/
    /*_______, _______, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  PLOVER,  _______,*/
    /*_______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,*/
    /*_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______*/
/*)*/

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
            rgblight_sethsv_noeeprom(170, 255, 255);  // Max brightness blue
            break;
        case NUMPAD:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+0);
            rgblight_sethsv_noeeprom(85, 255, 255);   // Max brightness green
            break;
        case MOUSE_F:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+0);
            rgblight_sethsv_noeeprom(128, 255, 255);  // Max brightness cyan
            break;
        case SYMB:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+0);
            rgblight_sethsv_noeeprom(43, 255, 255);   // Max brightness gold
            break;
        case OTHER:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(213, 255, 255);  // Max brightness purple
            break;
        case GAMEM_L:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(0, 255, 255);  // Max brightness red
            break;
        case GAMEM_R:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+0);
            rgblight_sethsv_noeeprom(20, 255, 255); // Max brightness orange
            break;
        default:
            break;
    }
    return state;
};
#endif

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    // Boot sequence: brief color indication
    rgblight_enable();
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);

    // Flash green for 500ms to indicate successful boot
    rgblight_sethsv(HSV_GREEN);
    wait_ms(500);

    // Then turn off for normal BASE layer behavior
    rgblight_sethsv(HSV_OFF);
#endif
}

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

/*layer_state_t layer_state_set_user(layer_state_t state) {*/
  /*return update_tri_layer_state(state, BASE);*/
/*}*/

/*bool process_record_user(uint16_t keycode, keyrecord_t *record) {*/
/*  switch (keycode) {*/
/*    case QWERTY:*/
/*      if (record->event.pressed) {*/
/*        print("mode just switched to qwerty and this is a huge string\n");*/
/*        set_single_persistent_default_layer(_QWERTY);*/
/*      }*/
/*      return false;*/
/*      break;*/
/*    case COLEMAK:*/
/*      if (record->event.pressed) {*/
/*        set_single_persistent_default_layer(_COLEMAK);*/
/*      }*/
/*      return false;*/
/*      break;*/
/*    case DVORAK:*/
/*      if (record->event.pressed) {*/
/*        set_single_persistent_default_layer(_DVORAK);*/
/*      }*/
/*      return false;*/
/*      break;*/
/*    case BACKLIT:*/
/*      if (record->event.pressed) {*/
/*        register_code(KC_RSFT);*/
/*        #ifdef BACKLIGHT_ENABLE*/
/*          backlight_step();*/
/*        #endif*/
/*        #ifdef KEYBOARD_planck_rev5*/
/*          gpio_write_pin_low(E6);*/
/*        #endif*/
/*      } else {*/
/*        unregister_code(KC_RSFT);*/
/*        #ifdef KEYBOARD_planck_rev5*/
/*          gpio_write_pin_high(E6);*/
/*        #endif*/
/*      }*/
/*      return false;*/
/*      break;*/
/*    case PLOVER:*/
/*      if (record->event.pressed) {*/
/*        #ifdef AUDIO_ENABLE*/
/*          stop_all_notes();*/
/*          PLAY_SONG(plover_song);*/
/*        #endif*/
/*        layer_off(_RAISE);*/
/*        layer_off(_LOWER);*/
/*        layer_off(_ADJUST);*/
/*        layer_on(_PLOVER);*/
/*        if (!eeconfig_is_enabled()) {*/
/*            eeconfig_init();*/
/*        }*/
/*        keymap_config.raw = eeconfig_read_keymap();*/
/*        keymap_config.nkro = 1;*/
/*        eeconfig_update_keymap(keymap_config.raw);*/
/*      }*/
/*      return false;*/
/*      break;*/
/*    case EXT_PLV:*/
/*      if (record->event.pressed) {*/
/*        #ifdef AUDIO_ENABLE*/
/*          PLAY_SONG(plover_gb_song);*/
/*        #endif*/
/*        layer_off(_PLOVER);*/
/*      }*/
/*      return false;*/
/*      break;*/
/*  }*/
/*  return true;*/
/*}*/

/*bool muse_mode = false;*/
/*uint8_t last_muse_note = 0;*/
/*uint16_t muse_counter = 0;*/
/*uint8_t muse_offset = 70;*/
/*uint16_t muse_tempo = 50;*/

/*bool encoder_update_user(uint8_t index, bool clockwise) {*/
/*  if (muse_mode) {*/
/*    if (IS_LAYER_ON(_RAISE)) {*/
/*      if (clockwise) {*/
/*        muse_offset++;*/
/*      } else {*/
/*        muse_offset--;*/
/*      }*/
/*    } else {*/
/*      if (clockwise) {*/
/*        muse_tempo+=1;*/
/*      } else {*/
/*        muse_tempo-=1;*/
/*      }*/
/*    }*/
/*  } else {*/
/*    if (clockwise) {*/
/*      #ifdef MOUSEKEY_ENABLE*/
/*        tap_code(KC_MS_WH_DOWN);*/
/*      #else*/
/*        tap_code(KC_PGDN);*/
/*      #endif*/
/*    } else {*/
/*      #ifdef MOUSEKEY_ENABLE*/
/*        tap_code(KC_MS_WH_UP);*/
/*      #else*/
/*        tap_code(KC_PGUP);*/
/*      #endif*/
/*    }*/
/*  }*/
/*    return true;*/
/*}*/

/*bool dip_switch_update_user(uint8_t index, bool active) {*/
/*    switch (index) {*/
/*        case 0: {*/
/*#ifdef AUDIO_ENABLE*/
/*            static bool play_sound = false;*/
/*#endif*/
/*            if (active) {*/
/*#ifdef AUDIO_ENABLE*/
/*                if (play_sound) { PLAY_SONG(plover_song); }*/
/*#endif*/
/*                layer_on(_ADJUST);*/
/*            } else {*/
/*#ifdef AUDIO_ENABLE*/
/*                if (play_sound) { PLAY_SONG(plover_gb_song); }*/
/*#endif*/
/*                layer_off(_ADJUST);*/
/*            }*/
/*#ifdef AUDIO_ENABLE*/
/*            play_sound = true;*/
/*#endif*/
/*            break;*/
/*        }*/
/*        case 1:*/
/*            if (active) {*/
/*                muse_mode = true;*/
/*            } else {*/
/*                muse_mode = false;*/
/*            }*/
/*    }*/
/*    return true;*/
/*}*/

/*void matrix_scan_user(void) {*/
/*#ifdef AUDIO_ENABLE*/
/*    if (muse_mode) {*/
/*        if (muse_counter == 0) {*/
/*            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];*/
/*            if (muse_note != last_muse_note) {*/
/*                stop_note(compute_freq_for_midi_note(last_muse_note));*/
/*                play_note(compute_freq_for_midi_note(muse_note), 0xF);*/
/*                last_muse_note = muse_note;*/
/*            }*/
/*        }*/
/*        muse_counter = (muse_counter + 1) % muse_tempo;*/
/*    } else {*/
/*        if (muse_counter) {*/
/*            stop_all_notes();*/
/*            muse_counter = 0;*/
/*        }*/
/*    }*/
/*#endif*/
/*}*/

/*bool music_mask_user(uint16_t keycode) {*/
/*  switch (keycode) {*/
/*    case RAISE:*/
/*    case LOWER:*/
/*      return false;*/
/*    default:*/
/*      return true;*/
/*  }*/
/*}*/
