# rat
CC = g++
FILES = main.cpp file.cpp cli.cpp
NAME = rat
FLAGS = -lncurses
DIR = /usr/bin

build:
	$(CC) $(FLAGS) $(FILES) -o $(NAME)

install:
	make build
	cp -f $(NAME) $(DIR)/$(NAME)
	echo Successfully installed reader-at.

uninstall:
	rm -f $(NAME) $(DIR)/$(NAME)
	echo Successfully uninstalled reader-at.