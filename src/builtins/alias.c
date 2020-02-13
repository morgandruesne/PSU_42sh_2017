/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

void	display_alias(alias_t *alias)
{
	alias_t *tmp = alias;

	tmp = tmp->next;
	while (tmp && tmp->alias && tmp->cmd) {
		if (my_tablen(my_str_to_word_array(tmp->cmd, ' ')) > 1)
			my_printf("%s\t(%s)\n", tmp->alias, tmp->cmd);
		else
			my_printf("%s\t%s\n", tmp->alias, tmp->cmd);
		tmp = tmp->next;
	}
}

void	browse_list(alias_t *alias, char *alias_to_compare)
{
	alias_t *tmp = alias;

	tmp = tmp->next;
	while (tmp && tmp->alias && tmp->cmd) {
		if (my_strcmp(tmp->alias, alias_to_compare) == 0)
			my_printf("%s\n", tmp->cmd);
		tmp = tmp->next;
	}
}

int	verif_dangerous_alias(char *new_alias)
{
	if (strcmp(new_alias, "alias") == 0) {
		my_printf("alias: Too dangerous to alias that.\n");
		return (1);
	}
	return (0);
}

int	alias_builtin(core_t *cor, char **param)
{
	char *new_alias = NULL;
	char *new_cmd = NULL;

	if (my_tablen(param) == 1) {
		display_alias(cor->alias);
		return (0);
	} else if (my_tablen(param) == 2) {
		browse_list(cor->alias, param[1]);
		return (0);
	}
	new_alias = my_strdup(param[1]);
	if (verif_dangerous_alias(new_alias) == 1)
		return (1);
	new_cmd = get_new_cmd(param);
	if (replace_alias(&cor->alias, new_alias, new_cmd) == 0)
		cor->alias = add_alias(cor->alias, new_alias, new_cmd);
	cor->alias = sort_alias(cor->alias);
	return (0);
}
