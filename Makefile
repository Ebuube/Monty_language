# Maintains this codebase
# =======================
#
# USAGE
# =====
#
# This Makefile does a lot of work on maintaining the codebase
# 1) You can simply build the executable using
# 	```
# 	make
# 	```
#
# 2) To compile the executable using the `-gddb3` build to enable `valgrind`
#	track source of error in codebase
#	```
#	make with_debug
#	```
#
# 3) To compile source code and run a memory leak check using a sample \
#	bytecode file
# 	```
# 	make mem_check filename=path_to_file
# 	```
# 	Where, `path_to_file` is the absolute/relative path to a bytecode file
# 	Note!: You have to investigate the $(LOG_FILE) after running this command
#
# 4) To clean the directory and remove unnecessary files along with the executable
#	```
#	make clean
#	```
#
# 5) To ensure that all C source files are `betty` compliant
#	```
#	make betty_check
#	```
#
# 6) To ensure that the codebase is grammatically spelling-error proof (English)
#	```
#	make spell_check
#	```
#	This enables you to go through the codebase and make spelling changes.
#	Note!: You must have the `aspell` program installed on your system before
#	you can make use of this target. Install it using
#	```
#	$ sudo apt update
#	$ sudo apt install -y aspell
#	```
#
# 7) To run both betty_check and spell_check use this target
#	```
#	make check
#	```
#	Look up how to use `spell_check` and `betty_check` to learn the dependencies
#
# 8) To ensure code is ready to be submitted without checking on memory leaks
#	```
#	make ready
#	```
#
# 9) To ensure code is ready to be submitted and run a check on memory leaks
#	```
#	make ready_and_debug filename=path_to_file
#	```
#	Where `path_to_file` is the absolute/relative path to a bytecode file
#	Note!: you have to investigate the $(LOG_FILE) after running this command
#
#
# DEPENDENCIES
# ============
# To use some targets, you need to have these programs/utilities.
# 1) To use this Makefile or the target 'all, you must have the 'make'
# 	utility installed. Check out
# 	make -> https://www.gnu.org/s/make/manual/make.html
#
# 2) To use the 'betty_check' target, you must have 'betty' configured on your
# 	system. Find Betty -> https://github.com/alx-tools/Betty
#
# 3) To use the 'spell_check' target, you must have 'aspell' installed on your
# 	system. Find Aspell -> https://howtoinstall.co/en/aspell
#
# 4) To make use of 'check' target you must satisfy the dependencies of
# 	'betty_check' and 'spell_check'
#
# 5) To make use of 'mem_check' ensure you 'valgrind' installed on you system.
# 	Find 'valgrind' -> https://wiki.ubuntu.com/Valgrind
#
# 6) To make use of the 'with_debug' target, you must satisfy the dependencies of
# 	'mem_check' and 'all'.
#
# 7) To make use 'ready' target, you must satisfy the dependencies for 'clean',
# 	'check' and 'all' target
#
# 8) To make use of the 'clean' target, does not require any dependency.



# Variables
# =========

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
	bytecode file
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
