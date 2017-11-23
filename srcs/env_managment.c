/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_managment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 18:07:32 by didier            #+#    #+#             */
/*   Updated: 2016/11/27 11:19:30 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int			fct_ptr_envar(t_list *iter, char *to_find, int absolute_match)
{
	t_environ	*curr;

	curr = (t_environ*)iter->content;
	if (absolute_match)
	{
		if (!ft_strcmp(to_find, curr->name))
			return (1);
	}
	else if (ft_strnstr(to_find, curr->name, ft_strlen(curr->name)))
		return (1);
	return (0);
}

static void	modify_envvar(t_list *list, char *ptr)
{
	t_environ	*curr;
	int			i;

	i = 0;
	curr = (t_environ*)list->content;
	ft_memdel((void**)&curr->value);
	curr->value = NULL;
	while ((ptr[i]) && (ptr[i] != ' ' || ptr[i] != '	'))
		i++;
	curr->value = ft_strsub(ptr, 1, i);
}

void		init_environ(t_global *gb, char *arg)
{
	t_environ	*curr;
	t_list		*list;
	char		*ptr;
	int			pos;

	ptr = ft_strchr(arg, '=');
	if (ptr + 1)
	{
		curr = ft_memalloc(sizeof(t_environ));
		pos = ptr - arg;
		curr->name = ft_strsub(arg, 0, pos);
		if (!ft_strcmp(curr->name, "SHELL"))
			curr->value = ft_strdup("./minishell");
		else if (!ft_strcmp(curr->name, "HOME") && ((!arg)
			|| (arg && !ft_strlen(arg))))
			curr->value = ft_strdup("/");
		else
			curr->value = ft_strdup(arg + pos + 1);
		list = lst_create(&gb->lst_env_var, 'b');
		ft_memset(&list->content, 0, sizeof(t_environ));
		list->content = (t_environ*)curr;
	}
}

int			const_envvar(char *name)
{
	if (!ft_strcmp(name, "HOME") || !ft_strcmp(name, "PWD")
		|| !ft_strcmp(name, "PATH") || !ft_strcmp(name, "OLDPWD"))
		return (1);
	return (0);
}

int			env_manager(t_global *gb, char *str, int pos, int call)
{
	t_list	*tmp;
	char	*name;
	int		end;

	end = pos;
	while (pos > 0 && (str[pos] != ' ' || str[pos] != '	'))
		pos--;
	name = ft_strsub(str, pos, (end - pos));
	if ((tmp = is_var_used(gb->lst_env_var, name, 1, &fct_ptr_envar)))
	{
		modify_envvar(tmp, (str + end));
		if (!ft_strcmp(name, "PATH"))
		{
			free_tab((void***)&gb->g_path);
			if (ft_strlen(((t_environ*)tmp->content)->value) > 0)
				gb->g_path = ft_strsplit(((t_environ*)tmp->content)->value,
				':');
		}
	}
	else if (const_envvar(name) || call)
		create_envvar(gb, name, str + end + 1);
	else
		end = 0;
	ft_memdel((void**)&name);
	return (end);
}
