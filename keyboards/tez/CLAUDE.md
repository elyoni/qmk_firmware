# Tez V3 — "Travel Easy" Keyboard

Custom split keyboard designed and maintained by Yehonatan Elentok.

## Hardware

- **MCU**: ATmega32u4, bootloader: Caterina (Arduino-compatible)
- **Split**: Serial protocol over D1, USB-detect auto-routes to the connected side
- **RGB**: 4 LEDs per half (WS2812 on B5), split sync enabled
- **Layout**: 3×5 column-staggered + 3-key thumb cluster per hand (46 keys total)

## Build & Flash

```bash
# Compile
qmk compile -kb tez -km default

# Flash (put keyboard in bootloader mode first: double-tap reset, or QK_BOOTLOADER key in OTHER layer)
qmk flash -kb tez -km default
```

The `QK_BOOTLOADER` key is in the **OTHER** layer (see layout below). Flash each half separately.

## Layer Overview

| Layer    | Activated by                          | Purpose                          |
|----------|---------------------------------------|----------------------------------|
| BASE     | Default                               | QWERTY with home-row mods        |
| MOVE     | Hold right-middle thumb (`MO(MOVE)`)  | Navigation, brackets, tab        |
| NUMPAD   | Hold Space or F (`LT(NUMPAD,…)`)      | Numbers, symbols, mouse buttons  |
| MOUSE_F  | Hold `/` (`LT(MOUSE_F,…)`)           | Mouse movement + F-keys          |
| SYMB     | Hold V or Backspace (`LT(SYMB,…)`)   | Symbols (underscore, hash, etc.) |
| OTHER    | Hold left-outer thumb (`MO(OTHER)`)  | Volume, brightness, RGB, bootloader, Hebrew toggle |
| GAMEM_L  | Toggle via OTHER layer                | Gaming left hand (no mod-taps)   |
| GAMEM_R  | Hold right-middle thumb in GAMEM_L   | Gaming numbers + movement        |

### Base Layer (QWERTY + home-row mods)

```
Q          W          E          R          T               Y          U          I          O          Alt(P)
Ctrl(A)    Gui(S)     Shift(D)   Numpad(F)  G               H          J          Shift(K)   Gui(L)     Ctrl(;)
Alt(Z)     X          C          Symb(V)    B               N          M          ,          .          MouseF(/)
                      OTHER      Numpad(Spc) LShift          Symb(Bspc) MOVE       Enter
```

### MOVE Layer (right thumb hold)

```
-          !          [          ]          S-Tab           PgUp       PgDn       Enter      Del        S-F10
Ctrl       S-Alt      (          )          Tab             Left       Down       Up         Right      Ctrl(Enter)
Alt        -          {          }          `               Home       End        WBack      WFwd       Insert
                      PrtScr     -          -               -          -          -
```

### NUMPAD Layer (Space or F hold)

```
Bspc       Esc        MouseBtn1  MouseBtn2  -               +          7          8          9          /
Ctrl       Gui        Shift      `          Enter           -          4          5          6          Ctrl(=)
Alt        NumLock    F13        -          `               ,          1          2          3          KP_Dot
                      NumLock    -          -               -          -          0
```

### MOUSE_F Layer (/ hold)

```
WhlLeft    WhlDown    MsUp       WhlUp      WhlRight        F11        F7         F8         F9         F12
MsBtn1     MsLeft     MsDown     MsRight    Ctrl+Shift      -          F4         F5         F6         F10
MsBtn2     MsBtn3     Copy       Paste      Ctrl+Shift      -          F1         F2         F3         -
                      -          MsBtn1     MsBtn2          MsBtn1     MsBtn2     MsBtn1
```

### SYMB Layer (V or Backspace hold)

```
-          -          -          -          -               -          |          '          "          \
SelectAll  -          -          -          -               _          *          #          $          _
Ctrl+Z     -          -          Paste      -               -          ~          |          F4         =
                      -          -          -               -          -          -
```

### OTHER Layer (left-outer thumb hold)

```
VolUp      SpkMute    BriUp      RGB_Breathe RGB_Plain      BOOTLOADER -          -          -          TG(GAMEM_L)
VolDn      MicMute    BriDn      -          -               -          -          -          -          -
-          -          -          -          HebrewToggle    -          -          -          -          -
                      -          -          -               -          -          -
```

## Design Decisions

### Home-row mods
Mods live on the home row: `Ctrl/A`, `Gui/S`, `Shift/D`, `Shift/K`, `Gui/L`, `Ctrl/;`.
`Alt` is on `Z` and `P` (outer positions, same hand).

### Tapping term
Global tapping term is **150ms** (set in `keyboard.json`).
`LT(NUMPAD, KC_SPACE)` and `LT(NUMPAD, KC_F)` are overridden to **300ms** in `get_tapping_term`.

**Why 300ms for NUMPAD keys:** During fast typing, Space or F would briefly activate NUMPAD and corrupt the next keypress. The longer threshold gives a clear intent signal.

**Side-effect:** Accessing NUMPAD layer intentionally (e.g. Space+W for ESC) requires holding Space for 300ms before the layer is active. This feels slow. A per-combo workaround is tracked below.

### HOLD_ON_OTHER_KEY_PRESS — disabled for most LT keys
`config.h` defines both `HOLD_ON_OTHER_KEY_PRESS` and `HOLD_ON_OTHER_KEY_PRESS_PER_KEY`.
`get_hold_on_other_key_press` returns `true` **only** for `LT(SYMB, KC_BSPACE)`.
All other LT keys (including NUMPAD/Space and NUMPAD/F) return `false`.

**Why:** Enabling it globally caused wrong keys during fast typing — the hold layer would activate from normal key-overlap and corrupt output.

**Rule:** Do not add new keys to `get_hold_on_other_key_press` unless the LT key is on a thumb or non-typing position where false triggers are unlikely.

### Combos — currently disabled
`COMBO_ENABLE = no` in `keymaps/default/rules.mk`.
The original combo `J+F → ESC` was removed because it triggered accidentally during normal typing.

**Pending:** A `Space+W → ESC` combo with a short per-combo term (~50ms) is planned as a safer replacement — it requires true simultaneous press, avoiding the 300ms NUMPAD hold wait.

### RGB feedback per layer
`layer_state_set_user` sets LED color/mode for each layer:

| Layer   | Color          | Mode      |
|---------|----------------|-----------|
| BASE    | Off            | Static    |
| MOVE    | Dim blue       | Breathing |
| NUMPAD  | Dim green      | Breathing |
| MOUSE_F | Dim cyan       | Breathing |
| SYMB    | Dim gold       | Breathing |
| OTHER   | Dim purple     | Static    |
| GAMEM_L | Bright red     | Static    |
| GAMEM_R | Bright orange  | Breathing |

### Special keycodes
| Keycode        | Expands to                  | Notes                        |
|----------------|-----------------------------|------------------------------|
| `MIC_MUTE`     | `KC_F20`                    | System mic mute (OS handles) |
| `SPK_MUTE`     | `KC_MUTE`                   | Standard media mute          |
| `HEBREW_TOGGLE`| Custom (`process_record_user`) | Toggles Hebrew input mode, sets orange LED |
| `KC_CH_LNG`    | `LAlt+LShift`               | Language switch shortcut      |
| `KC_COPY/PASTE/CUT` | Ctrl+C/V/X             | Redefined over QMK defaults  |
