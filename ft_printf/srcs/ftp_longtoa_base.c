/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_longtoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 18:08:59 by dsebban           #+#    #+#             */
/*   Updated: 2016/07/26 18:45:47 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_count_word(long value, int base)
{
	int i;

	i = 0;
	if (value < 0)
	{
		i++;
		value *= -1;
	}
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

static void		exception(long *value, int base, char *tab, short *sign)
{
	if (*value == 0)
		ft_strcpy(tab, "0");
	if (*value < 0 && base == 10)
	{
		*sign = 1;
		*value *= -1;
	}
}

void			ftp_longtoa_base(long value, int base, char **ct_str)
{
	int		whide;
	char	tab[19];
	short	sign;

	sign = 0;
	whide = ft_count_word(value, base);
	if (value == LONG_MIN)
	{
		*ct_str = ft_strcat(*ct_str, "-9223372036854775808");
		return ;
	}
	tab[whide] = '\0';
	exception(&value, base, tab, &sign);
	while (value > 0)
	{
		whide--;
		tab[whide] = (value % base) + 48;
		if (tab[whide] > 57)
			tab[whide] += 7;
		value /= base;
	}
	if (sign)
		tab[--whide] = '-';
	*ct_str = ft_strcat(*ct_str, tab);
}
