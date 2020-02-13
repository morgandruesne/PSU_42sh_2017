/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

int	linked_list_len(list_t *list)
{
	int len = 0;

	while (list) {
		len++;
		list = list->next;
	}
	return (len);
}

char	**linked_list_to_tab(list_t *list)
{
	int i;
	char **env = malloc(sizeof(char*) * (linked_list_len(list) + 1));

	for (i = 0; list; i++) {
		env[i] = my_strdup(list->line);
		list = list->next;
	}
	env[i] = NULL;
	return (env);
}

void	check_error(int error, cmd_t cmd)
{
	char *tmp = cmd.param[0];

	if (error == EACCES)
		my_printf("%s: Permission denied.\n", tmp);
	else if (error == ENOEXEC)
		my_printf("%s: Exec format error. Wrong Architecture.\n", tmp);
	exit (-1);
}

int	exec_cmd(list_t *list, cmd_t cmd, fd_t fd)
{
	int child_pid = 0;
	int return_value = 0;
	pid_t pid = fork();

	if (pid == -1)
		return (0);
	if (pid == 0) {
		dup2(fd.in, 0);
		dup2(fd.out, 1);
		if (execve(cmd.cmd, cmd.param, linked_list_to_tab(list)) == -1)
			check_error(errno, cmd);
	} else {
		waitpid(pid, &child_pid, 0);
		return_value = check_child_pid(child_pid);
	}
	return (return_value);
}

int	browse_path(list_t *list, cmd_t cmd, fd_t fd)
{
	char *tmp = NULL;
	int is_succes = 0;

	cmd.cmd = my_strdup(cmd.param[0]);
	for (int i = 0; cmd.path_list[i]; i++) {
		tmp = my_strcat(cmd.path_list[i], my_strcat("/", cmd.param[0]));
		if (access(tmp, F_OK) == 0 && strcmp(cmd.cmd, "\0") != 0) {
			cmd.cmd = my_strdup(tmp);
			break;
		} else
			tmp = NULL;
	}
	if (access(cmd.cmd, F_OK) == 0 ) {
		is_succes = exec_cmd(list, cmd, fd);
	} else {
		my_printf("%s: Command not found.\n", cmd.param[0]);
		is_succes = 1;
	}
	return (is_succes);
}
