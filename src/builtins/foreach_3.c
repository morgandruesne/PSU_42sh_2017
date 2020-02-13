/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** built-in
*/

#include "minishell2.h"

void	my_simple_prompt_for(void)
{
	if (isatty(0) == 1)
		my_printf("foreach? ");
}

int	comp_list(list_t *param_list)
{
	int i = 0;

	while (param_list != NULL) {
		i++;
		param_list = param_list->next;
	}
	return (i);
}

list_t	*start_foreach(list_t *list)
{
	char *input = NULL;
	int opt = 1;

	while (opt == 1) {
		my_simple_prompt_for();
		input = get_next_line(0);
		if (my_strcmp(input, "end") == 0)
			break;
		list = add_node(list, input);
	}
	return (list);
}

int	foreach(core_t *cor, char **param)
{
	char *var_name;
	list_t	*list = NULL;
	int	nb_boucle = get_nb_rol(param);
	list_t	*param_list = get_param(param);

	if (nb_boucle == -1)
		return (84);
	nb_boucle = comp_list(param_list);
	var_name = get_name_var(param[1]);
	list = start_foreach(list);
	while (nb_boucle > 0) {
		cor->cmd.input = my_strcat("set ", my_strcat(var_name,
		my_strcat("=", param_list->line)));
		executer(cor);
		exec_foreach(cor, list);
		param_list = param_list->next;
		nb_boucle -= 1;
	}
	return (0);
}