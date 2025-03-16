#define TAPPING_TERM_PER_KEY // Turn on custom tapping term per key. Needed to slow down the rotary media button

#define COMBO_TERM 22 // How quickly all combo keys must be pressed to register a combo
#define COMBO_MUST_HOLD_MODS // Makes it so that you must hold down the modifier keys for combos to register
#define COMBO_HOLD_TERM 175 // How long you must hold down the modifier keys for combos to register

// Set ESC to trigger bootmagic when held + turning on keyboard
#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 0

// Custom mouse key settings for smoother movement (inspired by Miroyku config)
#define MK_KINETIC_SPEED  
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY	5
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 10
#define MOUSEKEY_MOVE_DELTA 20
#define MOUSEKEY_INITIAL_SPEED 600
#define MOUSEKEY_BASE_SPEED 3000
#define MOUSEKEY_DECELERATED_SPEED	650
#define MOUSEKEY_ACCELERATED_SPEED	1800
#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS	16
#define MOUSEKEY_WHEEL_BASE_MOVEMENTS	32
#define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS	48
#define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS	8
