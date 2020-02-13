/*
** EPITECH PROJECT, 2018
** which
** File description:
** my_42sh
*/

#include "input.h"
#include "function_pointer.h"

int	which_browse_builtin(char *param, int *is_valid)
{
	for (int i = 0; i < NB_BUILTIN; i++) {
		if (strcmp(param, blt_list[i].bls) == 0) {
			my_printf("%s: shell built-in ", blt_list[i].bls);
			my_printf("command.\n");
			*is_valid = 0;
			return (0);
		}
	}
	return (1);
}

int	which_browse_path(char **path_list, char *param, int *is_valid)
{
	char *tmp = NULL;

	for (int i = 0; path_list[i]; i++) {
		tmp = my_strcat(path_list[i], my_strcat("/", param));
		if (access(tmp, F_OK) == 0) {
			my_printf("%s\n", tmp);
			*is_valid = 0;
			return (0);
		} else
			tmp = NULL;
	}
	return (1);
}

int	which_browse_alias(alias_t *alias, char *param, int *is_valid)
{
	alias_t *tmp = alias;

	tmp = tmp->next;
	while (tmp) {
		if (strcmp(tmp->alias, param) == 0) {
			my_printf("%s: \t aliased to %s\n", param, tmp->cmd);
			*is_valid = 0;
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

void	which_error(char *str, int n)
{
	if (n == 1)
		my_printf("%s: Command not found.\n", str);
}

int	which_builtin(core_t *cor, char **p)
{
	int is_v = 1;
	int n = 0;

	if (my_tablen(p) == 1) {
		my_printf("which: Too few arguments.\n");
		return (1);
	}
	for (int i = 1; p[i]; i++) {
		n = which_browse_alias(cor->alias, p[i], &is_v);
		if (n != 0)
			n = which_browse_builtin(p[i], &is_v);
		if (n != 0)
			n = which_browse_path(cor->cmd.path_list, p[i], &is_v);
		if (n == 1)
			which_error(p[i], n);
	}
	return (is_v);
}