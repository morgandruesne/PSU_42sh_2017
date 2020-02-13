/*
** EPITECH PROJECT, 2018
** handling line
** File description:
** my_sh2
*/

#include "input.h"

void	key_handling_line(int key, edl_t *line, int *state, char *c)
{
	if (key == -129 && line->pc > 0 && *state == 0) {
		line->pc--;
		line->line = supr_letter(line->line, line->pc);
		termx("le");
		clrdisp((*line));
		*state = 1;
	}
	(*c) = key % 256;
	if (*c >= 32 && *c <= 126 && *state == 0) {
		line->line = add_letter(line->line, *c, line->pc);
		line->pc++;
		termx("nd");
		clrdisp((*line));
		*state = 1;
	}
}

void	key_handling_move_line(int key, int *s, edl_t *l)
{
	if (key == -12297445 && l->pc > 0 && *s == 0) {
		left();
		l->pc--;
		*s = 1;
	}
	if (key == -12362981 && l->pc < my_strlen(l->line) && *s == 0) {
		right();
		l->pc++;
		*s = 1;
	}
}

int	key_handling_valid_line(char *c, int *state, core_t *cor, edl_t *line)
{
	if (*c == '\n' && *state == 0) {
		write(1, "\n", 1);
		while (line->his != NULL && line->his->prev != NULL)
			line->his = line->his->prev;
		if (line->line[0] != '\0') {
			line->his = add_line_history(line->line, line->his);
			cor->cmd.input = strdup(line->line);
			executer(cor);
		}
		line->line = reset_line(line);
		*state = 1;
		return (1);
	}
	return (0);
}

char 	*reset_line(edl_t *line)
{
	free(line->line);
	line->line = NULL;
	line->line = malloc(sizeof(char) * 1);
	line->line[0] = '\0';
	line->pc = 0;
	return (line->line);
}