/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header of the my library.
*/

#ifndef FUNCTION_POINTER_H_
#define FUNCTION_POINTER_H_

#include "minishell2.h"

#define NB_OPERATOR	8

#define NB_BUILTIN	14

static const struct  builtin_fptr blt_list[NB_BUILTIN] = {
	{"exit", &exit_builtin},
	{"env", &display_env},
	{"setenv", &setenv_builtin},
	{"unsetenv", &unsetenv_builtin},
	{"cd", &cd_builtin},
	{"where", &where_builtin},
	{"alias", &alias_builtin},
	{"unalias", &unalias_builtin},
	{"repeat", &repeat_builtin},
	{"set", &set_builtin},
	{"unset", &unset_builtin},
	{"echo", &echo_builtin},
	{"foreach", &foreach},
	{"which", &which_builtin}
};

static const struct  ope_fptr ope_list[NB_OPERATOR] = {
	{";", &semicolon_operator},
	{"&&", &and_operator},
	{"||", &or_operator},
	{"|", &pipe_operator},
	{"<", &left_operator},
	{"<<", &double_left_operator},
	{">", &right_operator},
	{">>", &double_right_operator}
};

#endif
