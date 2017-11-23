/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_itoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 18:44:01 by dsebban           #+#    #+#             */
/*   Updated: 2016/07/26 18:44:10 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_count_word(int value, int base)
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

static void		exception(long int *value, int base, char *tab, short *sign)
{
	if (*value == 0)
		ft_strcpy(tab, "0");
	if (*value < 0 && base == 10)
	{
		*sign = 1;
		*value *= -1;
	}
}

void			ftp_itoa_base(long int value, int base, char **ct_str)
{
	int		whide;
	char	tab[11];
	short	sign;

	sign = 0;
	whide = ft_count_word(value, base);
	if (value == -2147483648)
	{
		*ct_str = ft_strcat(*ct_str, "-2147483648");
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
