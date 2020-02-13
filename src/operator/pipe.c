/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

void	init_fd_left_and_right(fd_t *left, fd_t *right, fd_t fd, int pipefd[2])
{
	left->in = fd.in;
	left->out = pipefd[1];
	right->in = pipefd[0];
	right->out = fd.out;
}

int	init_pipe_and_fork(fd_t *left, fd_t *right, fd_t fd, int pipefd[2])
{
	pid_t pid;

	if (pipe(pipefd) == -1)
		return (-84);
	init_fd_left_and_right(left, right, fd, pipefd);
	if ((pid = fork()) == -1)
		return (-84);
	return (pid);
}

void	pipe_operator_child(core_t *cor, int pipefd, fd_t right)
{
	close(pipefd);
	cor->tree = cor->tree->right;
	cor->fd = right;
	exit (reader(cor));
}

int	pipe_operator_parent(core_t *cor, int pipefd, int *is_valid, pid_t pid)
{
	int child_pid = 0;

	*is_valid = reader(cor);
	close(pipefd);
	waitpid(pid, &child_pid, 0);
	return (check_child_pid(child_pid));
}

int	pipe_operator(core_t *cor)
{
	int pipefd[2];
	int is_valid = 0;
	int tmp = 0;
	fd_t left;
	fd_t right;
	pid_t pid;

	if ((pid = init_pipe_and_fork(&left, &right, cor->fd, pipefd)) == -84)
		return (0);
	if (pid == 0) {
		pipe_operator_child(cor, pipefd[1], right);
	} else {
		cor->tree = cor->tree->left;
		cor->fd = left;
		tmp = pipe_operator_parent(cor, pipefd[1], &is_valid, pid);
	}
	return ((is_valid == 1) ? 1 : tmp);
}
