/*
** EPITECH PROJECT, 2018
** control c
** File description:
** my_42sh
*/

#include "input.h"

void	control_c(int key, int *s, edl_t *line, int *status)
{
	if (key + 256 == 3 && *s == 0) {
		(*status) = 0;
		write(1, "\n", 1);
		line->line = reset_line(line);
		*s = 1;
	}
}