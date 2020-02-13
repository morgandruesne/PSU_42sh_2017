/*
** EPITECH PROJECT, 2018
** wildcard
** File description:
** my_42sh
*/

#include "input.h"

char	**recup_paths_wildcard(char *str)
{
	glob_t globbuf;
	
	glob(str, GLOB_ERR, NULL, &globbuf);
	return (globbuf.gl_pathv);
}

void	create_rep_globing(char **rep, char *str)
{
	if (*rep == NULL)
		*rep = strc(*rep, str, 1);
	else {
		*rep = strc(*rep, " ", 1);
		*rep = strc(*rep, str, 1);
	}
	free(str);
}

char	*globbing_wildcard(char *input)
{
	int pos = -1;
	char *pathern = NULL;
	char **pathern_paths = NULL;
	char *rep = NULL;

	while ((pos = presence_char(input, '*')) != -1) {
		pathern = recup_pathern_wildcard(input, &pos);
		pathern_paths  = recup_paths_wildcard(pathern);
		if (!pathern_paths)
			return (NULL);
		for (int i = 0; pathern_paths[i] != NULL; i++)
			create_rep_globing(&rep, pathern_paths[i]);
		input = replace_word(input, rep, pos, strlen(pathern));
		free(pathern);
		pathern  = NULL;
		free(rep);
		rep = NULL;
	}
	return (input);
}