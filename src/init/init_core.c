/*
** EPITECH PROJECT, 2018
** init core
** File description:
** my_42sh
*/

#include "input.h"

alias_t	*init_alias(void)
{
	alias_t *alias = NULL;

	alias = add_alias(alias, NULL, NULL);
	return (alias);
}

core_t	init_cor(char **env, int ac)
{
	core_t cor;

	cor.fd = init_file_descriptor();
	cor.env = copy_env(env);
	cor.alias = init_alias();
	cor.local = init_alias();
	cor.tree = NULL;
	if (cor.env == NULL || ac != 1)
		exit (84);
	cor.env = init_env(cor.env);
	cor.cmd.path_list = recup_path_list(cor.env);
	cor.cmd.is_ok = 0;
	cor.cmd.old_cmd = NULL;
	cor.qm = NULL;
	return (cor);
}
