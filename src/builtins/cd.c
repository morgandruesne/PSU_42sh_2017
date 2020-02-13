/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

int	cd_home(list_t *list)
{
	while (list) {
		if (my_strncmp(list->line, "HOME", 4) == 0) {
			actualise_old_pwd(list);
			chdir(recup_env_argument(list->line));
			actualise_actual_pwd(list);
			return (0);
		}
		list = list->next;
	}
	my_fprintf("cd: No home directory.\n");
	return (1);
}

int	cd_back(list_t *list)
{
	while (list) {
		if (my_strncmp(list->line, "OLDPWD", 6) == 0)
			return (cd_back_verif(list));
		list = list->next;
	}
	return (0);
}

int	cd_normal(list_t *list, char *param)
{
	int is_valid = 0;
	char *tmp = NULL;

	if (access(param, F_OK) == 0) {
		actualise_old_pwd(list);
		if (param[0] == '/') {
			is_valid = verif_chdir(param, param);
		} else {
			tmp = my_strcat(getcwd(NULL, 0), my_strcat("/", param));
			is_valid = verif_chdir(tmp, param);
		}
		actualise_actual_pwd(list);
	} else {
		my_fprintf("%s: No such file or directory.\n", param);
		return (1);
	}
	return (is_valid);
}

int	cd_builtin(core_t *cor, char **param)
{
	if (my_tablen(param) > 2) {
		my_fprintf("cd: Too many arguments.\n");
		return (1);
	} else if (param[1] == NULL || param[1][0] == '~' ||
	my_strcmp(param[1], "--") == 0) {
		return(cd_home(cor->env));
	} else if (param[1][0] == '-') {
		return(cd_back(cor->env));
	} else
		return(cd_normal(cor->env, param[1]));
}
