/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

tree_t	*create_node(char **pars, int len, int to_add)
{
	tree_t *new_node = malloc(sizeof(tree_t));

	new_node->left = NULL;
	new_node->right = NULL;
	new_node->node = NULL;
	new_node->pars = malloc(sizeof(char*) * (len + 1));
	for (int e = 0; e < len; e++)
		new_node->pars[e] = my_strdup(pars[e + to_add]);
	new_node->pars[len] = NULL;
	return (new_node);
}

void	sort_operator(tree_t *tree, char *operator)
{
	int tab_len = my_tablen(tree->pars);

	if (tree->node != NULL) {
		if (tree->left && tree->right) {
			sort_operator(tree->left, operator);
			sort_operator(tree->right, operator);
		}
		return;
	}
	for (int i = 0; tree->pars[i]; i++) {
		if (my_strcmp(tree->pars[i], operator) == 0) {
			tree->node = my_strdup(tree->pars[i]);
			tree->left = create_node(tree->pars, i, 0);
			tree->right = create_node(tree->pars, tab_len-i-1, i+1);
			sort_operator(tree->left, operator);
			sort_operator(tree->right, operator);
		}
	}
	tree->node = (tab_len == 1 && is_ope(tree->pars[0], 0) == 0) ?
	my_strdup(tree->pars[0]) : tree->node;
}

tree_t	*lexer(char **pars)
{
	tree_t *tree = create_node(pars, my_tablen(pars), 0);

	sort_operator(tree, ";");
	sort_operator(tree, "||");
	sort_operator(tree, "&&");
	sort_operator(tree, "|");
	sort_operator(tree, ">");
	sort_operator(tree, ">>");
	sort_operator(tree, "<");
	sort_operator(tree, "<<");
	return (tree);
}
