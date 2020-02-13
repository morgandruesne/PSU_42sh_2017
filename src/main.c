/*
** EPITECH PROJECT, 2017
** title
** File description:
** Description.
*/

#include "input.h"

void	prompt(void)
{
	char *pwd_tmp = NULL;

	if (isatty(0) == 1) {
		pwd_tmp = getcwd(NULL, 0);
		my_printf("%s> ", pwd_tmp);
		free (pwd_tmp);
	}
}

void	my_simple_prompt(void)
{
	if (isatty(0) == 1)
		my_printf("? ");
}

void	executer(core_t *cor)
{
	char **pars = NULL;

	if (browse_command(cor, cor->cmd.input) == 84)
		return;
	if ((pars = parser(cor->cmd.input)) == NULL)
		return;
	if ((cor->cmd.is_ok = browse_parsing(cor, pars)) == 1)
		return;
	if ((cor->cmd.is_ok = verif_pars(pars)) == 1)
		return;
	cor->tree = lexer(pars);
	cor->cmd.is_ok = reader(cor);
	cor->cmd.old_cmd = cor->cmd.input;
}

int	main(int ac, char **av, char **env)
{
	core_t cor;

	(void) av;
	cor = init_cor(env, ac);
	while (1)
		core(&cor);
}
