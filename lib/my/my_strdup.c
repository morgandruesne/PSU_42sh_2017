/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** task01
*/

#include "../../include/my.h"

char	*my_strdup(char const *str)
{
	char *mal = NULL;
	int i = 0;
	int size = 0;

	if (str == NULL)
		return (NULL);
	size = my_strlen(str);
	mal = malloc(sizeof(char) * (size + 1));
	if (mal == NULL)
		return (NULL);
	while (str[i] != '\0') {
		mal[i] = str[i];
		i++;
	}
	mal[i] = '\0';
	return (mal);
}
