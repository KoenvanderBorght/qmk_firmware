#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum custom_keycodes
{
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
};

#define ______ KC_TRANSPARENT

//docker run -e keymap=koenvdb -e subproject=default -e keyboard=ergodox --rm -v C:/Users/KoenvanderBorghtGomo/Documents/dev/qmk:/qmk:rw edasque/qmk_firmware
//http://configure.ergodox-ez.com/keyboard_layouts/qvjvye/edit
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /* Keymap 0: Basic layer
 * 
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  | Cut  |           |CTLWIND|   6 |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  | Copy |           |CTLWINR|   Y |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |       |-----+------+------+------+------+--------|
 * |   L3   |   A  |   S  |   D  |   F  |   G  |------|           |----- -|   H |   J  |   K  |   L  |   ;  |' / Cmd |
 * |--------+------+------+------+------+------| Paste|           |CTLWINL|-----+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |       |   N |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | OSL4 | NTab | PTab | TL2 | MOML2 |                                       |  MOML1| TL1 |ALTSHIFTF|ALTF4| F12|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | TAB  |AltINS|       |  -   |   *  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | LGUI |       |  +   |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | ALT  |       |  =   |        |      |
 *                                 `--------------------'       `----------------------'
 */
        // If it accepts an argument (i.e, is a function), it doesn't need KC_.
        // Otherwise, it needs KC_*
        [0] = KEYMAP(
          //Left hand
          KC_ESCAPE,                KC_1,                  KC_2,             KC_3,               KC_4,                     KC_5,                    LCTL(KC_X), 
          KC_DELETE,                KC_Q,                  KC_W,             KC_E,               KC_R,                     KC_T,                    LCTL(KC_C), 
          MO(3),                    KC_A,                  KC_S,             KC_D,               KC_F,                     KC_G,
          KC_LSHIFT,                CTL_T(KC_Z),           KC_X,             KC_C,               KC_V,                     KC_B,                    LCTL(KC_V), 
          OSL(4),                   LCTL(LSFT(KC_TAB)),    LCTL(KC_TAB),     TG(2),              MO(2), 
                                                                             KC_TAB,             ALT_T(KC_INSERT), 
                                                                                                 KC_LGUI, 
                                                           CTL_T(KC_SPACE),  ALT_T(KC_BSPACE),   KC_LALT,   

          //Right hand                                        
          LCTL(LGUI(KC_D)),         KC_6,                  KC_7,             KC_8,               KC_9,                     KC_0,                    KC_MINUS, 
          LCTL(LGUI(KC_RIGHT)),     KC_Y,                  KC_U,             KC_I,               KC_O,                     KC_P,                    KC_BSLASH, 
                                    KC_H,                  KC_J,             KC_K,               KC_L,                     KC_SCOLON,               KC_QUOTE, 
          LCTL(LGUI(KC_LEFT)),      KC_N,                  KC_M,             KC_COMMA,           KC_DOT,                   KC_SLASH,                KC_LSHIFT, 
          MO(1),                    TG(1),                 LALT(LSFT(KC_F)), LALT(KC_F4),        KC_F12, 
          KC_KP_MINUS,              KC_KP_ASTERISK, 
          KC_KP_PLUS,               
          KC_EQUAL,                 KC_TAB,                KC_ENTER),

