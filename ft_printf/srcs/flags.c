/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flgas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 11:37:28 by dsebban           #+#    #+#             */
/*   Updated: 2016/08/13 19:50:59 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>
#include <stdarg.h>
#include <wchar.h>
#include <stdlib.h>

int				ft_flags(const char *s, int pos, t_flag *flg)
{
	int init_pos;

	init_pos = pos;
	while ((s[pos]) && (s[pos] == '-' || s[pos] == '+'
	|| s[pos] == ' ' || s[pos] == '#' || s[pos] == '0' || s[pos] == 39))
	{
		if (s[pos] == '-')
		{
			flg->decalage = 1;
			flg->fill = ' ';
		}
		flg->sign = s[pos] == '+' ? 1 : flg->sign;
		flg->fill = s[pos] == '0' && flg->decalage != 1 ? '0' : flg->fill;
		flg->space = s[pos] == ' ' ? 1 : flg->space;
		flg->sharp = s[pos] == '#' ? 1 : flg->sharp;
		pos++;
	}
	return (pos - init_pos);
}
