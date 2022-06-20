##
## EPITECH PROJECT, 2021
## my_runner
## File description:
## makefile lib
##

CC = gcc -g3
CFLAGS = -W -Wall -Wextra -Werror
CPPFLAGS = -I./include

SRC = my_calloc.c \
	  my_intlen.c \
	  my_itoa.c \
	  my_printf.c \
	  my_put_nbr.c \
	  my_putchar.c \
	  my_putstr.c \
	  my_str_isupper.c \
	  my_str_to_word_array.c \
	  my_strcat.c \
	  my_strcmp.c \
	  my_strdup.c \
	  my_strlen.c \
	  my_strndup.c \
	  my_strupcase.c \
	  str_isalpha.c \
	  str_isnum.c \
	  is_alpha.c \
	  is_num.c \
	  str_non_alpha.c \
	  is_non_alpha.c \
	  error.c \
	  clear_string.c \

OBJ = $(SRC:.c=.o)

LIB = libmy.a

all: $(LIB)

$(LIB): $(OBJ)
	$(CC) -c $(SRC)
	$(AR) src $(LIB) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(LIB)

re: fclean all
