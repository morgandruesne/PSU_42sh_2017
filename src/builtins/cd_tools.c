/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

char	*recup_env_argument(char *str)
{
	char *arg = malloc(sizeof(char) * (my_strlen(str) + 1));
	int i = 1;
	int e = 0;

	for (;str[i - 1] != '='; i++);
	if (str[i] == '\0')
		return (NULL);
	for (; str[i] != '\0'; i++, e++)
		arg[e] = str[i];
	arg[e] = '\0';
	return (arg);
}

void	actualise_actual_pwd(list_t *list)
{
	while (list) {
		if (my_strncmp(list->line, "PWD", 3) == 0) {
			list->line = my_strcat("PWD=", getcwd(NULL, 0));
			return;
		}
		list = list->next;
	}
}

void	actualise_old_pwd(list_t *list)
{
	while (list) {
		if (my_strncmp(list->line, "OLDPWD", 6) == 0) {
			list->line = my_strcat("OLDPWD=", getcwd(NULL, 0));
			return;
		}
		list = list->next;
	}
}

int	verif_chdir(char *pwd, char *param)
{
	if (chdir(pwd) == -1) {
		if (errno == 20) {
			my_fprintf("%s: Not a directory.\n", param);
			return (1);
		}
	}
	return (0);
}

int	cd_back_verif(list_t *list)
{
	char *old_pwd = recup_env_argument(list->line);

	if (old_pwd) {
		actualise_old_pwd(list);
		chdir(old_pwd);
		actualise_actual_pwd(list);
	} else {
		my_fprintf(": No such file or directory.\n");
		return (1);
	}
	return (0);
}
