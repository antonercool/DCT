CONTIKI_PROJECT = dct_transformer
all: $(CONTIKI_PROJECT)

CONTIKI = ../contiki-ng
TARGET_LIBFILES += -lm
MAKE_NET = MAKE_NET_NULLNET
include $(CONTIKI)/Makefile.include
