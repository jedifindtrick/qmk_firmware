#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
#define _QWERTY 0
#define _SYM 3
#define _SYS 4
#define _GAME 5
#define _GAME2 6
#define _GAME3 7
#define _GFN 8
#define _GFN2 9

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// custom keycodes defined by my, mostly modtaps and layertaps
#define KC_SWLBRC A(KC_LBRC)
#define KC_SWQUOT A(KC_QUOT)
#define KC_SWSCLN A(KC_SCLN)
#define KC_GMESC LT(_GFN, KC_ESC)
#define KC_GMESC2 LT(_GFN2, KC_ESC)

// windows backslash
#define KC_WIN_BSLS RALT(KC_MINS)
// close all tabs to the right in firefox
#define KC_FFCT LALT(LSFT(KC_F2))
// ctrl enter, used in jupyter
#define KC_CENT LCTL(KC_ENT)

// all modifiers should be modtap!
#define KC_MYCTL MT(MOD_RCTL, KC_ENT)
#define KC_MYSYM LT(_SYM, KC_TAB)
#define KC_MYALT MT(MOD_RALT, KC_TAB)
#define KC_MYGUI MT(MOD_LGUI, KC_F3)
#define KC_MYSFT MT(MOD_LSFT, KC_BSPC)
#define KC_MYTAB LT(_SYS, KC_ESC)

// window manager change space/display
#define KC_DTOG LCTL(LALT(KC_X))
#define KC_SPC1 LGUI(LALT(KC_1))
#define KC_SPC2 LGUI(LALT(KC_2))
#define KC_SPC3 LGUI(LALT(KC_3))

// window manager send to space/display
#define KC_SDTG LCTL(LCMD(KC_X))
#define KC_SSP1 LSFT(LCMD(KC_1))
#define KC_SSP2 LSFT(LCMD(KC_2))
#define KC_SSP3 LSFT(LCMD(KC_3))


// Swedish keybord special signs
#define KC_ARING KC_LBRC
#define KC_OUML KC_SCLN
#define KC_AUML KC_QUOT
#define KC_SE_SLSH S(KC_7)
#define KC_SE_AT RALT(KC_2) 
#define KC_SE_AMPR S(KC_6)
#define KC_SE_LPRN S(KC_8)
#define KC_SE_RPRN S(KC_9)
#define KC_SE_QUOT KC_BSLS
#define KC_SE_DQUO S(KC_2)
#define KC_SE_DLR RALT(KC_4)
#define KC_SE_LCBR S(RALT(KC_8))
#define KC_SE_RCBR S(RALT(KC_9))
#define KC_SE_LBRC RALT(KC_8)
#define KC_SE_RBRC RALT(KC_9)
#define KC_SE_EQL S(KC_0)
#define KC_SE_GBP RALT(KC_3)
#define KC_SE_TILD RALT(KC_RBRC)
#define KC_SE_EURO RALT(KC_E)
#define KC_SE_AA KC_LBRC
#define KC_SE_OE KC_SCLN
#define KC_SE_AE KC_QUOT
#define KC_SE_PLAYP KC_MEDIA_PLAY_PAUSE
#define KC_SE_MUTE KC_AUDIO_MUTE
#define KC_SE_CIRC KC_RCBR
#define KC_SE_PARA KC_GRAVE
#define KC_SE_HALF KC_TILD
#define KC_SE_ACUT KC_EQL
#define KC_SE_GRAV KC_PLUS
#define KC_SE_GT S(KC_GRV)
#define KC_SE_LT KC_GRV
#define KC_SE_PLUS KC_MINS
#define KC_SE_ASTR KC_PIPE
#define KC_SE_QUES S(KC_MINS)
#define KC_SE_BSLS S(RALT(KC_7))
#define KC_SE_PIPE RALT(KC_7)
#define KC_SE_SCLN S(KC_COMM)
#define KC_SE_COLN S(KC_DOT)
#define KC_SE_MINS KC_SLSH
#define KC_SE_UNDS S(KC_SLSH)

// home row modifier stuff
/* #define KC_MYF MT(MOD_LSFT, KC_F) */
/* #define KC_MYJ MT(MOD_LSFT, KC_J) */
/* #define KC_MYD MT(MOD_LCTL, KC_D) */
/* #define KC_MYK MT(MOD_RCTL, KC_K) */
/* #define KC_MYS MT(MOD_LALT, KC_S) */
/* #define KC_MYL MT(MOD_RALT, KC_L) */
/* #define KC_MYA MT(MOD_LGUI, KC_A) */

