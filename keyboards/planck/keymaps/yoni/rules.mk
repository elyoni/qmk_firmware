#VIA_ENABLE = yes
#LTO_ENABLE = yes
ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

MOUSEKEY_ENABLE = yes
CONSOLE_ENABLE = no
