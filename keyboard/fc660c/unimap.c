#include "action.h"
#include "actionmap.h"
#include "hook.h"
#include "fc660c.h"

#define AC_L2		ACTION_LAYER_MOMENTARY(2)
#define AC_L3       ACTION_LAYER_MOMENTARY(3)
#define AC_L4       ACTION_LAYER_MOMENTARY(4)
#define AC_L7       ACTION_LAYER_MOMENTARY(7)
#define AC_LS_2     ACTION_LAYER_MODS(2, MOD_LSFT)
#define AC_RS_1     ACTION_LAYER_MODS(1, MOD_RSFT)
#define AC_RS_2     ACTION_LAYER_MODS(2, MOD_RSFT)
#define AC_TGL1     ACTION_LAYER_TOGGLE(1)
#define AC_SLS6     ACTION_LAYER_TAP_KEY(6, KC_SLSH)
#define AC_LALT3	ACTION_LAYER_MODS(3, MOD_LALT)
#define AC_LALT7	ACTION_LAYER_MODS(7, MOD_LALT)

#define AC_BACK     ACTION_MODS_KEY(MOD_LALT, KC_LEFT)
#define AC_FRWD     ACTION_MODS_KEY(MOD_LALT, KC_RIGHT)
#define AC_CTLF5	ACTION_MODS_TAP_KEY(MOD_LCTL, KC_F5)
#define AC_CTLBS	ACTION_MODS_TAP_KEY(MOD_RCTL, KC_BSPC)

// TODO try action mods tap key here without going to layer 5
#define AC_SPC5     ACTION_LAYER_TAP_KEY(5, KC_SPC)

/*TODO Change these to function actions, keeping in case I was wrong
#define AC_SH_9		ACTION_MODS_TAP_KEY(MOD_LSFT, KC_9)
#define AC_SH_0		ACTION_MODS_TAP_KEY(MOD_LSFT, KC_0)
#define AC_SH_MINS	ACTION_MODS_TAP_KEY(MOD_LSFT, KC_MINS)
#define AC_SH_EQL	ACTION_MODS_TAP_KEY(MOD_LSFT, KC_EQL)
#define AC_SH_LBRC	ACTION_MODS_TAP_KEY(MOD_LSFT, KC_LBRC)
#define AC_SH_RBRC	ACTION_MODS_TAP_KEY(MOD_LSFT, KC_RBRC)
#define AC_SH_BSLS	ACTION_MODS_TAP_KEY(MOD_LSFT, KC_BSLS)
#define AC_SH_SCLN	ACTION_MODS_TAP_KEY(MOD_LSFT, KC_SCLN)
#define AC_SH_QUOT	ACTION_MODS_TAP_KEY(MOD_LSFT, KC_QUOT)
#define AC_SH_COMM	ACTION_MODS_TAP_KEY(MOD_LSFT, KC_COMM)
#define AC_SH_DOT	ACTION_MODS_TAP_KEY(MOD_LSFT, KC_DOT)
#define AC_SH_SLSH	ACTION_MODS_TAP_KEY(MOD_LSFT, KC_SLSH)*/

#define AC_ALT_TAB	ACTION_MACRO(1)
#define AC_HELLO	ACTION_MACRO(2)
#define AC_PLYPS	ACTION_MACRO(3)

#define AC_FN0		ACTION_FUNCTION(0)
#define AC_FN1		ACTION_FUNCTION(1)
#define AC_FN2		ACTION_FUNCTION(2)
//TODO Try function actions for Shift+brackets etc again

