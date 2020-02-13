/*
** EPITECH PROJECT, 2018
** control l
** File description:
** my_42sh
*/

#include "input.h"

void	control_l(int key, int *s, edl_t *line, int *status)
{
	(void) status;
	if (key + 256 == 12 && *s == 0) {
		termx("cl");
		line->line = reset_line(line);
		clrdisp((*line));
		*s = 1;
	}
}