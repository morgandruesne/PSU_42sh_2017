/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

int	double_right_operator(core_t *cor)
{
	int is_valid = 0;
	int fd_file;
	core_t save = *cor;

	if (verif_file_name(save.tree->right->node) == 1) {
		my_fprintf("Missing name for redirect.\n");
		return (1);
	} else if (verif_file_is_not_a_directory(save.tree->right->node) == 1)
		return (1);
	fd_file = open(save.tree->right->node, O_RDWR | O_CREAT | O_APPEND);
	save.fd.out = fd_file;
	save.tree = save.tree->left;
	is_valid = reader(&save);
	return (is_valid);
}
