/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"
#include "print.h"

// clang-format off

enum {
	USER_WPM = QK_USER,
};

enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN,
  WIN_FN2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_109(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,    KC_SNAP,  KC_SIRI,  RGB_MOD,  KC_F13,   KC_F14,   KC_F15,   KC_F16,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [MAC_FN] = LAYOUT_ansi_109(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RGB_TOG,    _______,  _______,  RGB_TOG,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),
    [WIN_BASE] = LAYOUT_ansi_109(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,    _______,  RGB_TOG,  _______,  KC_CALC,  _______,  _______,  _______,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [WIN_FN] = LAYOUT_ansi_109(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,    _______,  RGB_MOD,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  QK_BOOT,  NK_TOGG,  USER_WPM, _______,  _______,  _______,              _______,              RGB_RMOD,           _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    MO(WIN_FN2),_______,  RGB_MOD,  _______,  _______,            _______,  _______),
    [WIN_FN2] = LAYOUT_ansi_109(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_FN2]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif // ENCODER_MAP_ENABLE

// clang-format on

#include "hid_user.h"
#include "rgb_matrix_user_eeprom.h"

uint8_t wpm_history[50];
uint8_t wpm_history_index = 0;
uint8_t wpm_current_max = 0;
bool wpm_init = true;
uint8_t wpm_last_addition = 0;

uint8_t get_wpm_avg(void) {
	uint16_t wpm_sum = 0;
	uint8_t wpm_history_len = ARRAY_SIZE(wpm_history);
	if (wpm_init && wpm_history_index < wpm_history_len-1) {
		wpm_history_len = wpm_history_index;
		wpm_sum = wpm_history[wpm_history_index + 1];
	}
	for(uint8_t ii = 0; ii < wpm_history_len; ii++) {
		wpm_sum += wpm_history[ii];
	}
	return (uint8_t)(wpm_sum / wpm_history_len);
}

uint32_t run_wpm_history(uint32_t trigger_time, void *cb_arg) {
	if (get_current_wpm() == 0 || wpm_last_addition >= 10) {
		if (wpm_current_max > 10 && (get_wpm_avg()*0.5 <= wpm_current_max)) {// || wpm_init)) {
			// if (wpm_init) {
				// wpm_init = false;
				// for(uint8_t ii = 0; ii < sizeof(wpm_history)/sizeof(wpm_history[0]); ii++) {
					// wpm_history[ii] = wpm_current_max;
				// }
			// } else {
			wpm_history[wpm_history_index] = wpm_current_max;
			// }
			wpm_history_index++;
			if (wpm_history_index > 9) {
				wpm_init = false;
				wpm_history_index = 0;
			}
		}
		wpm_current_max = 0;
		wpm_last_addition = 0;
	} else {
		wpm_last_addition++;
	}
	// uprintf("WPM: %d [%d, %d, %d, %d, %d, %d, %d, %d, %d, %d] = %d\n", get_current_wpm(), wpm_history[0], wpm_history[1], wpm_history[2], wpm_history[3], wpm_history[4], wpm_history[5], wpm_history[6], wpm_history[7], wpm_history[8], wpm_history[9], get_wpm_avg());//get_wpm_avg());
    return 500;
}

void keyboard_post_init_user(void) {
	defer_exec(500, run_wpm_history, NULL);
	keyboard_post_init_user_rgb_matrix();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	// uprintf("WPM: %d\n", get_current_wpm());
	// uprintf("Key: %d\n", keycode);
	
	rgb_matrix_enable_noeeprom();
	
	if (get_current_wpm() > wpm_current_max) {
		wpm_current_max = get_current_wpm();
	}
	
	switch (keycode) {
        case USER_WPM:
            if (record->event.pressed) {
				// uint16_t wpm_sum = 0;
				// for(uint8_t ii = 0; ii < sizeof(wpm_history)/sizeof(wpm_history[0]); ii++) {
					// wpm_sum += wpm_history[ii];
				// }
				// uint16_t wpm_avg = (uint16_t)((float)wpm_sum / ARRAY_SIZE(wpm_history) * 10);
				// uprintf("WPM: %3d.%02d\n", wpm_avg/10, wpm_avg%10);
				// char wpm_str[7];
				// sprintf(wpm_str, "%d.%d", wpm_avg/10, wpm_avg%10);
				// SEND_STRING(wpm_str);
				
				// uint16_t wpm_sum = 0;
				// for(uint8_t ii = 0; ii < ARRAY_SIZE(wpm_history); ii++) {
					// wpm_sum += wpm_history[ii];
				// }
				// uint8_t wpm_avg = (uint8_t)((float)wpm_sum / ARRAY_SIZE(wpm_history));
				
				// uint8_t wpm_avg = get_wpm_avg();
				
				// uprintf("[%d, %d, %d, %d, %d, %d, %d, %d, %d, %d] = %d\n", wpm_history[0], wpm_history[1], wpm_history[2], wpm_history[3], wpm_history[4], wpm_history[5], wpm_history[6], wpm_history[7], wpm_history[8], wpm_history[9], get_wpm_avg());//get_wpm_avg());
				
				uint8_t wpm_history_len = ARRAY_SIZE(wpm_history);
				if (wpm_init && wpm_history_index < wpm_history_len-1) {
					wpm_history_len = wpm_history_index+1;
				}
				uprintf("[");
				for (size_t i = 0; i < (wpm_history_len-1); ++i) {
					uprintf("%d, ", wpm_history[i]);
				}
				uprintf("%d]", wpm_history[wpm_history_len-1]);
				uprintf(" = %d\n", get_wpm_avg());
				
				const char *wpm_avg_str = get_u8_str(get_wpm_avg(), ' ');
				while (*wpm_avg_str++ == ' ') {}
				wpm_avg_str--;
				send_string(wpm_avg_str);
            }
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
	
    if (!process_record_keychron(keycode, record)) {
        return false;
    }
    return true;
}

void housekeeping_task_user(void) {
    housekeeping_task_keychron();
}
