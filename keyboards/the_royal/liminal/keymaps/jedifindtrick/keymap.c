#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _OTHER
};


//Tap Dance Declarations
enum {
  TD_RST,
  TD_DBQT,
  TD_ENBS
};

void dance_rst_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 2) {
    reset_keyboard();
    reset_tap_dance(state);
  }
}

//All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_RST] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, NULL, dance_rst_reset),
  [TD_DBQT] = ACTION_TAP_DANCE_DOUBLE (KC_QUOTE, KC_DQT),
  [TD_ENBS] = ACTION_TAP_DANCE_DOUBLE (KC_ENTER, KC_BSLASH)
};

enum custom_keycodes {
  M_PAR = SAFE_RANGE,
  M_BKT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M_PAR:
      if (record->event.pressed) {
        SEND_STRING("()" SS_TAP(X_LEFT));
      }
      break;
    case M_BKT:
      if (record->event.pressed) {
        SEND_STRING("[]" SS_TAP(X_LEFT));
      }
      break;
  }
  return true;

};

#define OTHER MO(_OTHER)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Default layer
   * ┌─────┬────┬─────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬──────┐
   * │ Esc │Tab │  Q  │ W  │ E  │ R  │ T  │ Y  │ U  │ I  │ O  │ P  │ Å  │ BkSp │
   * ├─────┼────┴─┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬─────┤
   * │PgUp │LCtrl │ A  │ S  │ D  │ F  │ G  │ H  │ J  │ K  │ L  │ Ö  │ Ä  │Enter│
   * ├─────┼────┬─┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─────┤
   * │PgDn │Shft│ < │ Z  │ X  │ C  │ V  │ B  │ N  │ M  │ ,  │ .  │ -  │  Other │
   * ├─────┼────┼───┴┬───┴─┬──┴────┴────┼────┴────┴┬───┴───┬┴────┴┬───┴─┬──────┤
   * │ Gui │Ctrl│Gui │ Alt │      Right │C = 7u/2.2│ AltGr │ Gui  │Menu │ Game │
   * └─────┴────┴────┴─────┴────────────┴──────────┴───────┴──────┴─────┴──────┘
   */
  [_QWERTY] = LAYOUT_base_kit_all(
    KC_ESC,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_BSPC,
    KC_PGUP, KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOTE, TD(TD_ENBS),
    KC_PGDN, KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  TT(_OTHER),
    KC_END,  KC_LCTL, KC_LGUI, KC_LALT,  LT(_LOWER, KC_SPACE), LT(_RAISE, KC_SPACE),          KC_RALT, RAISE,   KC_MENU,  LOWER
  ),

  /* LOWER layer
   * ┌─────┬────┬─────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬──────┐
   * │VolU │ §  │ 1   │ 2  │ 3  │ 4  │ 5  │ 6  │ 7  │ 8  │ 9  │ 0  │ _  │      │
   * ├─────┼────┴─┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬─────┤
   * │Next │      │ !  │ "  │ #  │ ¤  │ %  │ &  │ /  │ (  │ )  │ =  │ +  │  ¨  │
   * ├─────┼────┬─┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─────┤
   * │Prev │    │   │ @  │ £  │ $  │ €  │    │ {  │ [  │ ]  │ }  │ \  │        │
   * ├─────┼────┼───┴┬───┴─┬──┴────┴────┼────┴────┴┬───┴───┬┴────┴┬───┴─┬──────┤
   * │VolD │    │    │     │            │          │       │      │     │      │
   * └─────┴────┴────┴─────┴────────────┴──────────┴───────┴──────┴─────┴──────┘
   */
  [_LOWER] = LAYOUT_base_kit_all(
    KC_VOLU,  KC_GRV,    KC_1,         KC_2,         KC_3,         KC_4,         KC_5,         KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         LSFT(KC_MINUS),     _______,
    KC_MNXT,  KC_MPLY,   LSFT(KC_1),   LSFT(KC_2),   LSFT(KC_3),   LSFT(KC_4),   LSFT(KC_5),   LSFT(KC_6),   LSFT(KC_7),   LSFT(KC_8),   LSFT(KC_9),   LSFT(KC_0),   KC_MINUS,           KC_RBRC,
    KC_MPRV,  _______,   _______,      RALT(KC_2),   RALT(KC_3),   RALT(KC_4),   RALT(KC_5),   _______,      RALT(KC_7),   RALT(KC_8),   RALT(KC_9),   RALT(KC_0),   RALT(KC_MINUS),     _______,
    KC_VOLD,  _______,   _______,      _______,                            _______,                  _______,                       _______,   _______,     _______,     _______
  ),

  /* RAISE layer
   * ┌─────┬────┬─────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬──────┐
   * │     │    │     │    │    │    │    │    │    │    │    │    │ =  │  +   │
   * ├─────┼────┴─┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬─────┤
   * │     │ CAPS │    │    │    │    │    │    │    │    │    │    │    │     │
   * ├─────┼────┬─┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─────┤
   * │     │    │   │    │    │    │    │    │    │    │    │ [  │ ]  │        │
   * ├─────┼────┼───┴┬───┴─┬──┴────┴────┼────┴────┴┬───┴───┬┴────┴┬───┴─┬──────┤
   * │     │    │    │     │            │          │       │      │     │      │
   * └─────┴────┴────┴─────┴────────────┴──────────┴───────┴──────┴─────┴──────┘
   */
  [_RAISE] = LAYOUT_base_kit_all(
    KC_PSCREEN,   KC_F1,     KC_F2,     KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,          KC_DEL,
    _______,      KC_CAPS,   _______,   _______,    _______,    _______,    _______,    _______,   _______,    _______,    _______,    _______,    LSFT(KC_EQUAL),  KC_EQUAL,
    _______,      _______,   _______,   _______,    _______,    _______,    _______,    _______,   _______,    _______,    _______,    _______,    _______,         _______,        
    _______,      _______,   _______,   _______,                      _______,              _______,                       _______,    _______,    _______,         _______
  ),

  /* OTHER layer
   * ┌─────┬────┬─────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬──────┐
   * │HOME │    │     │    │    │    │    │    │    │    │    │    │ UP │      │
   * ├─────┼────┴─┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬───┴┬─────┤
   * │END  │      │    │    │    │    │    │    │    │    │    │LEFT│RGHT│     │
   * ├─────┼────┬─┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴─────┤
   * │     │    │   │    │    │    │    │    │    │    │    │    │DOWN│        │
   * ├─────┼────┼───┴┬───┴─┬──┴────┴────┼────┴────┴┬───┴───┬┴────┴┬───┴─┬──────┤
   * │     │    │    │     │            │          │       │      │     │      │
   * └─────┴────┴────┴─────┴────────────┴──────────┴───────┴──────┴─────┴──────┘
   */
  [_OTHER] = LAYOUT_base_kit_all(
    KC_ESC,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,      KC_UP,      _______,    _______,    _______,
    KC_2,    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_LEFT,   KC_DOWN,    KC_RIGHT,   _______,    KC_ENTER,
    KC_3,    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,      KC_COMM,    KC_DOT,     _______,    _______,
    KC_4,    KC_LCTL, KC_LGUI, KC_LALT,           KC_SPACE,        KC_SPACE,         TD(TD_RST),            _______,    _______,    _______
  )

};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(_LOWER, KC_SPACE):
      return 180;
    case LT(_RAISE, KC_SPACE):
      return 180;
    case TD(TD_DBQT):
      return 230;
    case TD(TD_ENBS):
      return 170;
    default:
      return 200;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 1:
        rgblight_setrgb (RGB_GOLD);
        break;
    case 2:
        rgblight_setrgb (RGB_RED);
        break;
    case 3:
        rgblight_setrgb (RGB_BLUE);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (RGB_CORAL);
        break;
    }
  return state;
}