float my_song[][2] = SONG(MARIO_MUSHROOM);

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYM,
  SYS,
  ANSIKEY,
  ANSICOM,
  ANSIDOT,
  MY_SCREENSHOT,
  M_ARROW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-------------------------------------------  -----------------------------------------.
 * | Shift|   Q  |   W  |   E  |   R  |   T  |   |  Y  |   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+------+-  +-----+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   |  H  |   J  |   K  |   L  |   Ö  |  Ä   |
 * |------+------+------+------+------+------+-  +-----+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   |  N  |   M  |   ,  |   .  |   /  | Shift|
 * `------+------+------+------+------+------+-  +-----+------+------+------+------+------'
 *               | Shift| Cmd  | Tab  | Bspc |   |Space| Enter| Alt  | Shift|
 *               |      | (F3) | SYM  | Shift|   |     | Ctrl | (Tab)|      |
 *               `-----------------------------  --------------------------'
 *
 * Enter becomes shift when held down
 * Tab goes to SYM layer when held down
 * Alt becomes Tab when tapped (only used for Cmd + Tab)
 * , . / becomes < > ? when shift is pressed
 * HJKL becomes arrows when right shift is pressed
 *
 */

[_QWERTY] = LAYOUT_ortho_4x12(
    KC_MYTAB,    KC_Q,    KC_W,     KC_E,    KC_R,      KC_T,        KC_Y,     KC_U,     KC_I,    KC_O,      KC_P, KC_ARING, \
      KC_ESC,    KC_A,    KC_S,     KC_D,    KC_F,      KC_G,        KC_H,     KC_J,     KC_K,    KC_L,   KC_OUML,  KC_AUML, \
     KC_LSFT,    KC_Z,    KC_X,     KC_C,    KC_V,      KC_B,        KC_N,     KC_M,  ANSICOM, ANSIDOT,   ANSIKEY, KC_MYTAB, \
     XXXXXXX, XXXXXXX, KC_LSFT, KC_MYGUI, KC_MYSYM, KC_MYSFT,     KC_SPC, KC_MYCTL, KC_MYALT, _______,   XXXXXXX,  XXXXXXX  \
),

/* SYM
 * ,-----------------------------------------.   ,-----------------------------------------.
 * |   `  |   !  |   @  |   {  |   }  |   &  |   |   *  |   7  |   8  |   9  |   +  |   =  |
 * |------+------+------+------+------+-------   |------+------+------+------+------+------|
 * |   ~  |   ^  |   $  |   (  |   )  |   '  |   |   ;  |   4  |   5  |   6  |   -  |   _  |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * |   |  |   #  |   %  |   [  |   ]  |   "  |   |   :  |   1  |   2  |   3  |   \  |  =>  |
 * |------+------+------+------+------+------+   |------+------+------+------+------+------|
 * |      |      | RESET|      |      |      |   |      | C_ENT|   0  |      |      |      |
 * `-----------------------------------------'   `-----------------------------------------'
 */
[_SYM] = LAYOUT_ortho_4x12( \
    KC_SE_GRAV,    KC_EXLM,  KC_SE_AT, KC_SE_LCBR, KC_SE_RCBR, KC_SE_AMPR, KC_SE_ASTR,    KC_7,      KC_8,    KC_9, KC_SE_PLUS,  KC_SE_EQL, \
    KC_SE_TILD, KC_SE_CIRC, KC_SE_DLR, KC_SE_LPRN, KC_SE_RPRN, KC_SE_QUOT, KC_SE_SCLN,    KC_4,      KC_5,    KC_6, KC_SE_MINS, KC_SE_UNDS, \
    KC_SE_PIPE,    KC_HASH,   KC_PERC, KC_SE_LBRC, KC_SE_RBRC, KC_SE_DQUO, KC_SE_COLN,    KC_1,      KC_2,    KC_3, KC_SE_BSLS,    M_ARROW, \
       XXXXXXX,    XXXXXXX,     RESET,    _______,    _______,    _______,    _______, KC_CENT,      KC_0, _______,    XXXXXXX,    XXXXXXX  \
),

/* Sys
 */

[_SYS] = LAYOUT_ortho_4x12(
    KC_MYTAB, KC_VOLD, KC_MUTE, KC_VOLU,       KC_FFCT, _______,        _______, KC_SDTG, KC_SSP1, KC_SSP2, KC_SSP3, _______, \
   TO(_GAME), KC_MRWD, KC_MPLY, KC_MFFD, MY_SCREENSHOT, _______,        KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______, _______, \
  TO(_GAME2), _______, _______, _______,       _______, _______,        _______, KC_DTOG, KC_SPC1, KC_SPC2, KC_SPC3, _______, \
     XXXXXXX, XXXXXXX,   RESET, _______,       _______, _______,        _______, _______, _______, _______, XXXXXXX, XXXXXXX \
),

/* Game
 * ,-----------------------------------------.   ,-----------------------------------------.
 * |[Esc] |   1  |   2  |   3  |   4  |   5  |   |QWERTY|      |      |      |      |      |
 * |------+------+------+------+------+-------   |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   |------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |   |      |      |      |      |      |      |
 * |------+------+------+------+------+------+   |------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  | Space|   |      |      |      |      |      |      |
 * `-----------------------------------------'   `-----------------------------------------'
 */

