/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_rm_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 14:38:52 by didier            #+#    #+#             */
/*   Updated: 2016/10/28 14:52:23 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	tab_rm_element(char ***tab, int elem)
{
	char **tmptab;

	tmptab = *tab;
	if (count_array(tmptab) > elem)
	{
		while (tmptab[elem])
		{
			free(tmptab[elem]);
			tmptab[elem] = tmptab[elem + 1];
			elem++;
		}
	}
	*tab = tmptab;
}
