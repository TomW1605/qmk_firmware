RGB_MATRIX_EFFECT(reactive_dual_colour)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

extern rgb_config_t rgb_matrix_config_custom;


// e.g: A more complex effect, relying on external methods and state, with
// dedicated init and run methods
//static uint8_t some_global_state;
//static void reactive_dual_colour_init(effect_params_t* params)
//{
//	uprint("reactive_dual_colour_init\n");
//	some_global_state = 1;
//}
//
//static bool reactive_dual_colour_run(effect_params_t* params)
//{
//	uprint("reactive_dual_colour_run\n");
//	RGB_MATRIX_USE_LIMITS(led_min, led_max);
//	for (uint8_t i = led_min; i < led_max; i++)
//	{
//		rgb_matrix_set_color(i, 0xff, some_global_state++, 0xff);
//	}
//	return rgb_matrix_check_finished_leds(led_max);
//}

// long map(long x, long in_min, long in_max, long out_min, long out_max) {
//   return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
// }
// 
// static RGB accent_colour;
// static void reactive_dual_colour_init(effect_params_t* params)
// {
// 	//purple = {290,94,47};
// 	//HSV hsv;
//     //hsv.h = (290 / 360) * 255;
//     //hsv.s = 94;// / 100) * 255;
//     //hsv.v = 47;// / 100) * 255;
// 	// base_colour.r = 128;
// 	// base_colour.g = 0;
// 	// base_colour.b = 255;
// 	// base_colour = rgb_matrix_hsv_to_rgb(rgb_matrix_get_hsv());
// 	// uprintf("base_colour:   RGB(%03u, %03u, %03u)\n", base_colour.r, base_colour.b, base_colour.g);
// 	
// 	//yellow = {52,96,97};
//     //hsv.h = (52 / 360) * 255;
//     //hsv.s = (96 / 100) * 255;
//     //hsv.v = (97 / 100) * 255;
//     // accent_colour = rgb_matrix_hsv_to_rgb(hsv);
// 	accent_colour.r = 255;
// 	accent_colour.g = 220;
// 	accent_colour.b = 0;
// 	uprintf("accent_colour: RGB(%03u, %03u, %03u)\n", accent_colour.r, accent_colour.b, accent_colour.g);
// }

typedef RGB (*reactive_f_RGB)(HSV hsv, uint16_t offset);

bool effect_runner_reactive_dual_colour(effect_params_t* params, reactive_f_RGB effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint16_t max_tick = 65535 / qadd8(rgb_matrix_config.speed, 1);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        uint16_t tick = max_tick;
        // Reverse search to find most recent key hit
        for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
            if (g_last_hit_tracker.index[j] == i && g_last_hit_tracker.tick[j] < tick) {
                tick = g_last_hit_tracker.tick[j];
                break;
            }
        }

        uint16_t offset = scale16by8(tick, qadd8(rgb_matrix_config.speed, 1));
        RGB      rgb    = effect_func(rgb_matrix_config.hsv, offset);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

static RGB reactive_dual_colour_math(HSV hsv, uint16_t offset) {
	// if (offset != 255) {
		// uprintf("0x%02X\n", offset);
	// }
    //hsv.h = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4);
    //hsv.h += qsub8(rgb_matrix_config.speed, offset); scale8
	
	RGB base_colour = rgb_matrix_hsv_to_rgb(hsv);
	RGB accent_colour = rgb_matrix_hsv_to_rgb(rgb_matrix_config_custom.hsv);
	RGB new_colour;
	// if (accent_colour.r > base_colour.r) {
		// current_colour.r -= scale8(qsub8(accent_colour.r, base_colour.r), offset);
	// } else {
		// current_colour.r += scale8(qsub8(base_colour.r, accent_colour.r), offset);
	// }
	// if (accent_colour.g > base_colour.g) {
		// current_colour.g -= scale8(qsub8(accent_colour.g, base_colour.g), offset);
	// } else {
		// current_colour.g += scale8(qsub8(base_colour.g, accent_colour.g), offset);
	// }
	// if (accent_colour.b > base_colour.b) {
		// current_colour.b -= scale8(qsub8(accent_colour.b, base_colour.b), offset);
	// } else {
		// current_colour.b += scale8(qsub8(base_colour.b, accent_colour.b), offset);
	// }
	
	if(accent_colour.r>base_colour.r) {
		new_colour.r = qadd8(base_colour.r, scale8(qsub8(accent_colour.r ,base_colour.r), qsub8(255, offset)));
	} else {
		new_colour.r = qsub8(base_colour.r, scale8(qsub8(base_colour.r, accent_colour.r), qsub8(255, offset)));
	}
	if(accent_colour.g>base_colour.g) {
		new_colour.g = qadd8(base_colour.g, scale8(qsub8(accent_colour.g ,base_colour.g), qsub8(255, offset)));
	} else {
		new_colour.g = qsub8(base_colour.g, scale8(qsub8(base_colour.g, accent_colour.g), qsub8(255, offset)));
	}
	if(accent_colour.b>base_colour.b) {
		new_colour.b = qadd8(base_colour.b, scale8(qsub8(accent_colour.b ,base_colour.b), qsub8(255, offset)));
	} else {
		new_colour.b = qsub8(base_colour.b, scale8(qsub8(base_colour.b, accent_colour.b), qsub8(255, offset)));
	}
	
	// if (offset != 255) {
		// uprintf("0x%02X\n", offset);
		// uprintf("current_colour: RGB(%03u, %03u, %03u)\n", current_colour.r, current_colour.g, current_colour.b);
	// }
	
	// current_colour.r = base_colour.r+((accent_colour.r-base_colour.r) * (offset / 256));
	// current_colour.g = base_colour.g+((accent_colour.g-base_colour.g) * (offset / 256));
	// current_colour.b = base_colour.b+((accent_colour.b-base_colour.b) * (offset / 256));

    return new_colour;

	// if (offset != 255) {
		// return accent_colour;
	// }
    // return base_colour;
}

static bool reactive_dual_colour(effect_params_t* params) {
	// if (params->init)
	// {
 		// reactive_dual_colour_init(params);
  	// }
    return effect_runner_reactive_dual_colour(params, &reactive_dual_colour_math);
}

//static bool reactive_dual_colour(effect_params_t* params) {
//	uprint("reactive_dual_colour\n");
//
//    RGB_MATRIX_USE_LIMITS(led_min, led_max);
//
//    uint16_t max_tick = 65535 / qadd8(rgb_matrix_config.speed, 1);
//    for (uint8_t i = led_min; i < led_max; i++) {
//        RGB_MATRIX_TEST_LED_FLAGS();
//        uint16_t tick = max_tick;
//        // Reverse search to find most recent key hit
//        for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
//            if (g_last_hit_tracker.index[j] == i && g_last_hit_tracker.tick[j] < tick) {
//                tick = g_last_hit_tracker.tick[j];
//                break;
//            }
//        }
//
//        //uint16_t offset = scale16by8(tick, qadd8(rgb_matrix_config.speed, 1));
//		
//        RGB      rgb    = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);
//		
//		rgb.r -= 1;
//		rgb.g -= 1;
//		rgb.b -= 1;
//		
//        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
//    }
//    return rgb_matrix_check_finished_leds(led_max);
//	
//	
//	//if (params->init)
//	//{
//	//	reactive_dual_colour_init(params);
//	//}
//	//return reactive_dual_colour_run(params);
//}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS;;;;;;;;;;;;;;;fffffffff