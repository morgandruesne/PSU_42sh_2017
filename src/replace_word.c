/*
** EPITECH PROJECT, 2018
** replace word
** File description:
** my_42sh
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*replace_word(char *ref, char *rep, int pos, int nb)
{
	char *ret = NULL;
	int i = 0;
	int e = 0;

	if (!ref || !rep || pos == -1 || nb <= 0)
		return (ref);
	ret = malloc(sizeof(char) * (strlen(ref) - nb + strlen(rep) +1));
	if (!ret)
		return (ref);
	for (; e != pos; e++, i++)
		ret[i] = ref[e];
	e = 0;
	for (; rep[e] != '\0'; e++, i++)
		ret[i] = rep[e];
	e = pos + nb;
	for (; ref[e] != '\0'; e++, i++)
		ret[i] = ref[e];
	ret[i] = '\0';
	free(ref);
	return (ret);
}