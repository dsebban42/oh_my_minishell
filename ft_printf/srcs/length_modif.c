/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_modif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:44:49 by dsebban           #+#    #+#             */
/*   Updated: 2016/08/13 19:50:58 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		length_modif(const char *fmt, int pos, t_flag *flg)
{
	int lng_mod;

	lng_mod = 0;
	if (!fmt[pos])
		return (0);
	if (ft_strnstr(fmt + pos, "hh", 2))
		lng_mod = 1;
	else if (ft_strnstr(fmt + pos, "h", 1))
		lng_mod = 2;
	else if (ft_strnstr(fmt + pos, "ll", 2))
		lng_mod = 4;
	else if (ft_strnstr(fmt + pos, "l", 1))
		lng_mod = 3;
	else if (ft_strnstr(fmt + pos, "j", 1))
		lng_mod = 5;
	else if (ft_strnstr(fmt + pos, "z", 1))
		lng_mod = 6;
	lng_mod > flg->lng_mod ? flg->lng_mod = lng_mod : lng_mod;
	if (lng_mod == 1 || lng_mod == 4)
		return (2);
	if (lng_mod != 0)
		return (1);
	return (0);
}
