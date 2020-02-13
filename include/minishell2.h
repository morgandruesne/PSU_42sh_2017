/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header of the my library.
*/

#ifndef MINISHELL2_H_
#define MINISHELL2_H_

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
#include <glob.h>
#include "my.h"

typedef struct list_s {
	char *line;
	struct list_s *next;
} list_t;

typedef struct alias_s {
	char *alias;
	char *cmd;
	struct alias_s *next;
} alias_t;

typedef struct qmark {
	char *data;
	struct qmark *next;
} qm_t;

typedef struct cmd_s {
	char *input;
	char **param;
	char **path_list;
	char *cmd;
	char *old_cmd;
	int is_ok;
} cmd_t;

typedef struct tree_s {
	char *node;
	char **pars;
	struct tree_s *left;
	struct tree_s *right;
} tree_t;

typedef struct fd_s {
	int in;
	int out;
} fd_t;

typedef struct core_s {
	struct cmd_s cmd;
	struct list_s *env;
	struct alias_s *alias;
	struct alias_s *local;
	struct tree_s *tree;
	struct fd_s fd;
	qm_t *qm;
} core_t;

struct builtin_fptr {
	char *bls;
	int (*func)(core_t *, char **);
};

struct ope_fptr {
	char *bls;
	int (*func)(core_t *cor);
};

void	prompt(void);
void	my_simple_prompt(void);

/* ---------------------------- INIT PROTOTYPES ----------------------------- */
list_t	*init_env(list_t *);
fd_t	init_file_descriptor(void);
core_t	init_cor(char **env, int ac);
char	**recup_path_list(list_t *);
void	enable_termcaps(int enable);

/* ------------------------- BINARY TREE PROTOTYPES ------------------------- */
tree_t	*lexer(char **);
char	**parser(char *);
int	reader(core_t *cor);
void	executer(core_t *cor);

int	verif_pars(char **);
int	is_simple_ope(char);
int	is_ope(char *, int);
char	*realoc_string(char *, char);
char	**realoc_tab(char **);
int	quote(char **pars, char *str, int *i, int e);
int	verif_second_quote_exist(char *str, int i, char quote);

/* --------------------------- BUILTINS PROTOTYPES -------------------------- */
int	display_env(core_t *, char **);
int	cd_builtin(core_t *, char **);
int	exit_builtin(core_t *, char **);
int	setenv_builtin(core_t *, char **);
int	unsetenv_builtin(core_t *, char **);
int	echo_builtin(core_t *, char **);
int	alias_builtin(core_t *, char **);
int	unalias_builtin(core_t *cor, char **param);
int	where_builtin(core_t *, char **);
int	repeat_builtin(core_t *, char **);
int	set_builtin(core_t *, char **);
int	unset_builtin(core_t *cor, char **param);
int	which_builtin(core_t *, char **);
int	foreach(core_t *cor, char **param);

char	*recup_env_argument(char *);
void	actualise_actual_pwd(list_t *);
void	actualise_old_pwd(list_t *);
int	verif_chdir(char *, char *);
int	cd_back_verif(list_t *);
list_t	*add_node(list_t *, char *);
list_t	*copy_env(char **);
void	ctrl_d(int);
char	*get_new_cmd(char **);
int	setenv_verif_name(char *);
alias_t	*sort_alias(alias_t *alias);
void	remove_alias_line(alias_t *local, char *cmp);
void	remove_alias_first(alias_t *head, alias_t *n);
int	replace_alias(alias_t **alias, char *new_alias, char *new_cmd);
char	*browse_alias(alias_t *alias, char *str);
char	*browse_local_var(alias_t *local, char *str);
int	verif_alias_loop(alias_t *alias, char *str, int *check);

/* -------------------------- OPERATORS PROTOTYPES -------------------------- */
int	semicolon_operator(core_t *cor);
int	pipe_operator(core_t *cor);
int	right_operator(core_t *cor);
int	double_right_operator(core_t *cor);
int	left_operator(core_t *cor);
int	double_left_operator(core_t *cor);
int	and_operator(core_t *cor);
int	or_operator(core_t *cor);

int	verif_file_is_not_a_directory(char *);
int	verif_file_name(char *);
cmd_t	init_tmp_rm(char *name_file);
fd_t	cfd(int nin, int nout);

/* -------------------------- EXECUTES PROTOTYPES --------------------------- */
int	browse_path(list_t *, cmd_t, fd_t);
int	exec_cmd(list_t *list, cmd_t cmd, fd_t fd);
void	core(core_t *cor);

int	check_child_pid(int);
int	check_signal(int);

int	backstick(core_t *cor, char *input, int *i);

alias_t	*init_alias(void);
void	display_alias(alias_t *alias);
alias_t	*add_alias(alias_t *list, char *alias, char *cmd);

/* ---------------------------- QMARK PROTOTYPES ---------------------------- */
qm_t	*create_qmark(char *add);
qm_t	*add_qmark(qm_t *list, char *add);
int	qstrstr(char *ind, char *str);
char	*search_in_qm(qm_t *qm, char *str);
char	*qmark(core_t *core, char *str, int pos);
void	print_qmark_error(core_t *core, char *pref);
char	*recup_str_qm(char *str, int ind);

/* ---------------------------- GLOBING PROTOTYPES -------------------------- */
char	*globbing_wildcard(char *input);
void	create_rep_globing(char **rep, char *str);
char	**recup_paths_wildcard(char *str);
char	*recup_pathern_wildcard(char *str, int *pos);

char	*strc(char *str, char *add, int opt);
int	presence_char(char *str, char c);
char	*replace_word(char *ref, char *rep, int pos, int nb);

int	create_file(char **name_file);
cmd_t	init_tmp_rm(char *name_file);
int	browse_parsing(core_t *cor, char **pars);
int	browse_command(core_t *cor, char *str);

int	exec_foreach(core_t *cor, list_t *list);
int	is_good_foreach(char *str);
int	is_good_nb_arg(char **param);
int	get_nb_rol(char **param);
list_t	*get_param(char **param);
char	*get_name_var(char *str);
int	get_nb_paren_open(char c);
int	get_nb_paren_close(char c);
int	check_param_enter(char **param);
int	get_nb_param(char **param);

#endif /* MINISHELL2_H_ */
