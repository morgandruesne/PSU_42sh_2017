/*
** EPITECH PROJECT, 2017
** my_compute_power_rec
** File description:
** return the value of a number put to the power.
*/

#include "../../include/my.h"

int	my_pow(int nb, int power)
{
	int res = nb;

	if (power > 0) {
		nb = res * my_pow(nb, power - 1);
		return (nb);
	}
	else if (power == 0)
		return (1);
	else
		return (0);
}
