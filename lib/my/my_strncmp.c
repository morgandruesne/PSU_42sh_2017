/*
** EPITECH PROJECT, 2017
** my_strncmp
** File description:
** compare two strings only for n characters.
*/

#include "../../include/my.h"

int	my_strncmp(char const *s1, char const *s2, int n)
{
	while (n > 0) {
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
