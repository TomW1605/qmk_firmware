#include "print.h"

#include "rgb_matrix_user_hid.h"

//void raw_hid_receive(uint8_t *data, uint8_t length) {
//    // Your code goes here
//    // `data` is a pointer to the buffer containing the received HID report
//    // `length` is the length of the report - always `RAW_EPSIZE`
//	if (*data == 0x40) {
//		print("0x40");
//	} else if (*data == 0x41) {
//		print("0x41");
//	}
//}

enum via_test_value {
    id_test   = 1
};

void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id        = &(data[0]);
    uint8_t *channel_id        = &(data[1]);
    //uint8_t *value_id          = &(data[2]);
    uint8_t *value_data        = &(data[3]);
	
	if (*channel_id == 6) {
        custom_qmk_rgb_matrix_command(data, length);
        return;
    }

    if ( *channel_id == 0 ) {
        switch ( *command_id )
        {
            case id_custom_set_value:
            {
                uprint("set\n");
                uprintf("0x%04X\n", *value_data);
				if (*value_data) {
					rgb_matrix_enable_noeeprom();
				} else {
					rgb_matrix_disable_noeeprom();
				}
                break;
            }
            case id_custom_get_value:
            {
                uprint("get\n");
                break;
            }
            case id_custom_save:
            {
                uprint("save\n");
                break;
            }
            default:
            {
                // Unhandled message.
                *command_id = id_unhandled;
                break;
            }
        }
        return;
    }

    // Return the unhandled state
    *command_id = id_unhandled;

    // DO NOT call raw_hid_send(data,length) here, let caller do this
}