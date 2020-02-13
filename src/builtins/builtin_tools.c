/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

alias_t	*add_alias(alias_t *list, char *alias, char *cmd)
{
	alias_t *new_node = malloc(sizeof(alias_t));
	alias_t *tmp = list;

	new_node->alias = my_strdup(alias);
	new_node->cmd = my_strdup(cmd);
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

char	*get_new_cmd(char **param)
{
	char *new_cmd = NULL;

	new_cmd = my_strcat(new_cmd, param[2]);
	for (int i = 3; param[i]; i++)
		new_cmd = my_strcat(new_cmd, my_strcat(" ", param[i]));
	return (new_cmd);
}

int	replace_alias(alias_t **alias, char *new_alias, char *new_cmd)
{
	alias_t *save = *alias;

	*alias = (*alias)->next;
	while (*alias && (*alias)->alias) {
		if (my_strcmp((*alias)->alias, new_alias) == 0) {
			(*alias)->alias = new_alias;
			(*alias)->cmd = new_cmd;
			*alias = save;
			return (1);
		}
		*alias = (*alias)->next;
	}
	*alias = save;
	return (0);
}
