##
## EPITECH PROJECT, 2022
## Makefile général
## File description:
## Makefile
##

CC = gcc -g3
CFLAGS = -W -Wall
CPPFLAGS = -I./include

SRC = $(wildcard src/*.c) \
	  $(wildcard src/commands/*.c)

OBJ = $(SRC:.c=.o)

BIN = mysh

all: $(BIN)

$(BIN): $(OBJ)
	make -C lib/ libmy.a
	$(CC) -o $(BIN) $(OBJ) -lmy -L./lib/

clean:
	make -C lib/ clean
	$(RM) $(OBJ)

fclean: clean
	make -C lib/ fclean
	$(RM) $(BIN)

re: fclean all
