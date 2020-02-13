/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** return the first number of a string.
*/

#include "../../include/my.h"

int	my_getnbr(char const *str)
{
	long num = 0;
	int sign = 1;

	while (*str != '\0') {
		if (*str != '+' && *str != '-' && (*str < '0' || *str > '9'))
			break;
		else if (*str >= '0' && *str <= '9')
			num = num * 10 + (*str - '0');
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		sign = (*str == '-') ? sign * -1 : sign;
		str++;
	}
	return (num * sign);
}