// Keymaps are a mixture of Hasu's 660c keymaps, stock 660c, and me
#ifdef KEYMAP_SECTION_ENABLE
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] PROGMEM = {
#endif
    [0] = KMAP( \
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     HOME,
        TAB,  Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     DEL,
        CTLF5,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,
        LS_2, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,      RS_2,UP,
        LCTL, LGUI,LALT7,          SPC,                 L7,RCTL,L3,LEFT,DOWN,RGHT
    ),
	// Default/same as layer0, except Insert LED on and spacebar behavior changed
    [1] = KMAP(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     HOME,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     DEL,
        CTLF5,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,
        LS_2,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,         RS_2,UP,
        LCTL, LGUI,LALT7,          SPC5,              L7,RCTL,L3,  LEFT,DOWN,RGHT
    ),
	// Just for shift+esc to make grave, everything else falls through to default layers (0 and 1)
    [2] = KMAP(
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS
    ),
	// Holding Fn takes us here
    [3] = KMAP(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, FN2,    FN0,
        TAB,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,TRNS,TRNS,TRNS,     TRNS,
        FN1,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,HOME,PGUP,TRNS,TRNS,     TRNS,
        TRNS,MUTE,VOLD,VOLU,TRNS,TRNS,TRNS,TRNS,END, PGDN,TRNS,          TRNS,PGUP,
        L3,  TRNS,TRNS,          TRNS,                    TRNS,APP, L3,  HOME,PGDN,END
    ),
	// TODO: Can we even get here? Remove this layer if not..
    [4] = KMAP(
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,     TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,TRNS,TRNS,HOME,PGUP,TRNS,TRNS,     TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,END, PGDN,TRNS,          TRNS,PGUP,
        L4,  TRNS,TRNS,          TRNS,                    TRNS,APP, L4,  HOME,PGDN,END
    ),
	// Holding spacebar while in layer 1 brings us here
    [5] = KMAP(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  TRNS,  TRNS, TRNS, TRNS, FN2,      TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,         TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,        PGUP,
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,HOME,PGDN,END
    ),
	// Using Lalt + keys besides volume controls will fall through to this default map
    [6] = KMAP( \
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     HOME,
        TAB,  Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     DEL,
        CTLF5,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,
        LS_2, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,      RS_2,UP,
        LCTL, LGUI,LALT3,          SPC,                 L7,RCTL,L3,LEFT,DOWN,RGHT
    ),
	// Right alt takes you here for media controls
	[7] = KMAP(
        TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
        TRNS,MUTE,VOLD,VOLU,TRNS,TRNS,TRNS,TRNS,MPRV,MNXT,MPLY,          TRNS,TRNS,
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS
    ),
};

// Saved for later mouse control layer in case we want it back
// [5] = KMAP(
//        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, GRV,      TRNS,
//       TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,WH_L,WH_D,MS_U,WH_U,WH_R,BTN4,BTN5,TRNS,     TRNS,
//        TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,TRNS,MS_L,MS_D,MS_R,BTN1,TRNS,     TRNS,
//       TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN2,BTN1,BACK,FRWD,TRNS,          TRNS,PGUP,
//       TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,HOME,PGDN,END
//   ),

// Not using now but leaving here to remember how to do it...
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case 2:
            return (record->event.pressed ?
                    MACRO( I(0), T(H), T(E), T(L), T(L), W(255), T(O), END ) :
                    MACRO_NONE );
        case 1:
            return (record->event.pressed ?
                    MACRO( D(LALT), D(TAB), END ) :
                    MACRO( U(TAB), END ));
		case 3:
			return (record->event.pressed ?
					MACRO( CM(), T(MEDIA_PLAY_PAUSE), END ) :
					MACRO_NONE );
		case 4:
			return (record->event.pressed ?
					MACRO( D(RCTL), T(BSPC), U(RCTL), END ) :
					MACRO_NONE );
    }
    return MACRO_NONE;
}

/* id for user defined functions, don't have to define if it's not a custom function action */
enum function_id {
    INS_TGL_1,
	CAPS_W_LED,
	CTL_BSPC
};

// Use function actions somehow to create Fn+Ins = Ins + Toggle Layer 1
/*
 * Fn action definition, use on keymap as FN0 FN1 etc, not the same as F1 F2 etc
 */
