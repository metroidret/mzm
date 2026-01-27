# Make rules to build the tools used for compilation, inside `tools` folder.
ifeq ($(V),1)
	Q =
	MSG = @:
else
	Q = @
	MSG = @echo " "
endif

MAKEFLAGS += --no-print-directory

TOOLS_DIR := tools
# Tool executables to build
TOOLS := gbafix preproc

TOOLDIRS := $(TOOLS:%=$(TOOLS_DIR)/%)

.PHONY: tools clean-tools $(TOOLDIRS)

tools: $(TOOLDIRS)

$(TOOLDIRS):
	$Q$(MAKE) -C $@

clean-tools:
	$Q$(foreach tooldir, $(TOOLDIRS), $(MAKE) clean -C $(tooldir);)
