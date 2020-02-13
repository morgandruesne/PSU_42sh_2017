/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** reverse the characters of a string.
*/

#include "../../include/my.h"

char	*my_revstr (char *str)
{
	int i = 0;
	int len = my_strlen(str);
	int mid = len / 2;
	char x;

	while (i < mid) {
		x = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = x;
		i++;
	}
	return (str);
}
