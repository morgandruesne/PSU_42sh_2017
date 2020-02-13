/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"
#include "function_pointer.h"

int	browse_operator(core_t *cor)
{
	int is_valid = 0;

	for (int i = 0; i < NB_OPERATOR; i++) {
		if (my_strcmp(cor->cmd.param[0], ope_list[i].bls) == 0) {
			is_valid = ope_list[i].func(cor);
			return (-(is_valid + 1));
		}
	}
	return (is_valid);
}

int	browse_builtin(core_t *cor, int *is_a_builtin)
{
	int is_vld = 0;
	int fd_save = dup(1);

	for (int i = 0; i < NB_BUILTIN; i++) {
		if (my_strcmp(cor->cmd.param[0], blt_list[i].bls) == 0) {
			*is_a_builtin = 1;
			dup2(cor->fd.out, 1);
			is_vld = blt_list[i].func(cor, cor->cmd.param);
			dup2(fd_save, 1);
		}
	}
	return (is_vld);
}

void	free_tab(char **arr)
{
	for (int i = 0; arr[i] != NULL; i++)
		free(arr[i]);
	free(arr);
}

int	reader(core_t *cor)
{
	int is_a_builtin = 0;
	int is_valid = 0;
	char **tmp = NULL;

	if (cor->tree->node == NULL)
		return (is_valid);
	tmp = cor->cmd.param = my_str_to_word_array(cor->tree->node, ' ');
	cor->tree->node = globbing_wildcard(cor->tree->node);
	if (!cor->tree->node) {
		my_printf("%s: No match.\n", tmp[0]);
		free_tab(tmp);
		return (1);
	}
	cor->cmd.param = my_str_to_word_array(cor->tree->node, ' ');
	if ((is_valid = browse_operator(cor)) < 0)
		return (-(is_valid + 1));
	is_valid = browse_builtin(cor, &is_a_builtin);
	if (is_a_builtin == 0)
		is_valid = browse_path(cor->env, cor->cmd, cor->fd);
	return (is_valid);
}
