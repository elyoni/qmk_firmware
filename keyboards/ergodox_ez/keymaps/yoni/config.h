#pragma once

// Mirrors keyboards/tez: 150ms tapping term, permissive hold (per-key overrides)
#undef TAPPING_TERM
#define TAPPING_TERM 150
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

// Make layer-tap keys activate immediately when another key is pressed
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Enable per-key tapping term configuration
#define TAPPING_TERM_PER_KEY
