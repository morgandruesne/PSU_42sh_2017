/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header of the my library.
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>

void	my_printf(char *str, ...);
void	my_fprintf(char *str, ...);
void	my_putchar(char);
void	my_fputchar(char);
int	my_putnbr(int);
int	my_fputnbr(int);
int	my_putstr(char const*);
int	my_fputstr(char const*);
int	my_strlen(char const*);
int	my_tablen(char **);
int	my_getnbr(char const*);
int	my_pow(int, int);
int	my_sqrt(int);
char	*my_revstr(char*);
int	my_strcmp(char const*, char const*);
int	my_strncmp(char const*, char const*, int);
char	*my_strcat(char*, char*);
char	*my_strdup(char const *);
char	**my_str_to_word_array(char const *, char);
char	*my_str_cleaner(char *);
char	*get_next_line(int);
char	*my_charcat(char *, char);
int	my_str_isnum(char const *);

#endif	/* MY_H_ */
