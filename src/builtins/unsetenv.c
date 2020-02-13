/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

void	remove_first(list_t *head, list_t *n)
{
	if (head->next == NULL) {
		head->line = NULL;
		return;
	}
	head->line = head->next->line;
	n = head->next;
	head->next = head->next->next;
	free (n);
	return;
}

void	remove_line(list_t *list, char *cmp)
{
	while (list->next) {
		if (my_strncmp(list->next->line, cmp, my_strlen(cmp)) == 0) {
			list->next = list->next->next;
			return;
		}
		list = list->next;
	}
}

int	unsetenv_builtin(core_t *cor, char **param)
{
	list_t *head = cor->env;

	if (my_tablen(param) == 1) {
		my_fprintf("unsetenv: Too few arguments.\n");
		return (1);
	}
	for (int i = 1; param[i]; i++) {
		if (my_strncmp(cor->env->line, param[i],
		my_strlen(param[i])) == 0) {
			remove_first(head, cor->env);
		} else
			remove_line(cor->env, param[i]);
	}
	return (0);
}
