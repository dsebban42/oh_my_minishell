/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 16:13:43 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/26 13:49:56 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	var_integer(t_flag flg, void *i, char **ct_str)
{
	void *p;

	p = *ct_str;
	flg.sign && (int)i < 0 && flg.fill != '0' ? flg.width++ : 0;
	if (flg.sign)
		*ct_str = var_integer_sub1(&flg, *ct_str, i);
	else if (flg.space && (int)i > 0)
		*ct_str = var_integer_sub2(&flg, *ct_str);
	if (flg.width && !flg.decalage)
		largeur_champ(flg, ct_str, i != NULL ? int_size((int)i) : 1);
	if (flg.lng_mod >= 3 && flg.lng_mod <= 6)
	{
		ftp_longtoa_base((long)i, 10, ct_str);
		return (p - (void *)*ct_str);
	}
	if (flg.lng_mod == 1)
		ftp_itoa_base((char)i, 10, ct_str);
	else if (flg.lng_mod == 2)
		ftp_itoa_base((short)i, 10, ct_str);
	else
		ftp_itoa_base((int)i, 10, ct_str);
	if (flg.width && flg.decalage)
		largeur_champ(flg, ct_str, i != NULL ? int_size((int)i) : 1);
	return (p - (void *)*ct_str);
}

size_t	var_c(t_flag flg, char c, char **ct_str)
{
	if (flg.width && !flg.decalage)
		largeur_champ(flg, ct_str, 1);
	if (flg.lng_mod == 3)
		return (0);
	ft_strcat(*ct_str, &c);
	if (flg.width && flg.decalage)
		largeur_champ(flg, ct_str, 1);
	return (1 + flg.width);
}

void	strwidth_first_set(t_flag *flg, char **ct_str, int len)
{
	if (flg->width > flg->precision && (int)len - flg->precision > 0
			&& flg->precision > 0)
		flg->width += (len - flg->precision);
	if (flg->width && !flg->decalage)
		largeur_champ(*flg, ct_str, len);
}

size_t	var_str(t_flag flg, void *str, char **ct_str)
{
	size_t len;

	len = 0;
	if (str)
		len = flg.precision == -1 ? 0 : ft_strlen(str);
	strwidth_first_set(&flg, ct_str, len);
	if (flg.lng_mod == 3)
		return (var_wstr(flg, str, ct_str));
	if (null_str_verif(str, ct_str, 's'))
		return (6);
	if (flg.precision)
		ft_strncat((*ct_str), (char *)str,
				flg.precision = flg.precision == -1 ? 0 : flg.precision);
	else
		ft_strcat((*ct_str), (char *)str);
	if (flg.width && flg.decalage)
		largeur_champ(flg, ct_str, str != NULL ? len : 0);
	return (len);
}

size_t	var_wstr(t_flag flg, wchar_t *wstr, char **ct_str)
{
	size_t	ret;
	wchar_t	*wtmp;
	int		len;

	len = 0;
	if (wstr)
		len = flg.precision == -1 ? 0 : utf_size(wstr, 0);
	wtmp = wstr;
	strwidth_first_set(&flg, ct_str, len);
	if ((ret = null_str_verif(wstr, ct_str, 'S')))
		return (ret);
	ret = 0;
	while (*wtmp && flg.precision != -1 &&
		(!flg.precision || ((int)ret + 1) < flg.precision))
	{
		ret += convert_utf(*wtmp, ct_str);
		wtmp++;
	}
	if (flg.width && flg.decalage)
		largeur_champ(flg, ct_str, len);
	return (ret);
}
