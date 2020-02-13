/*
** EPITECH PROJECT, 2018
** init term
** File description:
** my_42sh
*/

#include "input.h"

void 	init_term(edl_t *line)
{
	line->line = malloc(sizeof(char) * 1);
	line->line[0] = '\0';
	line->pc = 0;
	line->his = NULL;
	fcntl(0, F_SETFL, O_NONBLOCK);
	tgetent(NULL, getenv("TERM"));
	enable_termcaps(1);
}