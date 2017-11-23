/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:07:52 by dsebban           #+#    #+#             */
/*   Updated: 2017/11/23 16:57:47 by didier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "libftprintf.h"

static int	opt_wihoutparam(t_global *gb_tmp, char *tmpstr)
{
	int		i;

	i = 1;
	if (tmpstr[0] == '-')
	{
		while ((tmpstr[i]) && (ft_strchr("iv", tmpstr[i])))
		{
			tmpstr[i] == 'i' ? gb_tmp->opt.env_opt |= 0x2 : 0;
			tmpstr[i] == 'v' ? gb_tmp->opt.env_opt |= 0x4 : 0;
			i++;
		}
		return (!tmpstr[i] ? 1 : 0);
	}
	return (0);
}

int			altpath(t_global *gb_tmp, char **args, int *i)
{
	if (args[*i] && args[*i + 1])
	{
		gb_tmp->g_path = tab_add_element(NULL, args[*i + 1]);
		*i += 2;
		gb_tmp->opt.env_opt |= 0x8;
		return (0);
	}
	return (1);
}

static int	opt_withparam(t_global *gb_tmp, char **args, int *i)
{
	while (args[*i])
	{
		if (args[*i][0] == '-')
		{
			if (args[*i] && !(ft_strallchr(args[*i] + 1, 'P')))
				altpath(gb_tmp, args, i);
			if (args[*i] && !(ft_strallchr(args[*i] + 1, 'u')))
				*i += ft_unsetenv(gb_tmp, args + *i);
		}
		if (args[*i] && (checkvar_condition(args + *i)))
			name_value(gb_tmp, args, i);
		else
			break ;
		(*i)++;
	}
	return (0);
}

int			parse_envopt(t_global *gb_tmp, char **args)
{
	int	i;

	i = 1;
	while (args[i] && opt_wihoutparam(gb_tmp, args[i]))
		i++;
	if (gb_tmp->opt.env_opt & 0x2)
	{
		ft_lstiter(gb_tmp->lst_env_var, &del_envar);
		ft_lstdel(&gb_tmp->lst_env_var);
	}
	opt_withparam(gb_tmp, args, &i);
	return (i);
}

int			ft_env(t_global const *gb, char **args)
{
	t_global	gb_tmp;
	int			tab_inc;
	unsigned	o;

	ft_memset(&gb_tmp, 0, sizeof(t_global));
	ft_lstcopy(gb->lst_env_var, &gb_tmp.lst_env_var,
		sizeof(t_environ), &cpy_env);
	gb_tmp.opt.env_opt = 0;
	gb_tmp.g_path = tabdup(gb->g_path, -1);
	tab_inc = parse_envopt(&gb_tmp, args);
	o = gb_tmp.opt.env_opt;
	if (!(o & 0x4) && args[tab_inc])
		command_finder(&gb_tmp, args + tab_inc);
	else if (!(o & 0x2) && !(o & 0x4) && !(o & 0x8)
			&& !(o & 0x10) && !(o & 0x20))
		ft_lstiter(gb_tmp.lst_env_var, &print_env);
	del_manager(&gb_tmp);
	return (0);
}
