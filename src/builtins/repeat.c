/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

int	repeat_error_handling(char **param)
{
	if (my_tablen(param) < 3) {
		my_printf("repeat: Too few arguments.\n");
		return (1);
	}
	if (my_str_isnum(param[1]) == 1) {
		my_printf("repeat: Badly formed number.\n");
		return (1);
	}
	return (0);
}

int	repeat_builtin(core_t *cor, char **param)
{
	int nb_loop = 0;

	if (repeat_error_handling(param) == 1)
		return (1);
	nb_loop = atoi(param[1]);
	cor->cmd.input = get_new_cmd(param);
	for (; nb_loop > 0; nb_loop--)
		executer(cor);
	return (0);
}
