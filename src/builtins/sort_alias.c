/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

int	verif_sorted(alias_t *alias)
{
	alias_t *tmp = alias;

	tmp = tmp->next;
	while (tmp->next && tmp->next->alias) {
		if (my_strcmp(tmp->alias, tmp->next->alias) > 0) {
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	switch_alias(alias_t *alias)
{
	char *save_alias = NULL;
	char *save_cmd = NULL;

	if (my_strcmp(alias->alias, alias->next->alias) > 0) {
		save_alias = my_strdup(alias->alias);
		save_cmd = my_strdup(alias->cmd);
		alias->alias = alias->next->alias;
		alias->cmd = alias->next->cmd;
		alias->next->alias = save_alias;
		alias->next->cmd = save_cmd;
	}
}

alias_t	*sort_alias(alias_t *alias)
{
	alias_t *tmp = alias;

	while (verif_sorted(alias) == 1) {
		alias = alias->next;
		while (alias->next && alias->next->alias) {
			switch_alias(alias);
			alias = alias->next;
		}
		alias = tmp;
	}
	return (alias);
}
