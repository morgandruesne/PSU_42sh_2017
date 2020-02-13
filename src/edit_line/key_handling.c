/*
** EPITECH PROJECT, 2018
** key handling
** File description:
** my_42sh
*/

#include "input.h"

int	my_strcmp_2(char *str, char *cmp)
{
	int lenstr = -1;
	int lencmp = -1;
	int i = 0;

	if (!str || !cmp)
		return (1);
	while (str[++lenstr] != '\0');
	while (cmp[++lencmp] != '\0');
	if (lenstr != lencmp)
		return (1);
	while (str[i] != '\0') {
		if (str[i] != cmp[i])
			return (1);
		i++;
	}
	return (0);
}

int 	my_key(int key)
{
	static int my_key = -1;

	if (key == 0)
		return (my_key);
	else
		my_key = key;
	return (key);
}

void 	key_handling(int key, edl_t *line, int *status, core_t *cor)
{
	char c;
	int tmp = 0;
	int state = 0;

	key_handling_move_line(key, &state, line);
	control_c(key, &state, line, status);
	control_d(key, &state, line, status);
	control_l(key, &state, line, status);
	key_handling_move_history(key, line, &state);
	key_handling_line(key, line, &state, &c);
	tmp = key_handling_valid_line(&c, &state, cor, line);
	if (tmp == 1)
		*status = 0;
	my_key(-1);
}