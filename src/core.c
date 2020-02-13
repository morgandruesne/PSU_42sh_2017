/*
** EPITECH PROJECT, 2018
** core
** File description:
** my_42sh
*/

#include "input.h"

void	reset_save(char **save, char *new)
{
	if (*save != NULL)
		free(*save);
	*save = NULL;
	*save = strdup(new);
}

void	execute_core(core_t *cor, int i)
{
	if (cor->cmd.input != NULL) {
		if (i != 0)
			my_printf("%s\n", cor->cmd.input);
		cor->qm = add_qmark(cor->qm, cor->cmd.input);
		executer(cor);
	}
}

void	execute_qmark(core_t *cor, int *i)
{
	int n = -1;
	char *save = NULL;

	while ((n = presence_char(cor->cmd.input, '!')) != -1 && 
	cor->cmd.input != NULL) {
		reset_save(&save, cor->cmd.input);
		cor->cmd.input = qmark(cor, cor->cmd.input, n);
		if (my_strcmp_2(cor->cmd.input, save) == 0)
			break;
		(*i)++;
	}
}

void	core(core_t *cor)
{
	int i = 0;

	prompt();
	if ((cor->cmd.input = get_next_line(0)) != NULL) {
		execute_qmark(cor, &i);
		execute_core(cor, i);
	} else
		ctrl_d(cor->cmd.is_ok);
}