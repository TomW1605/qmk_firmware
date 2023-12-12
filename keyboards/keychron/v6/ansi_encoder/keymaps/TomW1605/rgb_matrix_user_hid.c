#include "rgb_matrix_user_hid.h"

rgb_config_t rgb_matrix_config_custom;

enum custom_qmk_rgb_matrix_value {
    id_qmk_rgb_matrix_accent_brightness = 1,
    id_qmk_rgb_matrix_accent_color      = 4,
};

void custom_qmk_rgb_matrix_command(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id        = &(data[0]);
    uint8_t *value_id_and_data = &(data[2]);

    switch (*command_id) {
        case id_custom_set_value: {
            custom_qmk_rgb_matrix_set_value(value_id_and_data);
            break;
        }
        case id_custom_get_value: {
            custom_qmk_rgb_matrix_get_value(value_id_and_data);
            break;
        }
        case id_custom_save: {
            custom_qmk_rgb_matrix_save();
            break;
        }
        default: {
            *command_id = id_unhandled;
            break;
        }
    }
}

void custom_qmk_rgb_matrix_set_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);
    switch (*value_id) {
        case id_qmk_rgb_matrix_accent_brightness: {
            rgb_matrix_config_custom.hsv.v = scale8(value_data[0], RGB_MATRIX_MAXIMUM_BRIGHTNESS);
            break;
        }
        case id_qmk_rgb_matrix_accent_color: {
			rgb_matrix_config_custom.hsv.h = value_data[0];
			rgb_matrix_config_custom.hsv.s = value_data[1];
            // rgb_matrix_sethsv_noeeprom(value_data[0], value_data[1], rgb_matrix_get_val());
            break;
        }
    }
}

void custom_qmk_rgb_matrix_get_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch (*value_id) {
        case id_qmk_rgb_matrix_accent_brightness: {
            value_data[0] = ((uint16_t)rgb_matrix_config_custom.hsv.v * UINT8_MAX) / RGB_MATRIX_MAXIMUM_BRIGHTNESS;
            break;
        }
        case id_qmk_rgb_matrix_accent_color: {
            value_data[0] = rgb_matrix_config_custom.hsv.h;
            value_data[1] = rgb_matrix_config_custom.hsv.s;
            break;
        }
    }
}

void custom_qmk_rgb_matrix_save(void) {
    eeconfig_update_rgb_matrix();
}