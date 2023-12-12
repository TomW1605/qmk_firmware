#pragma once

#include "print.h"
#include <lib/lib8tion/lib8tion.h>
#include <quantum/rgb_matrix/rgb_matrix.h>
// #include <quantum/rgb_matrix/rgb_matrix_types.h>
#include <quantum/via.h>

void custom_qmk_rgb_matrix_command(uint8_t *data, uint8_t length);
void custom_qmk_rgb_matrix_set_value(uint8_t *data);
void custom_qmk_rgb_matrix_get_value(uint8_t *data);
void custom_qmk_rgb_matrix_save(void);
