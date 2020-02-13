/*
** EPITECH PROJECT, 2018
** sos
** File description:
** 42-pls-sh
*/

#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <term.h>
#include <ncurses.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
//#include "my.h"
#include "minishell2.h"

typedef struct history {
	char *data;
	struct history *prev; //liste chaînée pour la data de l'historique
	struct history *next;
} node_t;

typedef struct edit_line_s {
	char *line;
	int pc;
	node_t *his;
} edl_t;

int 	my_putchar1(int c);
int	my_strcmp_2(char *str, char *cmp);

void 	color_prompt(void);
void 	init_term(edl_t *line);
int 	my_key(int key);

/*-------------------------- control functions ------------------------------*/
void	control_c(int key, int *s, edl_t *line, int *status);
void	control_l(int key, int *s, edl_t *line, int *status);
void	control_d(int key, int *s, edl_t *line, int *status);

/*-------------------------- termx ------------------------------------------*/
void	enable_termcaps(int enable);
void	termx(char *str);
void	left(void);
void	right(void);

/*-------------------------- function letter str ----------------------------*/
char	*add_letter(char *s, char c, int pos);
char	*supr_letter(char *s, int pos);

/*-------------------------- handling line ----------------------------------*/
void	key_handling_line(int key, edl_t *line, int *state, char *c);
void	key_handling_move_line(int key, int *s, edl_t *l);
int	key_handling_valid_line(char *c, int *state, core_t *cor, edl_t *line);
char 	*reset_line(edl_t *line);
void 	key_handling(int key, edl_t *line, int *status, core_t *cor);

/*-------------------------- display line -----------------------------------*/
void 	clrdisp(edl_t line);

/*-------------------------- history ----------------------------------------*/
node_t	*add_line_history(char *add, node_t *his);
void	key_handling_move_history(int key, edl_t *line, int *s);
void	reset_ind_his(edl_t *line);
node_t	*create_node_his(char *add);

#endif /* INPUT_H_ */