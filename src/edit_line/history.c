/*
** EPITECH PROJECT, 2018
** history
** File description:
** my_42sh
*/

#include "input.h"

void	move_up_history(edl_t *ln)
{
	if (ln->his->prev == NULL && 
	my_strcmp_2(ln->line, ln->his->data) == 1) {
		ln->line = strdup(ln->his->data);
	} else {
		reset_ind_his(ln);
		ln->his = (!(!ln->his->next)) ? ln->his->next : ln->his;
		ln->line = strdup(ln->his->data);
	}
	for (unsigned int i = ln->pc; i < strlen(ln->line); i++)
		termx("nd");
	for (unsigned int i = ln->pc; i > strlen(ln->line); i--)
		termx("le");
	ln->pc = (strlen(ln->line));
	clrdisp((*ln));
	ln->pc = (strlen(ln->line));
}

void	move_down_history(edl_t *ln)
{
	if (ln->his->prev == NULL && 
	(my_strcmp_2(ln->line, ln->his->data) == 0 || 
	my_strcmp_2(ln->line, "\0") == 0)) {
		ln->line = reset_line(ln);
	} else {
		ln->his = (!(!ln->his->prev)) ? ln->his->prev : ln->his;
		ln->line = strdup(ln->his->data);
	}
	for (unsigned int i = ln->pc; i < strlen(ln->line); i++)
		termx("nd");
	for (unsigned int i = ln->pc; i > strlen(ln->line); i--)
		termx("le");
	ln->pc = (strlen(ln->line));
	clrdisp((*ln));
	ln->pc = (strlen(ln->line));
}

void	key_handling_move_history(int key, edl_t *line, int *s)
{
	if (key == -12494053 && line->his != NULL && *s == 0) {
		move_up_history(line);
		*s = 1;
	}
	if (key == -12428517 && line->his != NULL && *s == 0) {
		move_down_history(line);
		*s = 1;
	}
}

void	reset_ind_his(edl_t *line)
{
	if (my_strcmp_2(line->line, line->his->data) == -1) {
		while (line->his->prev != NULL)
			line->his = line->his->prev;
	}
}