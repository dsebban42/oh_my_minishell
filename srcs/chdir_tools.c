/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 15:42:45 by didier            #+#    #+#             */
/*   Updated: 2017/11/23 16:37:16 by didier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 500
#include "libft.h"
#include "minishell.h"

void	build_path(char *arg, char to_go[512], char *delimiter)
{
	ft_strcpy(to_go, delimiter);
	ft_strcat(to_go, arg);
}

void	reset_wd(t_global *gb, char to_go[512], char cwd[512])
{
	char tmp[512];
	char *ptr;

	ft_memset(tmp, 0, 512);
	if (gb->mode == S_IFLNK)
	{
		ptr = ft_strrchr(to_go, '/');
		ft_strcpy(tmp, ptr);
	}
	getcwd(to_go, 512);
	ft_strcpy(cwd, "PWD=");
	ft_strcat(cwd, to_go);
	if (tmp[0])
	{
		ptr = ft_strrchr(cwd, '/');
		ft_memset(cwd + (ptr - cwd), 0, 512 - (ptr - cwd));
		ft_strcat(cwd, tmp);
	}
	env_manager(gb, cwd, 3, 0);
	ft_strcpy(cwd, "OLDPWD=");
	ft_strcat(cwd, gb->oldpwd);
	env_manager(gb, cwd, 6, 0);
}

void	change_wd(char oldpwd[512], char *to_go)
{
	char cwd[512];

	ft_strcpy(oldpwd, getcwd(cwd, 512));
	chdir(to_go);
}

void	initbuff(char cwd[512], char to_go[512])
{
	ft_memset(cwd, 0, 512);
	ft_memset(to_go, 0, 512);
}

int		is_special_char(char *str)
{
	char c;
	char d;
	char e;

	c = 0;
	d = 0;
	e = 0;
	if (str[0])
	{
		c = str[0];
		if (str[1])
		{
			d = str[1];
			if (str[2])
				e = str[2];
		}
	}
	if (!c || (c == '~' && !d) || (c == '/' && !d) || (c == '-' && !d) ||
		(c == '-' && d == '-' && !e) || (c == '~' && d == '/' && !e))
		return (1);
	return (0);
}
