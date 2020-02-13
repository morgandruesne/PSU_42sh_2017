/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** checks if a string is only composed of numeric characters.
*/

int	my_str_isnum(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
			return (1);
		i++;
	}
	return (0);
}
