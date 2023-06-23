# Maintains this codebase

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c89

# Filename to be supplied from command line
BYTECODE_FILE := $(filename)

# Compiler flags with the `debug` build for checking memory leaks with `valgrind`
DEBUG_CFLAGS = -Wall -Werror -Wextra -pedantic -std=c89 -ggdb3

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

# Run a memory check using valgrind
MEM_CHECK = valgrind

# Log file for the results of memory check
LOG_FILE = valgrind-out.txt

# Flags for memory check
MC_FLAGS = --leak-check=full \
	   --show-leak-kinds=all \
	   --track-origins=yes \
	   --log-file=$(LOG_FILE) \

# Essential files: Don't use comma to separate arguments for wildcard
ESS_FILES = "$(wildcard README.md monty.h)"

# Temporary files: Vim, Emacs, and backup for aspell original files
TEMP = $(wildcard *.swp *~ *.bak)





# rules

# Makefile should not be compiled if Essential files are missing

ifneq ($(strip $(ESS_FILES)), "")

all: $(SRC)
	$(CC) $(CFLAGS) $? -o $(NAME)


.PHONY: with_debug \
	clean \
	check \
	ready \
	ready_and debug \
	betty_check \
	spell_check \
	mem_check


with_debug: $(SRC) # Uses the gcc debug build
	$(CC) $(DEBUG_CFLAGS) $? -o $(NAME)

mem_check: with_debug $(NAME) # Run test for memory leaks using a sample \
	bytcode file
	$(MEM_CHECK) $(MC_FLAGS) ./$(NAME) $(BYTECODE_FILE)

clean: # Clear the directory of all object codes, temporary files \
	and the executable
	$(RM) $(OBJ) $(NAME) $(TEMP) $(LOG_FILE)

betty_check: # Ensure all source files are betty compliant
	$(STYLE_CHECK) $(SRC) $(HEAD_FILES)

spell_check: $(SPELL_CHECK_FILES) # Ensure that these files are \
	grammatically correct
	$(foreach var,$?, $(SPELL_CHECK) $(SCFLAGS) $(var);)

check: betty_check spell_check # Run all checks

ready: clean check all # Ensure that code is ready to be submitted

ready_and_debug: clean check mem_check # Ensure code is error free and perfect

else

$(info "README.md or monty.h file(s) missing")

endif
