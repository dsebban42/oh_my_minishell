/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mki_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 22:06:07 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/29 11:47:09 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		**init(int **tab, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

int				**mki_tab(int x, int y)
{
	int		**tab;
	int		*tab2;
	int		i;

	i = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * x)))
		print_err("Malloc error: make_int_tab");
	if (!(tab2 = (int *)malloc(sizeof(int) * y * x)))
		print_err("Malloc error: make_int_tab");
	while (i < x)
	{
		tab[i] = &tab2[i * y];
		i++;
	}
	tab = init(tab, x, y);
	return (tab);
}
