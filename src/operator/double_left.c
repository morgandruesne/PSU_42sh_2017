/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

int	create_file(char **name_file)
{
	int fd = 0;

	*name_file = "Td56L_WQ4w2e_pW5M7o_hki1OrS";
	fd =  open(*name_file, O_CREAT | O_WRONLY | O_APPEND, 00644);
	if (fd == -1)
		exit(84);
	return (fd);
}

cmd_t	init_tmp_rm(char *name_file)
{
	cmd_t tmpcmd;

	tmpcmd.cmd = "/bin/rm";
	tmpcmd.param = malloc(sizeof(char*) * 3);
	tmpcmd.param[0] = "/bin/rm";
	tmpcmd.param[1] = name_file;
	tmpcmd.param[2] = NULL;
	return (tmpcmd);
}

int	check_input(char *input, tree_t *tree, int *opt)
{
	if (input == NULL) {
		return (1);
	} else if (my_strcmp(input, tree->right->node) == 0) {
		*opt = 0;
		return (2);
	}
	return (0);
}

fd_t	cfd(int nin, int nout)
{
	fd_t new_fd;

	new_fd.in = nin;
	new_fd.out = nout;
	return (new_fd);
}

int	double_left_operator(core_t *cor)
{
	char *name_file;
	char *input = NULL;
	int fd_new = create_file(&name_file);
	int opt = 1;
	cmd_t tmpcmd = init_tmp_rm(name_file);
	fd_t tmpfd = cfd(0, 1);

	while (opt == 1) {
		my_simple_prompt();
		input = get_next_line(0);
		if (check_input(input, cor->tree, &opt) == 1)
			return (1);
		if (check_input(input, cor->tree, &opt) == 2)
			break;
		input = my_strcat(input, "\n");
		write(fd_new, input, my_strlen(input));
	}
	cor->tree->right->node = my_strdup(name_file);
	left_operator(cor);
	return (exec_cmd(cor->env, tmpcmd, tmpfd));
}
