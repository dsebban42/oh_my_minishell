/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_char_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 13:32:11 by dsebban           #+#    #+#             */
/*   Updated: 2016/06/23 13:36:41 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		len(char **tab)
{
	int t_len;

	t_len = 0;
	while (tab[t_len])
		t_len++;
	return (t_len);
}

void	sort_char_tab(char **tab, int s_type)
{
	int		i;
	int		j;
	int		t_len;
	char	*swap;

	i = 0;
	t_len = len(tab);
	while (i < t_len)
	{
		j = 0;
		while (j < i)
		{
			if (!s_type ? ft_strcmp(tab[j], tab[i]) > 0 :
				ft_strcmp(tab[j], tab[i]) < 0)
			{
				swap = tab[i];
				tab[i] = tab[j];
				tab[j] = swap;
			}
			j++;
		}
		i++;
	}
}
