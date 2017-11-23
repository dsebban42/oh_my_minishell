/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_catch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 10:21:17 by dsebban           #+#    #+#             */
/*   Updated: 2016/11/27 11:16:44 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int		spacing_char(char **ret, int j)
{
	ft_strcat((*ret) + j, " ; ");
	j += 2;
	return (j);
}

char	*match_and_treat_exceptions(char *str)
{
	int		untouch;
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	untouch = 0;
	ret = ft_strnew(ft_strlen(str) + (count_occur(str, ';') * 2));
	while ((str[i]) && (str[i] == ' ' || str[i] == '	'))
		i++;
	while (str[i])
	{
		(i > 1 && is_quote(0, str, i)) ? untouch = ~untouch : 0;
		if (str[i] == ';')
			j = spacing_char(&ret, j);
		else
			ret[j] = str[i];
		j++;
		i++;
	}
	ft_memdel((void**)&str);
	return (ret);
}