#ifdef KEYMAP_SECTION_ENABLE
const action_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const action_t fn_actions[] PROGMEM = {
#endif
//    [0] = ACTION_DEFAULT_LAYER_SET(0),                // Default layer(not used)
//    [1] = ACTION_LAYER_TAP_TOGGLE(1),                 // HHKB layer(toggle with 5 taps)
//    [2] = ACTION_LAYER_TAP_KEY(2, KC_SLASH),          // Cursor layer with Slash*
//    [3] = ACTION_LAYER_TAP_KEY(3, KC_SCLN),           // Mousekey layer with Semicolon*
//    [4] = ACTION_LAYER_TAP_KEY(4, KC_SPC),            // Mousekey layer with Space
//    [5] = ACTION_LAYER_MOMENTARY(4),                  // Mousekey layer(IJKL)
//    [6] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT),      // RControl with tap Enter
//    [7] = ACTION_MODS_ONESHOT(MOD_LSFT),              // Oneshot Shift
//    [8] = ACTION_MACRO(ALT_TAB),                      // Application switching
//    [9] = ACTION_MODS_KEY(MOD_LALT, KC_LEFT),
//   [10] = ACTION_MODS_KEY(MOD_LALT, KC_RIGHT),

//  [x] = ACTION_LMOD_TAP_KEY(KC_LCTL, KC_BSPC),        // LControl with tap Backspace
//  [x] = ACTION_LMOD_TAP_KEY(KC_LCTL, KC_ESC),         // LControl with tap Esc
    [0] = ACTION_FUNCTION(INS_TGL_1),	       	    	// Function: Hit Ins and toggle layer 1
	[1] = ACTION_FUNCTION(CAPS_W_LED),					// Function: Toggle Caps Lock and Caps Lock LED
	[2] = ACTION_MODS_KEY(MOD_RCTL, KC_BSPC),			// Macro: Hold Rctl and tap Backspace
	
//  [x] = ACTION_MACRO(HELLO),                          // Macro: say hello
//  [x] = ACTION_MACRO(VOLUP),                          // Macro: media key
};

// Attempt to create a variable to hold LED on/off status
bool my_led_status = 0;

/*
 * user defined action function
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    //if (record->event.pressed) dprint("P"); else dprint("R");
    //dprintf("%d", record->tap.count);
    //if (record->tap.interrupted) dprint("i");
    //dprint("\n");

    switch (id) {
        case INS_TGL_1:
            // If the key we assigned this to is pressed
            if (record->event.pressed) {
                // Press Ins key once
				register_code(KC_INS);
                unregister_code(KC_INS);
                send_keyboard_report();
				// Toggle layer 1, (if on turn off, if off turn on)
				layer_invert(1);
				break;
            } else {
			}
		case CAPS_W_LED:
			// If the key we assigned this to is pressed
			if (record->event.pressed) {
				// Press CapsLock key once
				register_code(KC_CAPS);
				unregister_code(KC_CAPS);
				send_keyboard_report();
				// Toggle CapsLock LED (if on turn off, if off turn on)
				// If my_led_status still = 0 then this will be true
				if (my_led_status) {
					// LED is off, turn it on
					DDRB &= ~(1<<5);
					// Set my_led_status to 1 to indicate LED is on
					my_led_status = 1;
				} else {
					// LED is on, turn if off
					DDRB |=  (1<<5);
					// Set my_led_status back to 0 to indicate LED is off
					my_led_status = 0;
					break;
				}
			}
		case CTL_BSPC:
            // If the key we assigned this to is pressed
            if (record->event.pressed) {
                // Press RCTL+BSPC
				register_code(KC_RCTL);
				register_code(KC_BSPC);
				send_keyboard_report();
				unregister_code(KC_RCTL);
				unregister_code(KC_BSPC);
                send_keyboard_report();
				break;
            }
    }
}


// Turn on LED if Layer 1 is enabled
void hook_layer_change(uint32_t layer_state)
{
    // If layer 1 is enabled
    if (layer_state & (1L<<1)) {
		// Ins LED On
        PORTB &= ~(1<<5);
    } else {
		// Ins LED Off
        PORTB |=  (1<<5);
    }
}
