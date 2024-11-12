#include QMK_KEYBOARD_H


enum layer_names {
    _QWERTY,
    _QWERTY_HRM,
    _TRANSP,
    _COLEMAK,
    _COLEREVMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FUN,
    _MAXTEND,
    _MOUSE,
    _NUMSPACE,
    _NUMTAB
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  QWERTY_HRM,
  TRANSP,
  COLEMAK,
  REVMAK,
  LOWER,
  RAISE,
  ADJUST,
  FUN,
  MAXTEND,
  MOUSE,
  NUMSPACE,
  NUMTAB
};

#define D_TRANS DF(_TRANSP)
#define D_QWRTY DF(_QWERTY)
#define D_QTYHR DF(_QWERTY_HRM)
#define D_COLMK DF(_COLEMAK)
#define D_REVMK DF(_COLEREVMAK)
#define CALTDEL LCTL(LALT(KC_DEL))
#define ALTTAB LALT(KC_TAB)
#define TSKMGR LCTL(LSFT(KC_ESC))
#define RS_ENT MT(MOD_RSFT, KC_ENT)
#define MAXTBSP LT(_MAXTEND, KC_BSPC)
#define LA_LEFT LALT(KC_LEFT)
#define LA_RGHT LALT(KC_RGHT)
#define CTL_Z LCTL(KC_Z)
#define CTL_X LCTL(KC_X)
#define CTL_C LCTL(KC_C)
#define CTL_V LCTL(KC_V)
#define CTL_SPC LCTL(KC_SPC)
#define SPCMOUSE LT(_MOUSE, KC_SPC)
#define CTL_W LCTL(KC_W)
#define CTL_PGU LCTL(KC_PGUP)
#define CTL_PGD LCTL(KC_PGDN)
#define CTL_F LCTL(KC_F)
#define NUMSPC LT(_NUMSPACE, KC_SPC)
#define NUMTB LT(_NUMTAB, KC_TAB)
#define SPCLOWER LT(_LOWER, KC_SPC)
#define SPCRAISE LT(_RAISE, KC_SPC)
#define H_LA_A MT(MOD_LALT, KC_A)
#define H_RA_S MT(MOD_RALT, KC_S)
#define H_LS_D MT(MOD_LSFT, KC_D)
#define H_LC_F MT(MOD_LCTL, KC_F)
#define H_LG_G MT(MOD_LGUI, KC_G)
#define H_RG_H MT(MOD_RGUI, KC_H)
#define H_RC_J MT(MOD_RCTL, KC_J)
#define H_RS_K MT(MOD_RSFT, KC_K)
#define H_RA_L MT(MOD_RALT, KC_L)
#define H_LA_SC MT(MOD_LALT, KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     NUMTB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,          KC_EQL,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     MAXTBSP, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,          KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,           KC_SPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RS_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_LGUI, KC_LALT, ADJUST,           LOWER,   SPCMOUSE,         NUMSPC,  RAISE,            FUN,     KC_RALT, KC_RGUI, KC_RCTL
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_QWERTY_HRM] = LAYOUT(
     NUMTB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,          KC_EQL,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     MAXTBSP, H_LA_A,  H_RA_S,  H_LS_D,  H_LC_F,  H_LG_G,  KC_LBRC,          KC_RBRC, H_RG_H,  H_RC_J,  H_RS_K,  H_RA_L,  H_LA_SC, KC_QUOT,
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,           KC_SPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RS_ENT,
     KC_LCTL, KC_LGUI, KC_LALT, ADJUST,           LOWER,   SPCMOUSE,         NUMSPC,  RAISE,            FUN,     KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_TRANSP] = LAYOUT(
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,          KC_EQL,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,          KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,           KC_SPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
     KC_LCTL, KC_LGUI, KC_LALT, ADJUST,           LOWER,   KC_SPC,           KC_SPC,  RAISE,            FUN,     KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_COLEMAK] = LAYOUT(
     NUMTB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_MINS,          KC_EQL,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
     MAXTBSP, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_LBRC,          KC_RBRC, KC_H,    KC_N,    KC_E,    KC_I,    KC_I,    KC_QUOT,
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,           KC_SPC,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RS_ENT,
     KC_LCTL, KC_LGUI, KC_LALT, ADJUST,           LOWER,   KC_SPC,           NUMSPC,  RAISE,            FUN,     KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_COLEREVMAK] = LAYOUT(
     NUMTB,   KC_Q,    KC_W,    KC_K,    KC_S,    KC_F,    KC_MINS,          KC_EQL,  KC_O,    KC_I,    KC_L,    KC_SCLN, KC_R,    KC_BSPC,
     MAXTBSP, KC_A,    KC_D,    KC_G,    KC_E,    KC_T,    KC_LBRC,          KC_RBRC, KC_H,    KC_Y,    KC_N,    KC_U,    KC_P,    KC_QUOT,
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,           KC_SPC,  KC_J,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RS_ENT,
     KC_LCTL, KC_LGUI, KC_LALT, ADJUST,           LOWER,   KC_SPC,           NUMSPC,  RAISE,            FUN,     KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_LOWER] = LAYOUT(
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_HOME,         KC_PGUP, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
     KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_END ,         KC_PGDN, KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_BSLS,
     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_BSPC,         KC_BSPC, KC_F12,  _______, _______, KC_MUTE, _______, KC_PIPE,
     _______, _______, _______, _______,          _______, KC_BSPC,         KC_BSPC, _______,          KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),

  [_RAISE] = LAYOUT(
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,         _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
     KC_DEL,  KC_4,    KC_5,    KC_6,    KC_PLUS, _______, _______,         _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_GRV,
     KC_ENT,  KC_7,    KC_8,    KC_9,    KC_MINS, _______, _______,         _______, _______, KC_NUHS, KC_NUBS, KC_MUTE, _______, KC_BSLS,
     _______, KC_COMM, KC_0,    KC_DOT,           _______, KC_BSPC,         KC_BSPC, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),

  [_ADJUST] = LAYOUT(
     ALTTAB,  _______, _______, _______, _______, _______, D_TRANS,         D_QWRTY, D_QTYHR, UG_NEXT, UG_VALU, UG_SATU, UG_HUEU, CALTDEL,
     _______, _______, _______, _______, _______, _______, D_COLMK,         D_REVMK, _______, UG_PREV, UG_VALD, UG_SATD, UG_HUED, UG_TOGG,
     _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, BL_STEP,
     _______, _______, _______, _______,          _______, _______,         _______, _______,          _______, _______, QK_RBT,  QK_BOOT
  ),

  [_FUN] = LAYOUT(
     KC_ESC,  _______, _______, _______, _______, _______, _______,         _______, _______, KC_MPLY, KC_VOLU, KC_PSCR, KC_SCRL, KC_PAUS,
     _______, _______, _______, _______, _______, _______, _______,         _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, _______,
     _______, _______, _______, KC_CALC, _______, _______, _______,         _______, _______, _______, KC_MUTE, _______, _______, _______,
     _______, _______, _______, _______,          _______, _______,         _______, _______,          _______, _______, _______, QK_BOOT
  ),

  [_MAXTEND] = LAYOUT(
     _______, KC_ESC,  MS_WHLU, KC_WBAK, KC_WFWD, _______, _______,         _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_DEL,  KC_INS,
     KC_ENT,  KC_LALT, MS_WHLD, KC_LSFT, KC_LCTL, KC_LGUI, _______,         _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, KC_ENT,
     _______, CTL_Z,   CTL_X,   CTL_C,   CTL_V,   _______, _______,         _______, _______, _______, _______, _______, KC_APP,  KC_ENT,
     _______, _______, _______, _______,          _______, KC_ENT,          CTL_SPC, CTL_SPC,          _______, _______, _______, _______
  ),

  [_MOUSE] = LAYOUT(
     KC_ESC,  KC_ESC,  CTL_W,   CTL_PGU, CTL_PGD, CTL_F,   _______,         _______, MS_WHLU, MS_WHLL, MS_UP,   MS_WHLR,  KC_DEL,  KC_INS,
     KC_ENT,  MS_ACL1, MS_BTN3, MS_BTN2, MS_BTN1, MS_ACL0, _______,         _______, MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, KC_BSPC, KC_ENT,
     _______, CTL_Z,   CTL_X,   CTL_C,   CTL_V,   MS_ACL2, _______,         _______, _______, _______, _______, _______, KC_APP,  KC_ENT,
     _______, _______, _______, _______,          _______, _______,         MS_BTN1, MS_BTN2,          _______, _______, _______, _______
  ),

  [_NUMSPACE] = LAYOUT(
     KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,         _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
     MAXTBSP, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,         _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PLUS,
     KC_LSFT, KC_MINS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______,         _______, S(KC_P), KC_P,    _______, _______, _______, KC_EQL,
     _______, _______, _______, _______,          _______, _______,         _______, _______,          _______, _______, _______, _______
  ),

  [_NUMTAB] = LAYOUT(
     _______, KC_ESC,  _______, _______, _______, _______, _______,         _______, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_BSPC,
     MAXTBSP, KC_LALT, _______, _______, _______, _______, _______,         _______, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PENT,
     KC_LSFT, CTL_Z,   CTL_X,   CTL_C,   CTL_V,   KC_NUM,  KC_NUM,          _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, RS_ENT,
     _______, _______, _______, _______,          _______, KC_ENT,          _______, KC_0,             KC_PDOT, _______, _______, _______
  )

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        set_single_persistent_default_layer(_QWERTY);
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
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
     case FUN:
      if (record->event.pressed) {
        layer_on(_FUN);
      } else {
        layer_off(_FUN);
      }
      return false;
      break;
     case MAXTEND:
      if (record->event.pressed) {
        layer_on(_MAXTEND);
      } else {
        layer_off(_MAXTEND);
      }
      return false;
      break;
  }
  return true;
}
