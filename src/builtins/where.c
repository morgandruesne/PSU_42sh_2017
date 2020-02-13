/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"
#include "function_pointer.h"

void	where_browse_builtin(char *param, int *is_valid)
{
	for (int i = 0; i < NB_BUILTIN; i++) {
		if (strcmp(param, blt_list[i].bls) == 0) {
			my_printf("%s is a shell built-in\n", blt_list[i].bls);
			*is_valid = 0;
		}
	}
}

void	where_browse_path(char **path_list, char *param, int *is_valid)
{
	char *tmp = NULL;

	for (int i = 0; path_list[i]; i++) {
		tmp = my_strcat(path_list[i], my_strcat("/", param));
		if (access(tmp, F_OK) == 0) {
			my_printf("%s\n", tmp);
			*is_valid = 0;
		} else
			tmp = NULL;
	}
}

void	where_browse_alias(alias_t *alias, char *param, int *is_valid)
{
	alias_t *tmp = alias;

	tmp = tmp->next;
	while (tmp) {
		if (strcmp(tmp->alias, param) == 0) {
			my_printf("%s is aliased to %s\n", param, tmp->cmd);
			*is_valid = 0;
		}
		tmp = tmp->next;
	}
}

int	where_builtin(core_t *cor, char **param)
{
	int is_valid = 1;

	if (my_tablen(param) == 1) {
		my_printf("where: Too few arguments.\n");
		return (1);
	}
	for (int i = 1; param[i]; i++) {
		where_browse_alias(cor->alias, param[i], &is_valid);
		where_browse_builtin(param[i], &is_valid);
		where_browse_path(cor->cmd.path_list, param[i], &is_valid);
	}
	return (is_valid);
}
