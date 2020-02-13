/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** return the lenght of a string.
*/

#include "../../include/my.h"

int	my_strlen(char const *str)
{
	int i = 0;

	while (str && str[i])
		i++;
	return (i);
}
