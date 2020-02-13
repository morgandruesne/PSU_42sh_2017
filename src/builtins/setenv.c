/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

int	replace_line(list_t *env, char *cmp, char *str_to_replace)
{
	if (env == NULL)
		printf("NULL\n");
	if (env->line == NULL) {
		env->line = str_to_replace;
		return (0);
	}
	while (env) {
		if (my_strncmp(env->line, cmp, my_strlen(cmp)) == 0) {
			env->line = str_to_replace;
			return (0);
		}
		env = env->next;
	}
	return (1);
}

int	setenv_verif_name(char *str)
{
	if ((str[0] < 'a' || str[0] > 'z') && (str[0] < 'A' || str[0] > 'Z')) {
		my_fprintf("setenv: Variable name must begin with a letter.\n");
		return (1);
	}
	for (int i = 0; str[i]; i++) {
		if ((str[i] < '0' || str[i] > '9') &&
		(str[i] < 'a' || str[i] > 'z') &&
		(str[i] < 'A' || str[i] > 'Z')) {
			my_fprintf("setenv: Variable name must contain");
			my_fprintf(" alphanumeric characters.\n");
			return (1);
		}
	}
	return (0);
}

int	setenv_error(core_t *cor, char **param)
{
	if (my_tablen(param) > 3) {
		my_fprintf("setenv: Too many arguments.\n");
		return (84);
	} else if (my_tablen(param) == 1) {
		display_env(cor, param);
		return (1);
	}
	if (setenv_verif_name(param[1]) == 1)
		return (84);
	return (0);
}

int	setenv_builtin(core_t *cor, char **param)
{
	char *new_str = NULL;
	int tmp = setenv_error(cor, param);

	if (tmp == 84)
		return (1);
	if (tmp == 1) {
		return (0);
	} else if (my_tablen(param) == 2) {
		new_str = my_strcat(param[1], "=");
	} else
		new_str = my_strcat(param[1], my_strcat("=", param[2]));
	if (replace_line(cor->env, param[1], new_str) == 1)
		cor->env = add_node(cor->env, new_str);
	return (0);
}
