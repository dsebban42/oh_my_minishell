/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_long_itoa.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:48:12 by dsebban           #+#    #+#             */
/*   Updated: 2016/03/15 12:10:34 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "limits.h"

static int		ft_count_word(size_t value, int base)
{
	int i;

	i = 0;
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

static void		exception(size_t *value, char *tab)
{
	if (*value == 0)
		ft_strcpy(tab, "0");
}

void			ftp_ulongtoa_base(size_t value, int base, char **ct_str)
{
	int		whide;
	char	tab[21];

	whide = ft_count_word(value, base);
	tab[whide] = '\0';
	exception(&value, tab);
	while (value > 0)
	{
		whide--;
		tab[whide] = (value % base) + 48;
		if (tab[whide] > 57)
			tab[whide] += 7;
		value /= base;
	}
	*ct_str = ft_strcat(*ct_str, tab);
}
