/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtohex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 22:07:40 by dsebban           #+#    #+#             */
/*   Updated: 2016/07/25 22:07:51 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*dtohex(long unsigned int dec)
{
	int		j;
	char	*sum;
	char	*tmp;

	INIT(int, i, 0);
	sum = ft_memalloc(sizeof(dec));
	tmp = ft_memalloc(sizeof(dec));
	while (dec > 0)
	{
		if (((tmp[i] = (dec % 16) + 48)) > 57)
			tmp[i] += 39;
		dec /= 16;
		i++;
	}
	j = i;
	while (i-- > 0)
	{
		*sum = tmp[i];
		sum++;
	}
	free(tmp);
	*sum = 0;
	return (sum - j);
}
