/*
** EPITECH PROJECT, 2018
** presence char
** File description:
** my_42sh
*/

int	presence_char(char *str, char c)
{
	int i = 0;

	if (!str)
		return (-1);
	while (str[i] != '\0') {
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}