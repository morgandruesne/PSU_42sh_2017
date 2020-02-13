/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

int	verif_file_name(char *name)
{
	char *ope[6] = {";", "|", ">", ">>", "<", "<<"};

	if (name == NULL || name[0] == '\0')
	 	return (1);
	for (int i = 0; i < 6; i++)
		if (my_strcmp(name, ope[i]) == 0)
			return (1);
	return (0);
}

int	verif_file_is_not_a_directory(char *name)
{
	char *save_pwd = getcwd(NULL, 0);

	if (my_strcmp(name, "~") == 0) {
		my_fprintf("/root: Is a directory.\n");
		return (1);
	}
	if (chdir(name) == 0) {
		chdir(save_pwd);
		my_fprintf("%s: Is a directory.\n", name);
		return (1);
	}
	return (0);
}

int	right_operator(core_t *cor)
{
	int is_valid = 0;
	int fd_file;
	core_t save = *cor;

	if (verif_file_name(save.tree->right->node) == 1) {
		my_fprintf("Missing name for redirect.\n");
		return (1);
	} else if (verif_file_is_not_a_directory(save.tree->right->node) == 1)
		return (1);
	fd_file = open(save.tree->right->node, O_RDWR | O_CREAT | O_TRUNC);
	save.fd.out = fd_file;
	save.tree = save.tree->left;
	is_valid = reader(&save);
	return (is_valid);
}
