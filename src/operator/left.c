/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

int	left_operator(core_t *cor)
{
	int is_valid = 0;
	int fd_file;
	tree_t *save = cor->tree;

	if (verif_file_name(cor->tree->right->node) == 1) {
		my_fprintf("Missing name for redirect.\n");
		return (1);
	} else if (verif_file_is_not_a_directory(cor->tree->right->node) == 1)
		return (1);
	if ((fd_file = open(cor->tree->right->node, O_RDWR)) == -1) {
		my_fprintf("%s: No such file or", cor->tree->right->node);
		my_fprintf(" directory.\n");
		return (1);
	}
	cor->fd.in = fd_file;
	cor->tree = cor->tree->left;
	is_valid = reader(cor);
	cor->tree = save;
	return (is_valid);
}
