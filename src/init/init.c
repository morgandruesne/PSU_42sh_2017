/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

int	browse_env_oldpwd(list_t *list)
{
	while (list) {
		if (my_strncmp(list->line, "OLDPWD", 6) == 0)
			return (0);
		list = list->next;
	}
	return (1);
}

list_t	*init_env(list_t *list)
{
	if (browse_env_oldpwd(list) == 1)
		list = add_node(list, "OLDPWD=");
	return (list);
}

fd_t	init_file_descriptor(void)
{
	fd_t fd;

	fd.in = 0;
	fd.out = 1;
	return (fd);
}

char	**recup_path_list(list_t *list)
{
	char *path_line = NULL;
	char **path_list = NULL;
	int i = 0;

	while (list) {
		if (my_strncmp(list->line, "PATH", 4) == 0)
			break;
		list = list->next;
	}
	path_line = malloc(sizeof(char) * (my_strlen(list->line) - 4));
	for (; list->line[i] != '='; i++);
	i++;
	for (int e = 0; list->line[i]; i++, e++)
		path_line[e] = list->line[i];
	path_line[my_strlen(list->line) - 5] = '\0';
	path_list = my_str_to_word_array(path_line, ':');
	return (path_list);
}
