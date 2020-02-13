/*
** EPITECH PROJECT, 2017
** my_putchar
** File description:
** print a character.
*/

#include "../../include/my.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_fputchar(char c)
{
	write(2, &c, 1);
}
