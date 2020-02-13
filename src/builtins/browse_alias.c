/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

int	alias_len(alias_t *alias)
{
	alias_t *tmp = alias;
	int count = 0;

	tmp = tmp->next;
	while (tmp && tmp->alias && tmp->cmd) {
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	verif_alias_loop_sub(alias_t *alias, alias_t *tmp, int *check, int i)
{
	if (my_strcmp(tmp->alias, tmp->cmd) == 0)
		return (0);
	if (check[i] == 0) {
		check[i] = 1;
		return (verif_alias_loop(alias, tmp->cmd, check));
	}
	my_printf("Alias loop.\n");
	return (1);
}

int	verif_alias_loop(alias_t *alias, char *str, int *check)
{
	alias_t *tmp = alias;
	int i = 0;

	tmp = tmp->next;
	while (tmp && tmp->alias && tmp->cmd) {
		if (my_strcmp(tmp->alias, str) == 0)
			return (verif_alias_loop_sub(alias, tmp, check, i));
		tmp = tmp->next;
		i++;
	}
	return (0);
}

char	*browse_alias(alias_t *alias, char *str)
{
	alias_t *tmp = alias;
	int *check = malloc(sizeof(int) * alias_len(alias));

	for (int i = 0; i < alias_len(alias); i++)
		check[i] = 0;
	if (verif_alias_loop(alias, str, check) == 1)
		return (NULL);
	tmp = tmp->next;
	while (tmp && tmp->alias && tmp->cmd) {
		if (my_strcmp(tmp->alias, str) == 0 &&
		my_strcmp(tmp->alias, tmp->cmd) == 0) {
			return (tmp->cmd);
		} else if (my_strcmp(tmp->alias, str) == 0) {
			return (browse_alias(alias, tmp->cmd));
		}
		tmp = tmp->next;
	}
	return (str);
}
