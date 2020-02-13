/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** Description.
*/

#include "../../include/my.h"

int	count_word(char const *str, char separator)
{
	int nbr_word = 0;

	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == separator)
			nbr_word++;
	return (nbr_word + 1);
}

char	**my_str_to_word_array(char const *str, char separator)
{
	char **dest = NULL;
	int e = 0;
	int f = 0;

	dest = malloc(sizeof(char*) * (count_word(str, separator) + 1));
	dest[e] = malloc(sizeof(char) * (my_strlen(str) + 1));
	for (int i = 0; str[i] != '\0'; i++, f++) {
		if (str[i] == separator) {
			dest[e][f] = '\0';
			e++;
			f = -1;
			dest[e] = malloc(sizeof(char) * (my_strlen(str) + 1));
		} else
			dest[e][f] = str[i];
	}
	dest[e][f] = '\0';
	dest[e + 1] = NULL;
	return (dest);
}
