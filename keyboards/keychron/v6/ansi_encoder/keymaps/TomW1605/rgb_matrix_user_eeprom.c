#include "rgb_matrix_user_eeprom.h"

void eeconfig_save_rgb_matrix_custom(void) {
	eeconfig_update_user(rgb_matrix_config_custom.raw);
}

void keyboard_post_init_user_rgb_matrix(void) {
  // Call the keymap level matrix init.

  // Read the user config from EEPROM
  rgb_matrix_config_custom.raw = eeconfig_read_user();

  // Set default layer, if enabled
  // if (user_config.rgb_layer_change) {
    // rgblight_enable_noeeprom();
    // rgblight_sethsv_noeeprom(HSV_CYAN);
    // rgblight_mode_noeeprom(1);
  // }
}

void eeconfig_init_user(void) {  // EEPROM is getting reset!
  rgb_matrix_config_custom.raw = 0;
  rgb_matrix_config_custom.hsv.h = 0; // We want this enabled by default
  rgb_matrix_config_custom.hsv.s = 255;
  rgb_matrix_config_custom.hsv.v = 255;
  eeconfig_update_user(rgb_matrix_config_custom.raw); // Write default value to EEPROM now

  // use the non noeeprom versions, to write these values to EEPROM too
  // rgblight_enable(); // Enable RGB by default
  // rgblight_sethsv(HSV_CYAN);  // Set it to CYAN by default
  // rgblight_mode(1); // set to solid by default
}
