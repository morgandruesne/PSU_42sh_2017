/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

int	unalias_builtin(core_t *cor, char **param)
{
	alias_t *head = cor->alias;

	if (my_tablen(param) == 1) {
		my_printf("unalias: Too few arguments.\n");
		return (1);
	}
	for (int i = 1; param[i]; i++) {
		if (my_strcmp(cor->alias->alias, param[i]) == 0) {
			remove_alias_first(head, cor->alias);
		} else
			remove_alias_line(cor->alias, param[i]);
	}
	return (0);
}
