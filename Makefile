CC = clang

BINARY = ./bin/renderers
SRCDIR = ./src
BUILDDIR = ./build

CFILES = $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/**/*.c)
OBJFILES = $(patsubst $(SRCDIR)%.c,$(BUILDDIR)%.o,$(CFILES))
DEPFILES= $(patsubst $(SRCDIR)%.c,$(BUILDDIR)%.d,$(CFILES))

# The -MMD flags additionaly creates a .d file with
# the same name as the .o file.
CC_ASSEMBLER_FLAGS = -Wall -Wextra -MMD

all: $(BINARY)

$(BINARY): $(OBJFILES)
	@mkdir -p $(dir $@)
	$(CC) -o $@ $^

# only want the .c file dependency here, thus $< instead of $^.
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CC_ASSEMBLER_FLAGS) -c -o $@ $<
	
run: $(BINARY)
	$^

open: run
	open canvas.ppm -a Preview

clean:
	rm -rf $(BINARY) $(BUILDDIR)/*

# include the dependencies, will regenerate .o when .h file changes
-include $(DEPFILES)

# add .PHONY so that the non-targetfile - rules work even if a file with the same name exists.
.PHONY: all run clean