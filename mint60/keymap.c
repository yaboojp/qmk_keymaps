/* Copyright 2018 Eucalyn
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum custom_keycodes {
  RGBRST = SAFE_RANGE
};

#define KC_LLANG1 LT(KC_RGUI, KC_LANG1)
#define KC_LLANG2 LT(KC_LGUI, KC_LANG2)
#define KC_LMOVE LGUI(LSFT(KC_LBRC))
#define KC_RMOVE LGUI(LSFT(KC_RBRC))
#define KC_QVOLU LALT(LSFT(KC__VOLUP))
#define KC_QVOLD LALT(LSFT(KC__VOLDOWN))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,    KC_BSPC,\
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,\
    KC_LGUI,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,        KC_ENT,\
    KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,  KC_ESC,\
    MO(1),     KC_LCTL,    KC_LALT,    KC_LGUI,    KC_SPC,        MO(1),    KC_RGUI, KC_RSFT,                   KC_LEFT,KC_DOWN,KC_RGHT \
  ),
  [1] = LAYOUT( \
    RGB_HUD,  RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI,       KC_F6,   KC_MRWD,   KC_MPLY,   KC_MFFD,   KC__MUTE,  KC_QVOLD,  KC_QVOLU,    KC_DEL, \
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_PGUP, KC_LMOVE, KC_UP, KC_RMOVE, XXXXXXX, RGB_MOD, RGB_TOG, RGBRST, \
    KC_LGUI,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,           KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,        KC_ENT, \
    KC_LSFT,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_PGUP, _______, \
    XXXXXXX,   KC_LCTL,    KC_LALT,    KC_LGUI,    KC_SPC,           XXXXXXX, KC_RCTL, KC_RSFT,                    KC_HOME, KC_PGDN, KC_END \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
  }
  return true;
}
