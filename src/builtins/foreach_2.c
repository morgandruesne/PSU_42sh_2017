/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** built-in
*/

#include "minishell2.h"

char	*check_valid_param(char *param)
{
	if (param[0] == ')' && param[1] == '\0')
		return (NULL);
	for (int nb = 0; param[nb] != '\0'; nb += 1) {
		if (param[nb] == ')') {
			param[nb] = '\0';
			return (param);
		}
	}
	return (param);
}

int	first_param(char *param)
{
	for (int nb = 0; param[nb] != '\0'; nb += 1) {
		if (param[nb] == '(' && param[nb + 1] == '\0')
			return (1);
		if (param[nb] == '(' && param[nb + 1] != '\0')
			return (2);
	}
	return (0);
}

int	get_param_2(int *nb, char **param)
{
	int i = 0;

	for (; param[i] != NULL; i++) {
		*nb = first_param(param[i]);
		if (*nb == 1) {
			i += 1;
			break;
		}
		if (*nb == 2)
			break;
	}
	return (i);
}

list_t	*get_param(char **param)
{
	int i = 0;
	int nb = 0;
	int nb1 = 0;
	list_t	*list = NULL;

	i = get_param_2(&nb, param);
	if (nb == 2) {
		for (; param[i][nb1] != '('; nb1 += 1);
		param[i] = check_valid_param(param[i]);
		if (param[i] != NULL && param[i][nb1 + 1] != ')')
			list = add_node(list, param[i] + nb1 + 1);
		i += 1;
	}
	for (; param[i] != NULL; i++) {
		param[i] = check_valid_param(param[i]);
		if (param[i] != NULL)
			list = add_node(list, param[i]);
	}
	return (list);
}