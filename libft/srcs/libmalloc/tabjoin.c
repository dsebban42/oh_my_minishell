/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:13:41 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/29 11:48:34 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_element(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		++i;
	return (i);
}

char		**tabjoin(char **tab1, char **tab2)
{
	char	**ret_tab;
	int		tab_i;
	int		param_i;

	tab_i = 0;
	param_i = -1;
	if (tab1 == NULL || tab2 == NULL)
		return (NULL);
	if (!(ret_tab = (char **)malloc(sizeof(char *) *
		(count_element(tab1) + count_element(tab2) + 1))))
		print_err("Malloc error: tabdup");
	while (tab1[++param_i])
	{
		ret_tab[tab_i] = ft_strdup(tab1[param_i]);
		tab_i++;
	}
	param_i = -1;
	while (tab2[++param_i])
	{
		ret_tab[tab_i] = ft_strdup(tab2[param_i]);
		tab_i++;
	}
	ret_tab[tab_i] = NULL;
	return (ret_tab);
}
