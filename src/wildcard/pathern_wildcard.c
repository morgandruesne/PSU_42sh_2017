/*
** EPITECH PROJECT, 2018
** pathern wilcard
** File description:
** my_42sh
*/

#include "input.h"

void	create_pathern_wildcard_r(char **ret, char *str, int i, int pc)
{
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '['  
	&& str[i] != ']' && str[i] != '"' && str[i] != '\\' && 
	str[i] != '*' && str[i] != '`') {
		*ret = add_letter(*ret, str[i], pc);
		pc++;
		i++;
	}
}

void	create_pathern_wildcard_l(char **ret, char *str, int i, int *pos)
{
	while (i >= 0 && str[i] != ' ' && str[i] != '['  
	&& str[i] != ']' && str[i] != '"' && str[i] != '\\' && 
	str[i] != '*' && str[i] != '`') {
		*ret = add_letter(*ret, str[i], 0);
		i--;
	}
	(*pos) = i +1;
}

char	*recup_pathern_wildcard(char *str, int *pos)
{
	char *ret = NULL;
	int pc = 1;
	int i = (*pos) +1;

	if (!str || *pos == -1)
		return (NULL);
	ret = malloc(sizeof(char) * 2);
	if (!ret)
		return (NULL);
	ret[0] = '*';
	ret[1] = '\0';
	create_pathern_wildcard_r(&ret, str, i, pc);
	i = (*pos) -1;
	create_pathern_wildcard_l(&ret, str, i, pos);
	return (ret);
}