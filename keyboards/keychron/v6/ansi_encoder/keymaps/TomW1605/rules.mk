VIA_ENABLE = yes
ENCODER_MAP_ENABLE = yes
MIDI_ENABLE = no
MOUSEKEY_ENABLE = no
CONSOLE_ENABLE = yes
EXTRAKEY_ENABLE = yes
RGB_MATRIX_CUSTOM_USER = yes

VPATH += keyboards/keychron/common
SRC += keychron_common.c

SRC += rgb_matrix_user_hid.c
