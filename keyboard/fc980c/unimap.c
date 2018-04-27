#include "action.h"
#include "actionmap.h"
#include "hook.h"
#include "fc980c.h"


#define AC_L1       ACTION_LAYER_MOMENTARY(1)
#define AC_LALT1	ACTION_LAYER_MODS(1, MOD_LALT)
#define AC_PGDN1    ACTION_LAYER_TAP_KEY(1, KC_PGDN)
#define AC_MACR1	ACTION_MACRO(1)
#define AC_MACR2	ACTION_MACRO(2)
#define AC_MACR3	ACTION_MACRO(3)
#define AC_MACR4	ACTION_MACRO(4)
#define AC_MACR5	ACTION_MACRO(5)

#ifdef KEYMAP_SECTION_ENABLE
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] PROGMEM = {
#endif
    [0] = KMAP(
        ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,                         DEL, INS, MACR3,L1,
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,                        NLCK,PSLS,PAST,PMNS,
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,                        P7,  P8,  P9,  PPLS,
        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,                         P4,  P5,  P6,
        LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,          UP,           P1,  P2,  P3,  PENT,
        LCTL,LGUI,LALT1,              SPC,                     RALT,RCTL,L1,       LEFT,DOWN,RGHT,         P0,  PDOT
    ),
    [1] = KMAP(
        TRNS,     MACR5,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,                       TRNS,TRNS,MACR1,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,MACR4,                      TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,TRNS,TRNS,TRNS,                       TRNS,TRNS,TRNS,TRNS,
        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,                       TRNS,MACR2,TRNS,
        TRNS,     MUTE,VOLD,VOLU,TRNS,TRNS,TRNS,TRNS,MPRV,MNXT,MPLY,     TRNS,          PGUP,        TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,               TRNS,                    TRNS,APP, TRNS,     HOME,PGDN,END,         TRNS,TRNS
    ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
		// Go to desktop, then Sleep
        case 1:
            return (record->event.pressed ?
                    MACRO( D(LGUI), T(D), W(200), U(LGUI), W(200), D(LGUI), T(X), W(200), U(LGUI), W(200), T(U), W(200), T(S), END ) :
                    MACRO_NONE );
        
		// Case 2 removed for sharing
			
		// Take a screenshot
		case 3:
            return (record->event.pressed ?
                    MACRO( D(LGUI), T(PSCR), U(LGUI), END ) :
                    MACRO_NONE );
					
		// Ctrl + Backspace for deleting whole words
		case 4:
            return (record->event.pressed ?
                    MACRO( D(RCTL), T(BSPC), U(RCTL), END ) :
                    MACRO_NONE );
					
		// Premade method template
		case 5:
            return (record->event.pressed ?
                    MACRO( T(P), T(U), T(B), T(L), T(I), T(C), 
					T(SPC), T(V), T(O), T(I), T(D), T(SPC), 
					T(M), T(E), T(T), T(H), T(O), T(D), D(LSFT), T(T), U(LSFT), T(E), T(M), T(P), T(L), T(A), T(T), T(E), 
					D(LSFT), T(9), T(0), U(LSFT), T(SPC), D(LSFT), T(LBRC), U(LSFT),
					T(ENT), END ) :
                    MACRO_NONE );
        
    }
    return MACRO_NONE;
}