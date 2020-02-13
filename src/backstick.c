/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

int	generate_temp_file(void)
{
	char *name_file = "TY56L_hQ4w2e_po5M7o_Lki1erS";
	int fd = open(name_file, O_CREAT | O_RDWR);

	if (fd == -1)
		exit(84);
	return (fd);
}

int	looking_for_command(core_t *cor, char *input, int *i)
{
	char *command = NULL;

	*i += 1;
	if (verif_second_quote_exist(input, *i, '`') == 0) {
		my_printf("Unmatched '`'.\n");
		return (84);
	}
	for (; input[*i] != '`'; *i += 1)
		command = realoc_string(command, input[*i]);
	if (command == NULL)
		return (1);
	cor->cmd.input = command;
	return (0);
}

char	*replace_by_new_command(char *input, char *new_cmd, int i)
{
	char *final_cmd = NULL;

	for (int j = 0; j < i; j++)
		final_cmd = realoc_string(final_cmd, input[j]);
	final_cmd = my_strcat(final_cmd, new_cmd);
	return (final_cmd);
}

void	remove_temp_file(core_t *cor)
{
	char *name_file = "TY56L_hQ4w2e_po5M7o_Lki1erS";
	cmd_t tmpcmd = init_tmp_rm(name_file);
	fd_t tmpfd = cfd(0, 1);

	exec_cmd(cor->env, tmpcmd, tmpfd);
}

int	backstick(core_t *cor, char *input, int *i)
{
	int save = *i;
	int tmp = looking_for_command(cor, input, i);
	char *new_cmd = NULL;
	char *input_file = NULL;
	int fd = 0;

	if (tmp == 84)
		return (84);
	else if (tmp == 1)
		return (0);
	fd = generate_temp_file();
	cor->fd.out = fd;
	executer(cor);
	lseek(fd, 0, SEEK_SET);
	while ((input_file = get_next_line(fd)) != NULL)
		new_cmd = my_strcat(new_cmd, my_strcat(input_file, " "));
	remove_temp_file(cor);
	cor->fd.out = 0;
	cor->cmd.input = replace_by_new_command(input, new_cmd, save);
	return (0);
}
