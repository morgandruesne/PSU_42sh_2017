/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** put a src string after a dest string.
*/

#include "../../include/my.h"

char	*my_strcat(char *dest, char *src)
{
	int len = my_strlen(dest);
	int slen = my_strlen(src);
	char *res = malloc(sizeof(char) * (len + slen + 1));
	int i = 0;

	while (i < len) {
		res[i] = dest[i];
		i++;
	}
	i = 0;
	while (i < slen) {
		res[len + i] = src[i];
		i++;
	}
	res[len + i] = '\0';
	return (res);
}
