/*
** EPITECH PROJECT, 2017
** my_str_cleaner.c
** File description:
** Clean useless space or tab of a string.
*/

#include "../../include/my.h"

char	*verif_quote(char *dest, char *str, int *i, int *e)
{
	// my_printf("I: %d\n", *i);
	*i += 1;
	// my_printf("%s\n", str);
	for (; str[*i] != '\'' && str[*i]; *i += 1, *e += 1) {
		dest[*e] = str[*i];
		// my_printf("%c", dest[*e]);
	}
	// *i += 1;
	// my_printf("%d\n", str[*i]);
	// my_printf("I: %d\n", *i);
	return (dest);
}

char	*my_str_cleaner_sub(char *dest, int *e, char *str)
{
	for (int i = 1; str[i] != '\0'; i++) {
		if (str[i] == '\'') {
			// my_printf("QUOTE: %d\n", i);
			dest = verif_quote(dest, str, &i, e);
			// my_printf("END QUOTE: %d\n", i);
		} else if ((str[i] == ' ' || str[i] == '\t') &&
		(str[i - 1] != ' ' && str[i - 1] != '\t')) {
			dest[*e] = ' ';
			(*e)++;
		} else if (str[i] != ' ' && str[i] != '\t') {
			dest[*e] = str[i];
			(*e)++;
		}
	}
	if (dest[*e - 1] == ' ' || dest[*e - 1] == '\t')
		dest[*e - 1] = '\0';
	else
		dest[*e] = '\0';
	return (dest);
}

char	*my_str_cleaner(char *str)
{
	int e = 0;
	char *dest = malloc(sizeof(char) * (my_strlen(str) + 1));

	if (str[0] == 0) {
		dest[e] = '\0';
		return (dest);
	}
	if (str[0] != ' ' && str[0] != '\t') {
		dest[e] = str[0];
		e++;
	}
	dest = my_str_cleaner_sub(dest, &e, str);
	free (str);
	return (dest);
}
