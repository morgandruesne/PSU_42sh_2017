/*
** EPITECH PROJECT, 2018
** letter str
** File description:
** my_42sh
*/

#include "input.h"

char	*add_letter(char *s, char c, int pos)
{
	char *save = strdup(s);
	int i = pos;
	int j = pos;

	if (pos < 0 || (unsigned)pos > strlen(s))
		return (s);
	s = realloc(s, sizeof(char) * (strlen(s) + 2));
	s[i] = c;
	i++;
	while (save[j] != '\0') {
		s[i] = save[j];
		i++;
		j++;
	}
	s[i] = '\0';
	free(save);
	return (s);
}

char	*supr_letter(char *s, int pos)
{
	int i = pos;
	int len = strlen(s);

	if (pos < 0 || (unsigned)pos >= strlen(s))
		return (s);
	s = realloc(s, sizeof(char) * (strlen(s)));
	while (i + 1 < len) {
		s[i] = s[i + 1];
		i++;
	}
	s[i] = '\0';
	return (s);
}