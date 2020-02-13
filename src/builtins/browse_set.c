/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

char	*browse_local_var_sub_2(char *param)
{
	char *cmd = NULL;

	if (param[0] != '$')
		return (NULL);
	for (int i = 1, e = 0; param[i]; i++, e++)
		cmd = my_charcat(cmd, param[i]);
	return (cmd);
}

char	*browse_local_var_sub(char *str)
{
	char **param = my_str_to_word_array(str, ' ');
	char *cmd = NULL;

	for (int i = 0; param[i]; i++) {
		if ((cmd = browse_local_var_sub_2(param[i])) != NULL)
			return (cmd);
	}
	return (NULL);
}

char	*browse_local_var(alias_t *local, char *str)
{
	alias_t *tmp = local;
	char *cmd = NULL;

	if ((cmd = browse_local_var_sub(str)) == NULL)
		return (str);
	tmp = tmp->next;
	while (tmp && tmp->alias && tmp->cmd) {
		if (my_strcmp(tmp->alias, cmd) == 0)
			return (tmp->cmd);
		tmp = tmp->next;
	}
	my_printf("%s: Undefined variable.\n", cmd);
	return (NULL);
}
