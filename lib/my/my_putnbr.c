/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** print a number.
*/

#include "../../include/my.h"

int	my_putnbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
		my_putnbr(nb / 10);
	my_putchar(nb % 10 + '0');
	return (0);
}

int	my_fputnbr(int nb)
{
	if (nb < 0) {
		my_fputchar('-');
		nb *= -1;
	}
	if (nb > 9)
		my_putnbr(nb / 10);
	my_fputchar(nb % 10 + '0');
	return (0);
}
