/*
** EPITECH PROJECT, 2017
** my_square_root
** File description:
** return the square root of a number.
*/

#include "../../include/my.h"

int	my_sqrt(int nb)
{
	int i = 0;

	if (nb < 0)
		return (0);
	while ((i*i) != nb)
		i++;
	return (i);
}
