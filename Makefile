##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile du printf
##


CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -I./include -L./lib -lmy -pedantic -g3 -lcurses

SRC	=	src/main.c			\
		src/browse_main.c		\
		src/init/init.c			\
		src/execute.c			\
		src/signals.c			\
		src/builtins/builtin_tools.c	\
		src/builtins/env.c		\
		src/builtins/setenv.c		\
		src/builtins/unsetenv.c		\
		src/builtins/cd.c		\
		src/builtins/foreach.c		\
		src/builtins/foreach_1.c	\
		src/builtins/foreach_2.c	\
		src/builtins/foreach_3.c	\
		src/builtins/cd_tools.c		\
		src/builtins/exit.c		\
		src/builtins/echo.c		\
		src/builtins/alias.c		\
		src/builtins/sort_alias.c	\
		src/builtins/browse_alias.c	\
		src/builtins/unalias.c		\
		src/builtins/where.c		\
		src/builtins/which.c		\
		src/builtins/repeat.c		\
		src/builtins/set.c		\
		src/builtins/unset.c		\
		src/builtins/browse_set.c	\
		src/binary_tree/parser.c	\
		src/binary_tree/parser_2.c	\
		src/binary_tree/lexer.c		\
		src/binary_tree/reader.c	\
		src/binary_tree/binary_tools.c	\
		src/operator/semicolon.c	\
		src/operator/pipe.c		\
		src/operator/right.c		\
		src/operator/double_right.c	\
		src/operator/left.c		\
		src/operator/double_left.c	\
		src/operator/and.c		\
		src/operator/or.c		\
		src/backstick.c			\
		src/edit_line/handling_line.c \
		src/edit_line/termcaps.c \
		src/edit_line/history.c \
		src/letter_str.c \
		src/edit_line/history_node_functions.c \
		src/control_functions/control_l.c \
		src/control_functions/control_c.c \
		src/control_functions/control_d.c \
		src/init/init_term.c \
		src/edit_line/clear_and_disp.c \
		src/edit_line/key_handling.c \
		src/init/init_core.c \
		src/history_qmark/qmark_node.c \
		src/strc.c \
		src/wildcard/globbing_wildcard.c \
		src/wildcard/pathern_wildcard.c \
		src/history_qmark/qmark.c \
		src/presence_char.c \
		src/replace_word.c \
		src/core.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		rm -f $(OBJ)
		make -C ./lib/my clean

fclean:		clean
		make -C ./lib/my fclean
		rm -f $(NAME)

test:
		make -C ./exec

re:		fclean all
