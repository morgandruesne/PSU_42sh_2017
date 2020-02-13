/*
** EPITECH PROJECT, 2018
** history node function
** File description:
** my_42sh
*/

#include "input.h"

node_t	*create_node_his(char *add)
{
	node_t *new = malloc(sizeof(node_t));

	if (!new)
		return (NULL);
	new->data = strdup(add);
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

node_t	*add_line_history(char *add, node_t *his)
{
	node_t *new = NULL;

	if (!add)
		return (his);
	if (his == NULL) {
		new = create_node_his(add);
		return (new);
	}
	new = create_node_his(add);
	if (!new)
		return (his);
	his->prev = new;
	new->next = his;
	return (new);
}