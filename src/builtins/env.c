/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

list_t	*add_node(list_t *list, char *line)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *tmp = list;

	new_node->line = my_strdup(line);
	new_node->next = NULL;
	if (list == NULL)
		return (new_node);
	else {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	return (list);
}

list_t	*copy_env(char **env)
{
	list_t *list = NULL;

	for (int i = 0; env[i]; i++)
		list = add_node(list, env[i]);
	return (list);
}

void	ctrl_d(int val)
{
	if (isatty(0) == 1)
		my_printf("exit\n");
	exit (val);
}

int	display_env(core_t *cor, char **param)
{
	list_t *save = cor->env;

	if (my_tablen(param) != 1) {
		my_fprintf("env: Too many arguments.\n");
		return (1);
	}
	while (save && save->line) {
		if (my_strncmp(save->line, "OLDPWD", 6) != 0)
			my_printf("%s\n", save->line);
		save = save->next;
	}
	return (0);
}
