/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** print a string of characters.
*/

#include "../../include/my.h"

int	my_putstr(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i += 1;
	}
	return (0);
}

int	my_fputstr(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_fputchar(str[i]);
		i += 1;
	}
	return (0);
}
