/*
** EPITECH PROJECT, 2018
** qmark
** File description:
** my_42sh
*/

#include "input.h"

char	*recup_str_qm(char *str, int ind)
{
	int i = ind +1;
	int ps = 0;
	char *ret = malloc(sizeof(char));

	if (!ret)
		return (NULL);
	ret[0] = '\0';
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '['  
	&& str[i] != ']' && str[i] != '"' && str[i] != '\\' && 
	str[i] != '*' && str[i] != '`') {
		if (i == (ind +1) && str[i] == '!') {
			ret = add_letter(ret, '!', 0);
			return (ret);
		}
		ret = add_letter(ret, str[i], ps);
		ps++;
		i++;
	}
	ret = (ret[0] == '\0') ? NULL : ret;
	return (ret);
}

void	print_qmark_error(core_t *core, char *pref)
{
	if (my_strcmp_2(pref, "!") != 0)
		my_fprintf("%s: Event not found.\n", pref);
	else
		my_fprintf("0: Event not found.\n");
	core->cmd.is_ok = 1;
}

char	*qmark(core_t *core, char *str, int pos)
{
	char *pref = NULL;
	char *rep = NULL;
	char *ret = NULL;

	if (!str || pos < 0)
		return (NULL);
	pref = recup_str_qm(str, pos);
	if (pref == NULL)
		return (str);
	rep = search_in_qm(core->qm, pref);
	if (rep == NULL) {
		print_qmark_error(core, pref);
		return (NULL);
	}
	ret = replace_word(str, rep, pos, strlen(pref) +1);
	if (ret == NULL)
		return (NULL);
	ret = my_str_cleaner(ret);
	return (ret);
}