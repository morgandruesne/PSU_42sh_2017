/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "minishell2.h"

int	check_signal(int sig)
{
	if (sig == SIGSEGV) {
		my_printf("Segmentation fault\n");
		return (139);
	} else if (sig == SIGFPE) {
		my_printf("Floating exception\n");
		return (136);
	}
	return (0);
}

int	check_signal_dumped(int sig)
{
	if (sig == SIGSEGV) {
		my_printf("Segmentation fault (core dumped)\n");
		return (139);
	} else if (sig == SIGFPE) {
		my_printf("Floating exception (core dumped)\n");
		return (136);
	}
	return (0);
}

int	check_child_pid(int child_pid)
{
	int return_value = 0;

	if (WEXITSTATUS(child_pid))
		return_value = 1;
	if (WIFSIGNALED(child_pid)) {
		if (WCOREDUMP(child_pid))
			return_value = check_signal_dumped(WTERMSIG(child_pid));
		else
			return_value = check_signal(WTERMSIG(child_pid));
	}
	return (return_value);
}
