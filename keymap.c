    #include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#include "keymap_german.h"

#include "keymap_nordic.h"

// Layers Enum
enum {
  BASE = 0,
  ARRW
};

enum {
  TD_LB_P,
  TD_RB_P,
  TD_SQ_DQ,
  TD_SLSH_QUES,
  TD_SCOLON_COLN,
  TD_EQL_PLUS,
  TD_GRV_TILD
};


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN, 
  RGB_SLD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Base Layer
   *
   * ,-----------------------------------------------------.           ,-----------------------------------------------------.
   * | Esc       |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |  0   |    -      |
   * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
   * | Tab/ARRW  |   Q  |   W  |   E  |   R  |   T  |  /   |           |  =   |   Y  |   U  |   I  |   O  |  P   |    \      |
   * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
   * | Ctrl/Esc  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |    '      |
   * |-----------+------+------+------+------+------|  [   |           |   ]  |------+------+------+------+------+-----------|
   * | Shift     |   Z  |   X  |   C  |   V  |   B  |  (   |           |   )  |   N  |   M  |   ,  |  .   |  UP  |   Shift   |
   * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
   *     | ARRW  |      |      | LALT | LGUI |                                       |      |      | LEFT | DOWN | RIGHT |
   *     `-----------------------------------'                                       `-----------------------------------'
   *                                         ,-------------.           ,-------------.
   *                                         | ARRW |      |           |   F6 |  F7  |
   *                                  ,------|------|------|           |------+------+------.
   *                                  |      |      |      |           |   F8 |      |      |
   *                                  |Space |BSPACE|------|           |------| Enter| Space|
   *                                  |      |      |  DEL |           |      |      |      |
   *                                  `--------------------'           `--------------------'
   */

  [BASE] = KEYMAP(
    // Left Hand
    KC_GRV,               KC_1,     KC_2,     KC_3,     KC_4,      KC_5, KC_TRNS, 
    LT(ARRW, KC_TAB),     KC_Q,     KC_W,     KC_E,     KC_R,      KC_T, TD(TD_SLSH_QUES),
    MT(MOD_LCTL, KC_ESC), KC_A,     KC_S,     KC_D,     KC_F,      KC_G,
    OSM(MOD_LSFT),        KC_Z,     KC_X,     KC_C,     KC_V,      KC_B, TD(TD_LB_P), 
    KC_TRNS,              KC_TRNS,  KC_TRNS,  KC_LALT,  KC_LGUI,
          
    TT(ARRW), KC_TRNS,
              KC_TRNS,  
    KC_SPACE, KC_BSPACE, KC_DEL,

    // Right Hand
    KC_MINS,         KC_6,     KC_7,     KC_8,     KC_9,    KC_0,               KC_MINS,
    TD(TD_EQL_PLUS), KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,               KC_BSLASH,
                     KC_H,     KC_J,     KC_K,     KC_L,    TD(TD_SCOLON_COLN), TD(TD_SQ_DQ),
    TD(TD_RB_P),     KC_N,     KC_M,     KC_COMMA, KC_DOT,  KC_UP,              OSM(MOD_RSFT),
                               KC_TRNS,  KC_TRNS,  KC_LEFT, KC_DOWN,            KC_RIGHT,   

    KC_F6, KC_F7,  
    KC_F8,  
    KC_TRNS, KC_TRNS, KC_ENTER
  ),

  
  /* Keymap 1: Arrow Layer
   *
   * ,-----------------------------------------------------.           ,-----------------------------------------------------.
   * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
   * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
   * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
   * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
   * |           |      |      |      |      |      |------|           |------| Left | Down | Up   | Left |      |           |
   * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
   * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
   * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
   *     |       |      |      |      |      |                                       |      |      |      |      |       |
   *     `-----------------------------------'                                       `-----------------------------------'
   *                                         ,-------------.           ,-------------.
   *                                         |      |      |           |      |      |
   *                                  ,------|------|------|           |------+------+------.
   *                                  |      |      |      |           |      |      |      |
   *                                  |      |      |------|           |------|      |      |
   *                                  |      |      |      |           |      |      |      |
   *                                  `--------------------'           `--------------------'
   */
  [ARRW] = KEYMAP(
    // Left Hand
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, 
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  

    KC_TRNS,  KC_TRNS,  
              KC_TRNS,  
    KC_TRNS,  KC_TRNS,  KC_TRNS,  

    // Right Hand
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_UP,    KC_TRNS,  KC_TRNS,  KC_TRNS,  
    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_TRNS,  KC_TRNS,  
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  

    KC_TRNS,  KC_TRNS,  
    KC_TRNS,  
    KC_TRNS,  KC_TRNS,  KC_TRNS) , 

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LB_P]        = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LPRN),
  [TD_RB_P]        = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RPRN),
  [TD_SQ_DQ]       = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
  [TD_SLSH_QUES]   = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_QUES), 
  [TD_SCOLON_COLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCOLON, KC_COLN),
  [TD_EQL_PLUS]    = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_PLUS)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record,  uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
    
  }
  return true;
}

void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

};
