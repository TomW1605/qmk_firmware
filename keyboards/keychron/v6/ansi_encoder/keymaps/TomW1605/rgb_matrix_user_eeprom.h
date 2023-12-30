#pragma once

// #include <quantum/rgb_matrix/rgb_matrix.h>
#include <quantum/color.h>
#include <quantum/eeconfig.h>

typedef union {
  uint32_t raw;
  struct {
	HSV hsv;
  };
} rgb_config_custom_t;

rgb_config_custom_t rgb_matrix_config_custom;

void eeconfig_save_rgb_matrix_custom(void);
void keyboard_post_init_user_rgb_matrix(void);
void eeconfig_init_user(void);
