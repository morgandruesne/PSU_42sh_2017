/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** built-in
*/

#include "minishell2.h"

int	get_nb_paren_open(char c)
{
	if (c == '(')
		return (1);
	return (0);
}

int	get_nb_paren_close(char c)
{
	if (c == ')')
		return (1);
	return (0);
}

int	check_param_enter(char **param)
{
	int	paren_open = 0;
	int	paren_close = 0;

	for (int i = 0; param[i] != NULL; i++) {
		for (int nb = 0; param[i][nb] != '\0'; nb += 1) {
			paren_open += get_nb_paren_open(param[i][nb]);
			paren_close += get_nb_paren_close(param[i][nb]);
		}
	}
	if (paren_open < paren_close) {
		my_printf("Too many )'s.\n");
		return (1);
	}
	if (paren_close < paren_open) {
		my_printf("Too many ('s.\n");
		return (1);
	}
	return (0);
}

int	is_param(char *str)
{
	for (int para = 0; str[para] != '\0'; para++) {
		if (str[para] != '(' && str[para] != ')')
			return (1);
	}
	return (0);
}

int	get_nb_param(char **param)
{
	int i = 0;
	int nb = 0;

	for (; param[i] != NULL; i++)
		nb += is_param(param[i]);
	return (nb);
}