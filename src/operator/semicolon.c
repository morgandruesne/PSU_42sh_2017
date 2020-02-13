/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

int	semicolon_operator(core_t *cor)
{
	int is_valid = 0;
	int tmp = 0;
	tree_t *save = cor->tree;

	cor->tree = save->left;
	is_valid = reader(cor);
	cor->tree = save->right;
	tmp = reader(cor);
	cor->tree = save;
	is_valid = (is_valid == 1) ? 1 : tmp;
	return (is_valid);
}
