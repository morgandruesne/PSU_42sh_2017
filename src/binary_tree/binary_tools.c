/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

char	**realoc_tab(char **arr)
{
	char **new = malloc(sizeof(char *) * (my_tablen(arr) + 2));

	new[my_tablen(arr)] = NULL;
	for (int i = 0; arr && arr[i]; i++)
		new[i] = my_strdup(arr[i]);
	new[my_tablen(arr) + 1] = NULL;
	return (new);
}

char	*realoc_string(char *str, char c)
{
	char *new = malloc(sizeof(char) * (my_strlen(str) + 2));
	int i = 0;

	for (;str && str[i]; i++)
		new[i] = str[i];
	new[i] = c;
	new[i + 1] = '\0';
	return (new);
}

int	is_ope(char *str, int start)
{
	char *ope[8] = {">", ">>", "<", "<<", ";", "&&", "|", "||"};

	for (int i = start; i < 8; i++)
		if (my_strcmp(str, ope[i]) == 0)
			return (1);
	return (0);
}

int	is_simple_ope(char c)
{
	char ope[6] = {';', '|', '>', '<', '&'};

	for (int i = 0; i < 6; i++)
		if (c == ope[i])
			return (1);
	return (0);
}

int	verif_pars(char **pars)
{
	int i = 1;

	if (pars == NULL || pars[0] == NULL)
		return (0);
	if (is_ope(pars[0], 6) == 1) {
		my_printf("Invalid null command.\n");
		return (1);
	}
	for (;pars[i] && pars[i + 1]; i++) {
		if (is_ope(pars[i], 5) == 1 &&
		(is_ope(pars[i - 1], 4) == 1 || is_ope(pars[i + 1], 4) == 1)) {
			my_printf("Invalid null command.\n");
			return (1);
		}
	}
	if (pars[i] && is_ope(pars[i], 5) == 1) {
		my_printf("Invalid null command.\n");
		return (1);
	}
	return (0);
}
