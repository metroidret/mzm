CC ?= gcc
RM ?= rm -f
ifeq ($(V),1)
	Q =
	MSG = @:
else
	Q = @
	MSG = @echo " "
endif

.PHONY: all clean

SRCS = gbafix.c

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

all: gbafix$(EXE)
	@:

gbafix$(EXE): $(SRCS)
	$(MSG) CC $@
	$Q$(CC) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(MSG) RM gbafix$(EXE)
	$Q$(RM) gbafix gbafix.exe
