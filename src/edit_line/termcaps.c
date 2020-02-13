/*
** EPITECH PROJECT, 2018
** termcaps
** File description:
** my_sh2
*/

#include "input.h"

int 	my_putchar1(int c)
{
	write(1, &c, 4);
	return (1);
}

void	enable_termcaps(int enable)
{
	struct termios term;

	tcgetattr(0, &term);
	if (enable == 1) {
		term.c_lflag &= ~(ICANON);
		term.c_lflag &= ~(ECHO);
		tcsetattr(0, TCSANOW, &term);
		return;
	}
	term.c_lflag = (ICANON | ECHO);
	tcsetattr(0, TCSANOW, &term);
}

void	termx(char *str)
{
	int i = 0;
	char *tmp = NULL;

	if (!str || (tmp = tgetstr(str, NULL)) == NULL)
		return;
	for (; tmp[i] != '\0'; i++);
	tputs(tmp, 1, my_putchar1);
}

void	left(void)
{
	termx("le");
}

void	right(void)
{
	termx("nd");
}