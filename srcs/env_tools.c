/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:42:35 by dsebban           #+#    #+#             */
/*   Updated: 2017/11/23 16:55:39 by didier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "libftprintf.h"

void		print_env(t_list *curr)
{
	t_environ *var;

	var = (t_environ *)curr->content;
	ft_printf("%s=%s\033[0m\n", var->name, var->value);
}

void		cpy_env(t_list *dst, t_list *src)
{
	t_environ *var_src;
	t_environ *var_dst;

	var_src = (t_environ *)src->content;
	var_dst = (t_environ *)dst->content;
	var_dst->name = ft_strdup(var_src->name);
	var_dst->value = ft_strdup(var_src->value);
}

void		name_value(t_global *gb_tmp, char **args, int *i)
{
	char	*ptr;

	if (args[*i])
	{
		ptr = ft_strchr(args[*i], '=');
		env_manager(gb_tmp, args[*i], (ptr - args[*i]), 1);
		gb_tmp->opt.env_opt |= 0x10;
	}
}

char		**environ_lsttotab(t_global *gb)
{
	t_list		*iter;
	t_environ	*env;
	char		*tmpname;
	char		*fullstr;
	char		**envret;

	INIT(int, i, 0);
	iter = gb->lst_env_var;
	envret = (char **)malloc(sizeof(char *) * (count_node(iter) + 1));
	while (iter)
	{
		env = (t_environ*)iter->content;
		tmpname = ft_strjoin(env->name, "=");
		fullstr = ft_strjoin(tmpname, env->value);
		envret[i] = fullstr;
		ft_memdel((void*)&tmpname);
		iter = iter->next;
		i++;
	}
	envret[i] = NULL;
	return (envret);
}

void		create_envvar(t_global *gb, char *name, char *value)
{
	t_environ	*curr;
	t_list		*list;

	curr = ft_memalloc(sizeof(t_environ));
	curr->name = ft_strdup(name);
	curr->value = ft_strdup(value);
	//name_up(&curr->name);
	list = lst_create(&gb->lst_env_var, 'b');
	ft_memset(&list->content, 0, sizeof(t_environ));
	list->content = (t_environ*)curr;
	if (!ft_strcmp(name, "PATH"))
	{
		free_tab((void***)&gb->g_path);
		if (ft_strlen(value) > 0)
			gb->g_path = ft_strsplit(value, ':');
	}
}
