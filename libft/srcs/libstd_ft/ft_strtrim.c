/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:33:17 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/29 11:50:40 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		stopstring(char const *s)
{
	int i;

	i = ft_strlen(s) - 1;
	while (i >= 0 && (s[i] == ' ' || s[i] == ','
			|| s[i] == '\n' || s[i] == '\t'))
		i--;
	return (i + 1);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		st;
	char	*ret;

	i = 0;
	j = 0;
	ret = NULL;
	if (s == NULL)
		return (NULL);
	while (s[i] && (s[i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t'))
		i++;
	st = stopstring(s);
	if ((st >= i && !(ret = (char *)malloc(st - i + 1)))
			|| (!ret && !(ret = (char *)malloc(1))))
		print_err("Malloc error: ft_strtrim");
	while (i < st)
	{
		ret[j] = s[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
