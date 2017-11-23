/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 11:26:57 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/26 14:15:42 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>
#include <stdarg.h>
#include <wchar.h>
#include <stdlib.h>

int		verif_conv(char type)
{
	static char tab[18] = {"disSCfuUoOxXpDc%Fb"};

	if (ft_strchr(tab, type))
		return (1);
	return (-1);
}

void	*err_void(void *err, void *res)
{
	if (res == err)
		return (NULL);
	return (res);
}

int		null_str_verif(void *content, char **ct_str, char type)
{
	static wchar_t	nullwstr[8] = L"(null)\0";
	int				ret;
	int				i;

	ret = 0;
	i = 0;
	if (type == 's' && content == NULL)
	{
		ft_strcat(*ct_str, "(null)");
		return (1);
	}
	else if (type == 'S' && content == NULL)
		while (nullwstr[i])
		{
			ret += convert_utf(nullwstr[i], ct_str);
			i++;
		}
	return (ret);
}

void	pprint_err(char *str)
{
	write(2, str, ft_strlen(str));
	exit(-1);
}