[_GAME] = LAYOUT_ortho_4x12(
      KC_SPC,    KC_V,    KC_C,    KC_X,    KC_Z,  KC_LCTL,      _______, _______, _______, _______, _______, _______, \
        KC_G,    KC_F,    KC_D,    KC_S,    KC_A,  KC_LSFT,      _______, _______, _______, _______, _______, _______, \
        KC_T,    KC_R,    KC_E,    KC_W,    KC_Q,   KC_TAB,      _______, _______, _______, _______, _______, _______, \
        KC_5,    KC_4,    KC_3,    KC_2,    KC_1, KC_GMESC,  TO(_QWERTY), _______, _______, _______, _______, _______ \
),

[_GAME2] = LAYOUT_ortho_4x12(
     _______, _______, KC_GMESC2,    KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    TO(_QWERTY), _______, _______, _______, \
     _______, _______,    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,        _______, _______, _______, _______, \
     _______, _______,   KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,     KC_G,        _______, _______, _______, _______, \
     _______, _______,   KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,   KC_SPC,        _______, _______, _______, _______ \
),

/* Game FN
 * ,-----------------------------------------. 
 * |      |  F1  |  F2  | VOTE | TEAM | Cons | 
 * |------+------+------+------+------+------- 
 * |  Buy | Vol- | Mute | Vol+ | rebuy|autbuy| 
 * |------+------+------+------+------+------| 
 * |      | Bri- | Drop | Bri+ |  M   |  I   | 
 * |------+------+------+------+------+------+ 
 * |      |  P   |      |  O   |  K   |QWERTY| 
 * `-----------------------------------------' 
 */

[_GFN] = LAYOUT_ortho_4x12(
  TO(_QWERTY),      KC_K,      KC_O, _______,    KC_P,  _______,       _______,  _______, _______, _______, _______, _______, \
         KC_I,      KC_M,    BL_DEC,    KC_K,  BL_INC,  KC_SLSH,       _______,  _______, _______, _______, _______, _______, \
    KC_SWQUOT, KC_SWSCLN,   KC_VOLU, KC_MUTE, KC_VOLD,     KC_B,       _______,  _______, _______, _______, _______, _______, \
      KC_SLSH,      KC_M, KC_SWLBRC,   KC_F2,   KC_F1,  _______,       _______,  _______, _______, _______, _______, _______ \
),

[_GFN2] = LAYOUT_ortho_4x12(
    _______,  _______, _______,   KC_F1,   KC_F2, KC_SWLBRC,      KC_M,     KC_SLSH,    _______, _______, _______, _______, \
    _______,  _______,    KC_B, KC_VOLD, KC_MUTE,   KC_VOLU, KC_SWSCLN,   KC_SWQUOT,    _______, _______, _______, _______, \
    _______,  _______, KC_SLSH,  BL_INC,    KC_K,    BL_DEC,      KC_M,        KC_I,    _______, _______, _______, _______, \
    _______,  _______, _______,    KC_P, _______,      KC_O,      KC_K, TO(_QWERTY),    _______, _______, _______, _______ \
),

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t shift_pressed = get_mods() & ((MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)));
  // uint8_t alt_pressed = get_mods() & ((MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT)));

  switch (keycode) {
    case ANSIKEY: {
      if (record->event.pressed)
        if(shift_pressed) {
          register_code(KC_MINS);
        } else {
          register_code(KC_LSHIFT);
          register_code(KC_7);
          unregister_code(KC_LSHIFT);
        }
      else
        if(shift_pressed) {
          unregister_code(KC_MINS);
        } else {
          unregister_code(KC_7);
        }
      return false;
    }
    case ANSICOM: {
      if (record->event.pressed)
        if(shift_pressed) {
          unregister_code(KC_LSHIFT);
          register_code(KC_GRV);
          register_code(KC_LSHIFT);
        } else {
          register_code(KC_COMM);
        }
      else
        if(shift_pressed) {
          unregister_code(KC_GRV);
        } else {
          unregister_code(KC_COMM);
        }
      return false;
    }
    case ANSIDOT: {
      if (record->event.pressed)
        if(shift_pressed) {
          register_code(KC_GRV);
        } else {
          register_code(KC_DOT);
        }
      else
        if(shift_pressed) {
          unregister_code(KC_GRV);
        } else {
          unregister_code(KC_DOT);
        }
      return false;
    }
    case MY_SCREENSHOT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LGUI(SS_LSFT(SS_TAP(X_4)))));
      }
      return false;
      break;
    case M_ARROW:
      if (record->event.pressed) {
        SEND_STRING(")" SS_LSFT("`")); // =>
      }
      return false;
      break;
    // The following two cases handle layer switching
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case SYM:
      if (record->event.pressed) {
        layer_on(_SYM);
      } else {
        layer_off(_SYM);
      }
      return false;
      break;
  }
  return true;
}
