/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 14:52:04 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/29 11:48:11 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_count(char **src)
{
	int i;

	i = 0;
	if (src)
	{
		while (src[i])
			i++;
	}
	return (i);
}

char			**tabdup(char **src, int size_array)
{
	int		size;
	int		i;
	char	**ret_tab;

	i = 0;
	if (size_array == -1)
		size = ft_count(src);
	else
		size = size_array;
	if (!(ret_tab = (char **)malloc(sizeof(char *) * (size + 1))))
		print_err("Malloc error: tabdup");
	while (src && src[i] && i < size)
	{
		ret_tab[i] = ft_strdup(src[i]);
		i++;
	}
	ret_tab[i] = NULL;
	return (ret_tab);
}
