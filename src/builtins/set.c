/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

void	display_local_var_sub(alias_t *tmp)
{
	if (tmp->alias) {
		my_printf("%s\t", tmp->alias);
		if (tmp->cmd)
			my_printf("%s\n", tmp->cmd);
		else
			my_printf("\n");
	}
}

void	display_local_var(core_t *cor)
{
	alias_t *tmp = cor->local;

	my_printf("_\t");
	if (cor->cmd.old_cmd)
		my_printf("%s\n", cor->cmd.old_cmd);
	my_printf("\n");
	tmp = tmp->next;
	while (tmp) {
		display_local_var_sub(tmp);
		tmp = tmp->next;
	}
}

void	recup_var_cmd(char **param, char **new_var, char **new_cmd, int *i)
{
	int e = 0;

	for (; param[*i][e]; e++) {
		if (param[*i][e] == '=') {
			e++;
			break;
		}
		*new_var = my_charcat(*new_var, param[*i][e]);
	}
	for (; param[*i][e]; e++)
		*new_cmd = my_charcat(*new_cmd, param[*i][e]);
	if (param[*i + 1] && strcmp(param[*i + 1], "=") == 0) {
		*i += 2;
		if (param[*i])
			*new_cmd = strdup(param[*i]);
	}
}

int	local_verif_name(char *str)
{
	if (str == NULL ||
	((str[0] < 'a' || str[0] > 'z') && (str[0] < 'A' || str[0] > 'Z'))) {
		my_fprintf("set: Variable name must begin with a letter.\n");
		return (1);
	}
	for (int i = 0; str[i]; i++) {
		if ((str[i] < '0' || str[i] > '9') &&
		(str[i] < 'a' || str[i] > 'z') &&
		(str[i] < 'A' || str[i] > 'Z')) {
			my_fprintf("set: Variable name must contain");
			my_fprintf(" alphanumeric characters.\n");
			return (1);
		}
	}
	return (0);
}

int	set_builtin(core_t *cor, char **param)
{
	char *new_var = NULL;
	char *new_cmd = NULL;

	if (my_tablen(param) == 1) {
		display_local_var(cor);
		return (0);
	}
	for (int i = 1; param[i]; i++) {
		recup_var_cmd(param, &new_var, &new_cmd, &i);
		if (local_verif_name(new_var) == 1)
			return (1);
		if (replace_alias(&cor->local, new_var, new_cmd) == 0)
			cor->local = add_alias(cor->local, new_var, new_cmd);
		cor->local = sort_alias(cor->local);
		new_var = NULL;
		new_cmd = NULL;
	}
	return (0);
}
