CXX ?= g++
RM ?= rm -f
ifeq ($(V),1)
	Q =
	MSG = @:
else
	Q = @
	MSG = @echo " "
endif

CXXFLAGS := -std=c++11 -O2 -Wall -Wno-switch -Werror

SRCS := asm_file.cpp c_file.cpp charmap.cpp preproc.cpp string_parser.cpp \
	utf8.cpp

HEADERS := asm_file.h c_file.h char_util.h charmap.h preproc.h string_parser.h \
	utf8.h

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

.PHONY: all clean

all: preproc$(EXE)
	@:

preproc$(EXE): $(SRCS) $(HEADERS)
	$(MSG) CXX $@
	$Q$(CXX) $(CXXFLAGS) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(MSG) RM preproc$(EXE)
	$Q$(RM) preproc preproc.exe
