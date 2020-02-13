/*
** EPITECH PROJECT, 2018
** control d
** File description:
** my_42sh
*/

#include "input.h"

void	control_d(int key, int *s, edl_t *line, int *status)
{
	(void)status;
	if (key + 256 == 4 && *s == 0) {
		if (line->line[0] == 0) {
			enable_termcaps(0);
			printf("exit\n");
			exit(0);
			*s = 1;
		} else if (line->line[line->pc] == 0 && 
		line->pc != 0 && *s != 1) {
			write(1, "\n", 1);
			color_prompt();
			write(1, line->line, strlen(line->line));
			*s = 1;
		} else if (line->line[line->pc] != 0 && *s != 1) {
			line->line = supr_letter(line->line, line->pc);
			clrdisp((*line));
			*s = 1;
		}
	}
}