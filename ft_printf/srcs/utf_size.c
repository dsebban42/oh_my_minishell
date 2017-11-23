/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 19:09:30 by dsebban           #+#    #+#             */
/*   Updated: 2016/08/08 19:09:41 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			utf_size(wchar_t *content, int o)
{
	wchar_t *c;
	int		lng;
	int		i;

	i = 0;
	lng = 0;
	c = content;
	while (c[i])
	{
		if (c[i] < (1 << 7))
			lng += 1;
		else if (c[i] < (1 << 11))
			lng += 2;
		else if (c[i] < (1 << 16))
			lng += 3;
		else if (c[i] < (1 << 21))
			lng += 4;
		i++;
		if (o == 1)
			return (lng);
	}
	return (lng);
}
