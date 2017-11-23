/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 17:13:56 by didier            #+#    #+#             */
/*   Updated: 2017/11/23 16:35:00 by didier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include "libftprintf.h"
# include <stdlib.h>
# define PROMPT "\033[0m$ >"

typedef struct			s_opt
{
	unsigned			echo_opt;
	unsigned			env_opt;
}						t_opt;

typedef struct			s_local_var
{
	char				*name;
	char				*value;
}						t_local_var;

typedef struct			s_environ
{
	char				*name;
	char				*value;
}						t_environ;

typedef struct			s_command
{
	char				**args;
	int					type;
	struct s_command	*next;
}						t_command;

typedef struct			s_global
{
	int					status;
	int					mode;
	char				oldpwd[512];
	char				**g_path;
	t_environ			env;
	t_opt				opt;
	t_local_var			lc_var;
	t_list				*lst_lc_var;
	t_list				*lst_env_var;
	t_command			*lst_cmd;
}						t_global;

/*
**command_separator
*/
t_command				*cpy_args(t_command *curr, char **tmparray);
char					**separator_no_match(char **tmparray, char *str);
t_command				*separator_match(t_global *gb, t_command *curr,
						char ***tmparray);
t_command				*add_args_to_command(t_command *curr, char **tab);
t_command				*init_current_position(t_command **root);

/*
**command_parsing
*/
char					*match_and_treat_exceptions(char *str);
void					parse_command_separator(t_global *gb, char ***tab,
						int is_normal);
t_command				*new_command(t_command **root);
int						is_quote(char first_occur, char *str, int i);
void					var_to_commandline(t_global *gb, char *ptr,
						char ***tab, int i);
void					command_finder(t_global *gb, char **tab);
void					input_manager(t_global *gb);
char					**with_delimiters_args(char **tab, char *str,
						int st, int len);
char					**without_delimiters_args(char **tab, char *str,
						int st, int i);
int						lexical_parser(char **str, t_list **list, int i);
void					split_parsed_str(t_global *gb,
						char *str, t_list *list);

/*
**built_in
*/
int						built_in(t_global *gb, char **args);
int						ft_unsetenv(t_global *gb, char **args);
int						ft_setenv(t_global *gb, char **args);
int						ft_echo(t_global *gb, char **args);
int						ft_env(t_global const *gb, char **args);

/*
**local_var_manager
*/
int						fct_ptr_lcvar(t_list *iter, char *to_find,
						int absolute_match);
void					local_var_manager(t_global *gb, char *str, int pos);

/*
**local&environ_both
*/
int						checkvar_condition(char **args);
t_list					*is_var_used(t_list *root, char *to_find,
						int absolute_match, int (*f)(t_list *, char *, int));

/*
**environnement
*/
void					create_envvar(t_global *gb, char *name, char *value);
void					del_envar(t_list *lst);
char					**environ_lsttotab(t_global *gb);
int						fct_ptr_envar(t_list *iter, char *to_find,
						int absolute_match);
int						env_manager(t_global *gb, char *str, int pos, int call);
void					init_environ(t_global *gb, char *arg);
void					set_home(t_global *gb, char **home);
int						parse_envopt(t_global *gb_tmp, char **args);
void					cpy_env(t_list *dst, t_list *src);
void					print_env(t_list *curr);
void					name_value(t_global *gb_tmp, char **args, int *i);

/*
**free
*/
void					del_commands(t_command **commands);
void					del_manager(t_global *gb);

/*
**process
*/
int						launch_localprocess(t_global *gb, char **args,
						char *dot_slashptr);
int						process_manage(char *path, char **envtab, char **args);

/*
**cd_functions
*/
void					reset_wd(t_global *gb, char to_go[512], char cwd[512]);
int						chdir_manager(t_global *gb, char **args);
void					initbuff(char cwd[512], char to_go[512]);
void					change_wd(char oldpwd[512], char *to_go);
int						is_special_char(char *str);
void					build_path(char *arg, char to_go[512], char *delimiter);

void					name_up(char **name);
void					init_shell(t_global *gb);

#endif
