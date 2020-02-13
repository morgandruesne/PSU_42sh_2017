/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

int	echo_builtin(core_t *cor, char **param)
{
	(void)cor;
	for (int i = 1; param[i]; i++) {
		my_printf("%s", param[i]);
		if (param[i + 1])
			my_printf(" ");
	}
	my_printf("\n");
	return (0);
}
