/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

void	remove_alias_first(alias_t *head, alias_t *n)
{
	if (head->next == NULL) {
		head->alias = NULL;
		return;
	}
	head->alias = head->next->alias;
	n = head->next;
	head->next = head->next->next;
	free (n);
	return;
}

void	remove_alias_line(alias_t *local, char *cmp)
{
	while (local->next) {
		if (my_strcmp(local->next->alias, cmp) == 0) {
			local->next = local->next->next;
			return;
		}
		local = local->next;
	}
}

int	unset_builtin(core_t *cor, char **param)
{
	alias_t *head = cor->local;

	if (my_tablen(param) == 1) {
		my_printf("unset: Too few arguments.\n");
		return (1);
	}
	for (int i = 1; param[i]; i++) {
		if (my_strcmp(cor->local->alias, param[i]) == 0) {
			remove_alias_first(head, cor->local);
		} else
			remove_alias_line(cor->local, param[i]);
	}
	return (0);
}
