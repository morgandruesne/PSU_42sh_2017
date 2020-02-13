/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** built-in
*/

#include "minishell2.h"

int	exec_foreach(core_t *cor, list_t *list)
{
	char *input = NULL;

	while (list != NULL) {
		input = list->line;
		if (my_strcmp(input, "end") == 0)
			break;
		cor->cmd.input = input;
		executer(cor);
		list = list->next;
	}
	return (0);
}

int	is_good_foreach(char *str)
{
	if (!(str[0] >= 'a' && str[0] <= 'z')
	&& !(str[0] >= 'A' && str[0] <= 'Z')) {
		my_printf("foreach: Variable name");
		my_printf(" must begin with a letter.\n");
		return (1);
	}
	return (0);
}

int	is_good_nb_arg(char **param)
{
	int i = 0;

	for (; param[i] != NULL; i++);
	if (i < 2) {
		my_printf("foreach: Too few arguments.\n");
		return (1);
	}
	return (0);
}

int	get_nb_rol(char **param)
{
	int i = 2;

	if (is_good_nb_arg(param))
		return (-1);
	if (check_param_enter(param))
		return (-1);
	if (is_good_foreach(param[1]))
		return (-1);
	return (i);
}

char	*get_name_var(char *str)
{
	char *final = my_strdup(str);

	for (int i = 0; final[i] != '\0'; i++)
	if (!(final[i] >= 'a' && final[i] <= 'z')
	&& !(final[i] >= 'A' && final[i] <= 'Z')) {
		final[i] = '\0';
		return (final);
	}
	return (final);
}