/* Keymap 1: Mouse movements and media controls
 * 
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |   F7  |  F8 |  F9  | F10  | F11  | F12  |  PLAY  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |      |      | M_UP |      |      | Copy |           |CTLWINR|     |      |SCRLUP| PREV | NEXT | VOLUP  |
 * |--------+------+------+------+------+------|      |           |       |-----+------+------+------+------+--------|
 * |   L3   |      |M_LEFT|M_DOWN|M_RIGH|      |------|           |----- -|     |SCRLLE|SCRLDN|SCRLRI|      | VOLDWN |
 * |--------+------+------+------+------+------| Paste|           |CTLWINL|-----+------+------+------+------+--------|
 * | LShift |      |      |      |      |      |      |           |       |     |      |      |      |      |  MUTE  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | OSL4 | NTab | PTab | TL2 | MOML2 |                                       |  MOML1| TL1 |ALTSHIFTF|ALTF4| F12|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | TAB  | LCTL |       |  -   |   *  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | LGUI |       |  +   |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | ALT  |       |  =   |        |      |
 *                                 `--------------------'       `----------------------'
 */
        [1] = KEYMAP(
          //Left hand
          ______,                   KC_F1,                 KC_F2,            KC_F3,              KC_F4,                    KC_F5,                   KC_F6,
          ______,                   ______,                ______,           KC_MS_UP,           ______,                   ______,                  ______, 
          ______,                   ______,                KC_MS_LEFT,       KC_MS_DOWN,         KC_MS_RIGHT,              ______,  
          ______,                   ______,                ______,           ______,             ______,                   ______,                  ______, 
          ______,                   ______,                ______,           ______,             ______, 
                                                                             ______,             ______, 
                                                                                                 ______, 
                                                           KC_MS_BTN1,       KC_MS_BTN2,         ______, 
          
          //Right hand
          KC_F7,                    KC_F8,                 KC_F9,            KC_F10,             KC_F11,                KC_F12,                  KC_MEDIA_PLAY_PAUSE,
          ______,                   ______,                ______,           KC_MS_WH_UP,        KC_MEDIA_PREV_TRACK,   KC_MEDIA_NEXT_TRACK,     KC_AUDIO_VOL_UP, 
                                    ______,                KC_MS_WH_LEFT,    KC_MS_WH_DOWN,      KC_MS_WH_RIGHT,        ______,                  KC_AUDIO_VOL_DOWN, 
          ______,                   ______,                KC_MS_ACCEL0,     KC_MS_ACCEL1,       KC_MS_ACCEL2,          ______,                  KC_AUDIO_MUTE,
          ______,                   ______,                ______,           ______,             ______, 
          ______,                   ______,
          ______, 
          ______,                   ______,                ______),

        [2] = KEYMAP(
          //Left hand
          RESET,                    ______,                ______,           ______,             ______,                ______,                  ______,
          ______,                   ______,                ______,           ______,             ______,                ______,                  ______,
          ______,                   ______,                ______,           ______,             ______,                ______,                  
          ______,                   ______,                ______,           ______,             ______,                ______,                  ______,
          ______,                   ______,                ______,           ______,             ______,
                                                                             ______,             ______, 
                                                                                                 ______, 
                                                           KC_F5,            LSFT(KC_F5),        ______, 
          
          //Right hand
          ______,                   ______,                ______,           ______,             ______,                ______,                  ______,
          ______,                   KC_INSERT,             KC_HOME,          KC_UP,              KC_END,                ______,                  ______,
                                    KC_PSCREEN,            KC_LEFT,          KC_DOWN,            KC_RIGHT,              ______,                  ______,
          ______,                   LALT(KC_PSCREEN),      KC_PGUP,          ______,             KC_PGDOWN,             ______,                  ______, 
          LCTL(KC_Z),               ______,                ______,           ______,             ______, 
          ______,                   ______, 
          ______, 
          ______,                   LCTL(KC_A),            LCTL(KC_Y)),

        [3] = KEYMAP(
          //Left hand
          ______,                   ______,                ______,           ______,             ______,                ______,                  ______, 
          ______,                   LALT(LCTL(KC_DELETE)), HYPR(KC_KP_1),    HYPR(KC_KP_2),      HYPR(KC_3),            ______,                  ______,
          ______,                   LALT(LSFT(KC_F)),      HYPR(KC_4),       HYPR(KC_5),         HYPR(KC_6),            ______,
          ______,                   ______,                HYPR(KC_7),       HYPR(KC_8),         HYPR(KC_9),            ______,                  ______,
          ______,                   ______,                ______,           ______,             ______, 
                                                                             ______,             ______, 
                                                                                                 ______, 
                                                           ______,           ______,             ______, 
          
          //Right hand
          ______,                   ______,                ______,           ______,             ______,                ______,                  HYPR(KC_UP), 
          HYPR(KC_U),               KC_LABK,               KC_AT,            KC_LPRN,            KC_RPRN,               KC_HASH,                 HYPR(KC_DOWN), 
          KC_RABK,                  KC_EQUAL,              KC_LCBR,          KC_RCBR,            KC_DLR,                ______, 
          HYPR(KC_D),               ______,                KC_GRAVE,         KC_LBRACKET,        KC_RBRACKET,           KC_PIPE,                 ______, 
          KC_KP_PLUS,               KC_KP_MINUS,           KC_KP_ASTERISK,   KC_KP_SLASH,        ______, 
          ______,                   ______, 
          ______, 
          ______,                   ______,                ______),

        [4] = KEYMAP(
          //Left hand
          LALT(KC_F4),              LCTL(KC_1),            LCTL(KC_2),       LCTL(KC_3),         LCTL(KC_4),            LCTL(KC_5),              ______, 
          LCTL(LSFT(KC_B)),         LCTL(LSFT(KC_P)),      LCTL(KC_W),       LCTL(KC_T),         ______,                ______,                  ______, 
          LSFT(KC_F12),             LCTL(KC_A),            LCTL(KC_TAB),     LCTL(LSFT(KC_TAB)), ______,                ______, 
          LCTL(LSFT(KC_S)),         LCTL(KC_S),            LCTL(KC_N),       LCTL(KC_O),         ______,                ______,                  ______, 
          ______,                   ______,                ______,           ______,             LCTL(LSFT(KC_G)), 
                                                           ______,           ______, 
                                                           ______, 
                                                           ______,           ______,             ______, 
          
          //Right hand
          ______,                   ______,                ______,           ______,             ______,                ______,                  ______,
          ______,                   ______,                ______,           ______,             ______,                ______,                  ______, 
          ______,                   ______,                ______,           ______,             ______,                ______, 
          ______,                   ______,                ______,           ______,             ______,                ______,                  ______, 
          ______,                   ______,                ______,           ______,             ______, 
          ______,                   ______, 
          ______, 
          ______,                   ______,                ______),
};

const uint16_t PROGMEM fn_actions[] = {
        [1] = ACTION_LAYER_TAP_TOGGLE(1)};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch (id)
  {
  case 0:
    if (record->event.pressed)
    {
      SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  // dynamically generate these.
  case EPRM:
    if (record->event.pressed)
    {
      eeconfig_init();
    }
    return false;
    break;
  case VRSN:
    if (record->event.pressed)
    {
      SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
    }
    return false;
    break;
  case RGB_SLD:
    if (record->event.pressed)
    {
      rgblight_mode(1);
    }
    return false;
    break;
  }
  return true;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void)
{

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer)
  {
  // TODO: Make this relevant to the ErgoDox EZ.
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
    ergodox_right_led_3_on();
    break;
  default:
    // none
    break;
  }
};
