/*
** EPITECH PROJECT, 2018
** qmark_node
** File description:
** my_42sh
*/

#include "input.h"

qm_t	*create_qmark(char *add)
{
	qm_t *new = NULL;

	if (add == NULL)
		return (NULL);
	new = malloc(sizeof(qm_t));
	if (!new)
		return (NULL);
	new->data = strdup(add);
	new->next = NULL;
	return (new);
}

qm_t	*add_qmark(qm_t *list, char *add)
{
	qm_t *new = NULL;

	if (add == NULL)
		return (list);
	new = create_qmark(add);
	if (new == NULL)
		return (list);
	if (!list)
		return (new);
	new->next = list;
	return (new);

}


int	qstrstr(char *ind, char *str)
{
	int i = 0;

	if (strlen(ind) < strlen(str))
		return (1);
	while (str[i] != '\0') {
		if (str[i] == ind[i])
			i++;
		else
			return (1);
	}
	return (0);
}

char	*search_in_qm(qm_t *qm, char *str)
{
	qm_t *tmp = NULL;

	if (!str || !qm)
		return (NULL);
	tmp = qm;
	if (my_strcmp_2(str, "!") == 0)
		return ((!qm) ? NULL : my_strdup(qm->data));
	while (tmp != NULL) {
		if (qstrstr(tmp->data, str) == 0)
			return (strdup(tmp->data));
		tmp = tmp->next;
	}
	return (NULL);
}