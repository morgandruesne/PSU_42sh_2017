##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile lib
##

CC	= 	gcc

CFLAGS	= 	-Wall -Wextra -W -pedantic -I ../../include/ -g3

SRC	=	my_putchar.c		\
		my_putnbr.c		\
		my_putstr.c		\
		my_strlen.c		\
		my_tablen.c		\
		my_getnbr.c		\
		my_pow.c		\
		my_sqrt.c		\
		my_revstr.c		\
		my_strcmp.c		\
		my_strncmp.c		\
		my_strcat.c		\
		my_strdup.c		\
		my_str_to_word_array.c	\
		my_str_cleaner.c	\
		my_get_next_line.c	\
		my_printf.c		\
		my_fprintf.c		\
		my_str_isnum.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		mv $(NAME) ../

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f ../$(NAME)

re:		fclean all
