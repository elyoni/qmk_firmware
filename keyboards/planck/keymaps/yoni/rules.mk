#VIA_ENABLE = yes
#LTO_ENABLE = yes
ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

CONSOLE_ENABLE = no
