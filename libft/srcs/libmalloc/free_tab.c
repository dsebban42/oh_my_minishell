/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 22:09:11 by dsebban           #+#    #+#             */
/*   Updated: 2016/09/30 21:03:19 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		free_tab(void ***tab)
{
	int i;

	i = 0;
	while (tab[0] && tab[0][i])
	{
		free(tab[0][i]);
		tab[0][i] = NULL;
		i++;
	}
	if (tab[0])
	{
		free(tab[0]);
	}
	tab[0] = NULL;
}
