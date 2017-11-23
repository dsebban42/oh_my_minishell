/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 18:06:04 by didier            #+#    #+#             */
/*   Updated: 2017/07/20 16:09:06 by didier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "minishell.h"
#include <signal.h>

void		select_built_in(t_global *gb, char **args, int b_select)
{
	int (*built_tab[6])();

	built_tab[0] = &ft_echo;
	built_tab[1] = &chdir_manager;
	built_tab[2] = &ft_env;
	built_tab[3] = &ft_unsetenv;
	built_tab[4] = &ft_setenv;
	built_tab[b_select](gb, args);
}

int			built_in(t_global *gb, char **args)
{
	int					b_select;
	static const char	*built_tab[] = {
		"echo", "cd", "env", "unsetenv", "setenv", NULL};

	b_select = -1;
	while (built_tab[++b_select])
		if (!ft_strcmp(args[0], built_tab[b_select]))
		{
			select_built_in(gb, args, b_select);
			return (1);
		}
	return (0);
}

int			cmd_not_found(char *to_print)
{
	ft_printferror("minishell: command not found: %s\n", to_print);
	return (-1);
}

void		command_finder(t_global *gb, char **tab)
{
	char	*path;
	char	*ptr;
	int		cmd_iter;

	if (built_in(gb, tab))
		return ;
	else if ((path = find_in_path(gb->g_path, tab[0])))
		gb->status = process_manage(path, environ_lsttotab(gb), tab);
	else if (checkvar_condition(tab) == 2)
		while (*tab && checkvar_condition(tab))
		{
			ptr = ft_strchr(*tab, '=');
			if (!env_manager(gb, *tab, (ptr - *tab), 0))
				local_var_manager(gb, *tab, (ptr - *tab));
			tab++;
		}
	else if ((cmd_iter = checkvar_condition(tab)))
		command_finder(gb, tab + cmd_iter);
	else if (((ptr = ft_strrchr(tab[0], '/')) && !ft_strchr("	 ", ptr[1])))
	{
		ptr = gb->g_path && !gb->g_path[0] ? tab[0] : ptr;
		gb->status = launch_localprocess(gb, tab, ptr + 1);
	}
	else
		gb->status = cmd_not_found(tab[0]);
}

int			main(void)
{
	t_global	gb;

	init_shell(&gb);
	if (!gb.g_path)
		gb.g_path = ft_strsplit("/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin",
		':');
	if (!gb.lst_env_var)
		print_err("Unable to load environnement to minishell");
	input_manager(&gb);
	del_manager(&gb);
	return (gb.status);
}
