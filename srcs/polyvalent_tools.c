/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polyvalent_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 13:27:41 by didier            #+#    #+#             */
/*   Updated: 2017/06/09 23:59:14 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int			checkvar_condition(char **args)
{
	int		i;
	char	*ptr;
	int		pos;
	int		var;

	var = 0;
	i = -1;
	while (args[++i])
	{
		if ((ptr = ft_strchr(args[i], '=')))
		{
			pos = ptr - args[i];
			if (!pos || ft_strchr(" 	=", ptr[-1]))
				break ;
		}
		else
			break ;
		var = 1;
	}
	if (!args[i] && var)
		return (2);
	return (args[i] && var ? i : 0);
}

t_list		*is_var_used(t_list *root, char *to_find, int absolute_match,
			int (*f)(t_list *, char *, int))
{
	t_list		*iter;

	iter = root;
	while (iter)
	{
		if (f(iter, to_find, absolute_match))
			return (iter);
		iter = iter->next;
	}
	return (NULL);
}

void		init_shell(t_global *gb)
{
	int				i;
	char			*ptr;
	char			cwd[512];
	extern char		**environ;

	ft_memset(gb, 0, sizeof(t_global));
	i = -1;
	while (environ[++i])
	{
		init_environ(gb, environ[i]);
		if ((ptr = ft_strnstr(environ[i], "PATH=", 5)) && (!ptr[5]))
		{
			gb->g_path = (char **)malloc(sizeof(char *) * 1);
			gb->g_path[0] = NULL;
		}
		else if ((ptr = ft_strnstr(environ[i], "PATH=", 5)))
			gb->g_path = ft_strsplit(ptr + 5, ':');
	}
	ft_strcpy(gb->oldpwd, getcwd(cwd, 512));
}

void		set_home(t_global *gb, char **home)
{
	t_list *one_var;

	ft_memdel((void*)home);
	if ((one_var = is_var_used(gb->lst_env_var, "HOME", 0, &fct_ptr_envar)) &&
		((t_environ*)one_var->content)->value &&
		ft_strlen(((t_environ*)one_var->content)->value) > 0)
		*home = ft_strdup(((t_environ*)one_var->content)->value);
	else
		*home = ft_strdup("/");
}

int			is_quote(char first_occur, char *str, int i)
{
	if ((i == 0 && ft_strchr("\'\"", str[i])) ||
		(i >= 1 && ft_strchr("\'\"", str[i]) &&
		(str[i - 1] != '\\' || first_occur == '\'')))
		return (1);
	return (0);
}
