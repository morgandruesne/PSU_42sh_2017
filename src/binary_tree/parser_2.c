/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

int	verif_second_quote_exist(char *str, int i, char quote)
{
	for (; str[i]; i++)
		if (str[i] == quote)
			return (1);
	return (0);
}

int	quote(char **pars, char *str, int *i, int e)
{
	if (verif_second_quote_exist(str, *i + 1, '\'') == 0) {
		my_printf("Unmatched '''.\n");
		return (84);
	}
	*i += 1;
	for (; str[*i] != '\'' && str[*i]; *i += 1)
		pars[e] = realoc_string(pars[e], str[*i]);
	*i += 1;
	if (pars[e] == NULL)
		pars[e] = strdup("\0");
	return (0);
}
