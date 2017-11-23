/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_add_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 21:35:09 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/29 11:47:44 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**tab_add_element(char **tab, char *to_add)
{
	char	**ret_tab;
	int		i;

	i = 0;
	if (tab == NULL)
	{
		if (!(ret_tab = (char **)malloc(sizeof(char *) * (2))))
			print_err("Malloc error: tab_add_element");
		ret_tab[0] = ft_strdup(to_add);
		ret_tab[1] = NULL;
		return (ret_tab);
	}
	while (tab[i])
		i++;
	i++;
	if (!(ret_tab = (char **)malloc(sizeof(char *) * (i + 1))))
		print_err("Malloc error: tab_add_element");
	i = -1;
	while (tab[++i])
		ret_tab[i] = ft_strdup(tab[i]);
	ret_tab[i] = ft_strdup(to_add);
	ret_tab[++i] = NULL;
	return (ret_tab);
}
