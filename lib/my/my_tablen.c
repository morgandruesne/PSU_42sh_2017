/*
** EPITECH PROJECT, 2017
** my_tablen
** File description:
** return the lenght of a tab.
*/

#include "../../include/my.h"

int	my_tablen(char **tab)
{
	int len = 0;

	while (tab && tab[len])
		len++;
	return (len);
}
