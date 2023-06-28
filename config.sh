#!/bin/env bash

## Copyright (c) 2023 Onwuta Ebube Gideon, All Rights Reserved   ##
## 								 ##
## 								 ##
## This software falls under the MIT LICENSE                     ##
## Please read the LICENSE file for more information             ##
##
## --- Onwuta Ebube Gideon <onwutaebubegideon1555@gmail.com> --- ##



# # # # # # # # # # # # # # # # # # # #                          
# Make $NAME versatile in the system  #
# # # # # # # # # # # # # # # # # # # #                          



# Name of executable
NAME=monty

# Directory for executable
EXEC_DIR=/usr/bin

SCRIPT=$0
CMD=$1
FLAG=$2

INSTALL_CMD="install"
UNINSTALL_CMD="uninstall"
FORCE_FLAG="force"

# Colors: to be used as ${COLOR_NAME}
RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m'	# No color. Should end a colored string


# Functions

# Display to stderr
_display () {
	echo "$@" >&2
}

install_file () {
	FILE=$1
	LOCATION=$2

	if [ -e "$FILE" ]; then
		sudo mv --update "$FILE" "$LOCATION"
		_display  "${GREEN}$FILE${NC} successfully installed in ${CYAN}$LOCATION${NC}";
	else
		_display  "${RED}No executable $NAME program found in this directory${NC}"
		_display "Run '${GREEN}make${NC}' before installing with '${GREEN}$SCRIPT $INSTALL_CMD${NC}'";
	fi
}

uninstall_file () {
	FILE=$1
	LOCATION=$2

	if [ -e "$LOCATION/$FILE" ]; then
		sudo rm "$LOCATION/$FILE"
		_display  "${GREEN}$LOCATION/$FILE${NC} successfully uninstalled";
	else
		_display  "No need to uninstall it. ${CYAN}$FILE${NC} doesn't exist in ${CYAN}$LOCATION${NC}";
	fi
}

# Ensure binary file is not kept in this directory
clean_up () {
	if [ -e "$NAME" ]; then
		rm "$NAME"
	fi
}



# Main execution

if [ "$CMD" = "$INSTALL_CMD" ]; then

	# Ensure previous version is not overwritten without notice
	if [ "$FLAG" = "$FORCE_FLAG" ]; then
		install_file "$NAME" "$EXEC_DIR"
		clean_up
		exit
	fi

	if [ -e "$EXEC_DIR"/"$NAME" ]; then
		{
			_display  "${GREEN}$NAME${NC} is already installed in ${GREEN}$EXEC_DIR${NC}.";
			while true; do
				read -r -p "Do you want to overwrite existing version of $NAME? (y/n) " yn
				case $yn in
					[yY] ) install_file "$NAME" "$EXEC_DIR"; break;;
					[nN] ) _display "exiting"; break;;
					*) _display "invalid response";;
				esac
			done;
		}
		clean_up
		exit
	else
		install_file "$NAME" "$EXEC_DIR"
	fi


elif [ "$CMD" = "$UNINSTALL_CMD" ]; then

	uninstall_file "$NAME" "$EXEC_DIR"

else
	_display  "${RED}Inappropriate command${NC}"
	_dispaly  "You can run '${CYAN}$SCRIPT $INSTALL_CMD${NC}' or '${CYAN}$SCRIPT $UNINSTALL_CMD${NC}'";
fi

clean_up
