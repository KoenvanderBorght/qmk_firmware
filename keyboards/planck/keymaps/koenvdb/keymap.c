// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _PROGM,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

// Fillers to make layering more clear
#define ACCEL0 KC_MS_ACCEL0
#define ACCEL1 KC_MS_ACCEL1
#define ACCEL2 KC_MS_ACCEL2
#define PRINTSC LALT(KC_PSCREEN)
#define NEWD LCTL(LGUI(KC_D))
#define CLOSED LCTL(LGUI(KC_F4))
#define BACKD LCTL(LGUI(KC_LEFT))
#define NEXTD LCTL(LGUI(KC_RGHT))
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define FORMATC M(0)


//Tap Dance Declarations
enum {
  TD_ESC_CAPS = 0,
  TD_NEXT_PREV,
  TD_MINS_UNDS,
  TD_LCBR_LBRC,
  TD_RCBR_RBRC,
  TD_1_EXCL,
  TD_2_AT,
  TD_3_HAS,
  TD_4_DLR,
  TD_5_PRC,
  TD_6_CIR,
  TD_7_AMPR,
  TD_8_ASTR,
  TD_9_LPRN,
  TD_0_RPRN,
  TD_COPY_PASTE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | PROGM|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | newD |CloseD|BackD|NextD|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {MO(_PROGM),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT},
  {KC_LCTL, KC_LALT, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   NEWD,    CLOSED,  BACKD,   NEXTD}
},
/* PROGM
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+`````  ---------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   =  |   (  |   )  |   $  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   -  |   {  |   }  | Play | Next |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |  [  |   ]  | Vol+ | Prev |
 * `-----------------------------------------------------------------------------------'
 */
[_PROGM] = {
  {KC_GRV,  TD(TD_1_EXCL),    TD(TD_2_AT),    TD(TD_3_HAS),    TD(TD_4_DLR),    TD(TD_5_PRC),    TD(TD_6_CIR),    TD(TD_7_AMPR),    TD(TD_8_ASTR),    TD(TD_9_LPRN), TD(TD_0_RPRN),    KC_DEL},
  {_______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_EQL,    TD(TD_LCBR_LBRC),    TD(TD_RCBR_RBRC), KC_DLR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  TD(TD_MINS_UNDS), _______, _______, KC_MPLY, TD(TD_NEXT_PREV)},
  {_______, _______, _______, _______, KC_LSFT, _______, _______, TD(TD_COPY_PASTE),    KC_PSCR, KC_MUTE, KC_VOLD, KC_VOLU}
},
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |ALTSHTF|ALTENT|FORMATVS|UNDO|COPY|INSERT|HOME|UP|END|   #  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |      |      |     |      |      |  END  | LEFT | DOWN | RGHT|   $  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |       |      |ALTPSCR|PGUP|      |PGDN|        |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |     |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_ESC,   LALT(LSFT(KC_F)), LALT(KC_ENT),   FORMATC, LCTL(KC_Z), LCTL(KC_C), KC_INS,  KC_HOME, KC_UP,   KC_END,   _______,      _______},
  {_______, _______, _______, _______, _______, _______, KC_END,  KC_LEFT, KC_DOWN, KC_RGHT,  _______, _______},
  {_______, _______, _______, _______, _______, _______, LALT(KC_PSCR), KC_PGUP, _______, KC_PGDN, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},
/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  | M_UP |   3  |   4  |   5  |   6  |   7  |SCRLUP| PREV  | NEXT |VOLUP|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | PRGM  |M_LEFT|M_DOWN|M_RIGH|  F4  |LEFTM|RIGHTM|SCRLLE|SCRLDN|SCRLRI|   ]  |VOLD{N|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO /- |Pg Up |Pg Dn | MUTE |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | TLRAIS |ALTSHIFTF| Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_ESC,  KC_1,    KC_MS_UP,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_MS_WH_UP, KC_MPRV,   KC_MNXT,  KC_VOLU},
  {KC_DEL,  KC_MS_LEFT,   KC_MS_DOWN,   KC_MS_RIGHT,   KC_F4,   KC_MS_BTN1,   KC_MS_BTN2,   KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_RBRC, KC_VOLD},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ACCEL0,  ACCEL1,  ACCEL2, KC_PGDN, KC_MUTE},
  {_______, _______, _______, _______, _______, _______, _______, _______, TG(_RAISE), _______, LALT(KC_F4), KC_MPLY}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL },
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______, _______,  _______,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0: {
            if (record->event.pressed) {
                return MACRO (D(LCTL), T(K), U(LCTL), D(LCTL), T(D), U(LCTL), END); // if the key is being pressed, we start the timer.
            }
            break;
        }
      }
    return MACRO_NONE;
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Next, twice for Previous
  [TD_NEXT_PREV]  = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPRV),
  //Tap once for -, twice for _
  [TD_MINS_UNDS]  = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
  //Tap once for {, twice for [
  [TD_LCBR_LBRC]  = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_LBRC),
  //Tap once for }, twice for ]
  [TD_RCBR_RBRC]  = ACTION_TAP_DANCE_DOUBLE(KC_RCBR, KC_RBRC),
  //Tap once for 1, twice for !
  [TD_1_EXCL] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_EXLM),
  //Tap once for 2, twice for @
  [TD_2_AT] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_AT),
  //Tap once for 3, twice for #
  [TD_3_HAS] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_HASH),
  //Tap once for 4, twice for $
  [TD_4_DLR] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_DLR),
  //Tap once for 5, twice for %
  [TD_5_PRC] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_PERC),
  //Tap once for 6, twice for ^
  [TD_6_CIR] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_CIRC),
  //Tap once for 7, twice for 
  [TD_7_AMPR] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_AMPR),
  //Tap once for 8, twice for * 
  [TD_8_ASTR] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_ASTR),
  //Tap once for 9, twice for (
  [TD_9_LPRN] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_LPRN),
  //Tap once for 0, twice for ) 
  [TD_0_RPRN] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_RPRN),
  //Tap once for copy, twice for paste
  [TD_COPY_PASTE] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_C), LCTL(KC_V))
  
  // Other declarations would go here, separated by commas, if you have them
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
      case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
