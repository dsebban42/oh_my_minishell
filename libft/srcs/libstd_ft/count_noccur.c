/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_noccur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 14:57:10 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/28 14:57:11 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				count_noccur(const char *str, const char occur, int n)
{
	int i;
	int oc;

	i = 0;
	oc = 0;
	if (!str)
		return (0);
	while (str[i] && n > 0)
	{
		if (str[i] == occur)
			oc++;
		i++;
		--n;
	}
	return (oc);
}
