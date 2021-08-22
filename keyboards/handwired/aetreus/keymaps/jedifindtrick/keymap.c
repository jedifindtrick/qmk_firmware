#include QMK_KEYBOARD_H

#define _QWE 0
#define _RSE 1
#define _LWR 2
#define _ADJ 3

#define LWR MO(_LWR)
#define RSE MO(_RSE)
#define ADJ MO(_ADJ)

// MOD_KC
#define CTL_ESC MT(MOD_LCTL, KC_ESCAPE)
#define CTL_ENT MT(MOD_LCTL, KC_ENTER)
#define ALT_Z   MT(MOD_LALT, KC_Z)
#define ALT_SLS MT(MOD_LALT, KC_SLASH)
#define SU_QUOT MT(MOD_LGUI, KC_QUOTE)
#define SU_BSLS MT(MOD_LGUI, KC_BSLS)
#define SFT_DEL MT(MOD_LSFT, KC_DELETE)

// LAYER_KC
#define ADJ_SPC  LT(ADJ, KC_SPC)
#define LWR_SPC  LT(LWR, KC_SPC)
#define RSE_LBRC LT(RSE, KC_LBRC)
#define RSE_RBRC LT(RSE, KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Default Layer
  [_QWE] = LAYOUT(
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,       KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    CTL_ESC, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,       KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, CTL_ENT,
    KC_LSFT, ALT_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,       KC_N   , KC_M   , KC_COMM, KC_DOT , ALT_SLS, SFT_DEL,
                      KC_A   , RSE_LBRC, ADJ_SPC , SU_QUOT,       SU_BSLS, LWR_SPC, RSE_RBRC, KC_A
  ),
  // Symbols Layer
  [_LWR] = LAYOUT(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_EQL ,
    KC_INS , S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),       S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_MINS,
    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,       KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
                      _______, KC_CAPS, OUT_USB, _______,       _______, _______, _______, _______
  ),
  // Navigation Layer
  [_RSE] = LAYOUT(
    _______, _______, _______, KC_PGUP, _______, _______,       KC_BRIU, _______, KC_UP  , _______, _______, _______,
    _______, _______, KC_HOME, KC_PGDN, KC_END , _______,       _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______,       KC_BRID, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______,
                      _______, _______, _______, _______,       _______, _______, _______, _______
  ),
  // Mouse Layer
  [_ADJ] = LAYOUT(
    _______, _______, KC_WREF, KC_WH_U, KC_WSCH, _______,       _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
    _______, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______,       _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
    _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,       _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______,       _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LWR:
      if (record->event.pressed) {
        layer_on(_LWR);
        update_tri_layer(_LWR, _RSE, _ADJ);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LWR, _RSE, _ADJ);
      }
      return false;
    case RSE:
      if (record->event.pressed) {
        layer_on(_RSE);
        update_tri_layer(_LWR, _RSE, _ADJ);
      } else {
        layer_off(_RSE);
        update_tri_layer(_LWR, _RSE, _ADJ);
      }
      return false;
    }
  return true;
}
