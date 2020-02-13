/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** printf function.
*/

#include "../../include/my.h"

void	display_flag_f(char c, va_list list)
{
	switch (c) {
		case 'd':
		case 'i':
			my_fputnbr(va_arg(list, int));
			break;
		case 's':
			my_fputstr(va_arg(list, char*));
			break;
		case 'c':
			my_fputchar((char)va_arg(list, int));
			break;
		default:
			return;
	}
}

void	my_fprintf(char *str, ...)
{
	va_list list;

	va_start(list, str);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '%') {
			display_flag_f(str[i + 1], list);
			i++;
		} else
			my_fputchar(str[i]);
	}
	va_end(list);
}
