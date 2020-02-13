/*
** EPITECH PROJECT, 2018
** clear and disp
** File description:
** my_42sh
*/

#include "input.h"

void 	color_prompt(void)
{
	char *color = tgetstr("AF", NULL);
	char *reset = tgetstr("me", NULL);
	char *pwd_tmp = NULL;

	tputs(tparm(color, COLOR_CYAN), 1, my_putchar1);
	termx("md");
	if (isatty(0) == 1) {
		pwd_tmp = getcwd(NULL, 0);
		my_printf("< %s > ", pwd_tmp);
		free (pwd_tmp);
	}
	tputs(reset, 1, my_putchar1);
}

void 	clrdisp(edl_t line)
{
	if (line.line[0] != 0)
		termx("sc");
	termx("dl");
	for (unsigned int i = line.pc; i <= strlen(line.line); i++)
		termx("le");
	color_prompt();
	write(1, line.line, strlen(line.line));
	if (line.line[0] != 0)
		termx("rc");
}
