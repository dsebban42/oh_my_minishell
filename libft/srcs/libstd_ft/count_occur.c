/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_occur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 14:57:05 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/28 14:57:06 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				count_occur(const char *str, const char occur)
{
	int i;
	int oc;

	i = 0;
	oc = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == occur)
			oc++;
		i++;
	}
	return (oc);
}
