# Maintains this codebase

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c89

# Source files
SRC = $(wildcard *.c)

# Header files
HEAD_FILES = $(wildcard *.h)

# Object code
OBJ = $(SRC:.c=.o)

# Markdown files
MK_DOWN = $(wildcard *.md)

# Git ignore files
IGNORE_F = $(wildcard ./gitignore)

# Files to be tested by spelling check
SPELL_CHECK_FILES = $(SRC) $(HEAD_FILES) $(MK_DOWN) $(IGNORE_F)

# Name of executable
NAME = monty

# Style checker
STYLE_CHECK = betty

# Program for spelling errors
SPELL_CHECK = aspell

# Flags for English (en) language checker
SCFLAGS = check -l en

# Essential files: Don't use comma to separate arguments for wildcard
ESS_FILES = "$(wildcard README.md monty.h)"

# Temporary files: Vim, Emacs, and backup for aspell original files
TEMP = $(wildcard *.swp *~ *.bak)

# rules

# Makefile should not be compiled if Essential files are missing

ifneq ($(strip $(ESS_FILES)), "")

all: $(SRC)
	$(CC) $(CFLAGS) $? -o $(NAME)

.PHONY: clean check ready betty_check spell_check

clean: # Clear the directory of all object codes, temporary files \
	and the executable
	$(RM) $(OBJ) $(NAME) $(TEMP)

betty_check: # Ensure all source files are betty compliant
	$(STYLE_CHECK) $(SRC) $(HEAD_FILES)

spell_check: $(SPELL_CHECK_FILES) # Ensure that these files are \
	grammatically correct
	$(foreach var,$?, $(SPELL_CHECK) $(SCFLAGS) $(var);)

check: betty_check spell_check # Run all checks
ready: clean check all # Ensure that code is ready to be submitted

else
$(info "README.md or monty.h file(s) missing")

endif
