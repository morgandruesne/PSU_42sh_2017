/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "input.h"

int	quote_handling(core_t *cor, int *i, char *str)
{
	if (str[*i] == '`')
		if (backstick(cor, str, i) == 84)
			return (84);
	return (0);
}

int	browse_command(core_t *cor, char *str)
{
	for (int i = 0; str[i]; i++)
		if (quote_handling(cor, &i, str) == 84)
			return (84);
	return (0);
}

int	browse_parsing(core_t *cor, char **pars)
{
	for (int i = 0; pars[i]; i++) {
		if ((pars[i] = browse_alias(cor->alias, pars[i])) == NULL)
			return (1);
		if ((pars[i] = browse_local_var(cor->local, pars[i])) == NULL)
			return (1);
	}
	return (0);
}
