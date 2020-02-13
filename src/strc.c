/*
** EPITECH PROJECT, 2018
** strc
** File description:
** my-42sh
*/

#include "input.h"

int	strlencat(char *str)
{
	int i = -1;

	if (!str)
		return (0);
	while (str[++i] != '\0');
	return (i);
}

char	*strc(char *str, char *add, int opt)
{
	int len_str = strlencat(str);
	int len_add = strlencat(add);
	int e = 0;
	char *new;

	new = malloc(sizeof(char) * (len_str + len_add + 1));
	new[len_str + len_add] = '\0';
	for (int i = 0; i < len_str; i++, e++)
		new[e] = str[i];
	for (int i = 0; i < len_add; i++, e++)
		new[e] = add[i];
	if (opt == 1)
		free(str);
	if (opt == 2) {
		free(str);
		free(add);
	}
	return (new);
}