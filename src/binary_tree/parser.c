/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

char	**increase_tab(char **pars, int *e)
{
	*e += 1;
	pars = realoc_tab(pars);
	return (pars);
}

char	**clean_pars_tab(char **pars)
{
	for (int i = 0; pars[i]; i++)
		pars[i] = my_str_cleaner(pars[i]);
	return (pars);
}

char	**verif_previous_is_cmd(char **pars, int *e, int is_cmd)
{
	if (is_cmd == 1)
		pars = increase_tab(pars, e);
	return (pars);
}

char	**pars_core(char **pars, char *str, int *i, int *e)
{
	pars[*e] = realoc_string(pars[*e], str[*i]);
	if ((str[*i] == '<' && str[*i + 1] == '<') ||
	(str[*i] == '>' && str[*i + 1] == '>') ||
	(str[*i] == '&' && str[*i + 1] == '&') ||
	(str[*i] == '|' && str[*i + 1] == '|')) {
		*i += 1;
		pars[*e] = realoc_string(pars[*e], str[*i]);
	}
	pars = increase_tab(pars, e);
	return (pars);
}

char	**parser(char *str)
{
	char **pars = NULL;
	int is_cmd = 0;
	int e = 0;

	pars = realoc_tab(pars);
	for (int i = 0; str[i]; i++) {
		if (str[i] == ' ' && is_cmd == 0)
			continue;
		else if (is_simple_ope(str[i]) == 1) {
			pars = verif_previous_is_cmd(pars, &e, is_cmd);
			pars = pars_core(pars, str, &i, &e);
			is_cmd = 0;
		} else if (str[i] == '\'' && quote(pars, str, &i, e) == 84) {
			return (NULL);
		} else {
			pars[e] = realoc_string(pars[e], str[i]);
			is_cmd = 1;
		}
	}
	return (clean_pars_tab(pars));
}
