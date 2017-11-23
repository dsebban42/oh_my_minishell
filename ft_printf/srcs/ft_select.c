/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:32:45 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/26 13:35:23 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	var_select(void *content, char **ct_str, int type, t_flag flg)
{
	size_t (*var_types[121])();

	var_types['d'] = &var_integer;
	var_types['i'] = &var_integer;
	var_types['s'] = &var_str;
	var_types['S'] = &var_wstr;
	var_types['C'] = &var_wc;
	var_types['u'] = &var_utoa;
	var_types['U'] = &var_ulongtoa;
	var_types['o'] = &var_octal;
	var_types['O'] = &var_octal_long;
	var_types['x'] = &var_lower_hexa;
	var_types['X'] = &var_upper_hexa;
	var_types['p'] = &var_adress;
	var_types['D'] = &var_longtoa;
	return (var_types[type](flg, content, ct_str));
}

size_t			ft_select(void *content, char type, char **ct_str, t_flag flg)
{
	type != 'd' && type != 'i' ? flg.sign = 0 : 0;
	if (type == 'c')
		return (var_c(flg, (char)content, ct_str));
	else if (type == '%')
	{
		ft_strcat((*ct_str), "%");
		return (1);
	}
	else
		return (var_select(content, ct_str, type, flg));
}
