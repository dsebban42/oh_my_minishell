/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 12:04:22 by dsebban           #+#    #+#             */
/*   Updated: 2016/08/08 20:45:20 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t		var_wc(t_flag flg, wchar_t c, char **ct_str)
{
	size_t ret;

	(void)flg;
	ret = convert_utf(c, ct_str);
	if (c == 0)
		return (1);
	return (ret);
}

size_t		var_utoa(t_flag flg, void *i, char **ct_str)
{
	void *p;

	p = *ct_str;
	if (flg.width && !flg.decalage)
		largeur_champ(flg, ct_str, unsigned_size((unsigned)i));
	if (flg.lng_mod >= 3 && flg.lng_mod <= 6)
		ftp_ulongtoa_base((unsigned long int)i, 10, ct_str);
	else if (flg.lng_mod == 1)
		ftp_ulongtoa_base((unsigned char)i, 10, ct_str);
	else
		ftp_ulongtoa_base((unsigned int)i, 10, ct_str);
	if (flg.width && flg.decalage)
		largeur_champ(flg, ct_str, unsigned_size((unsigned)i));
	return (p - (void *)*ct_str);
}

size_t		var_ulongtoa(t_flag flg, unsigned long int j, char **ct_str)
{
	void *p;

	(void)flg;
	p = *ct_str;
	ftp_ulongtoa_base(j, 10, ct_str);
	return (p - (void *)*ct_str);
}

size_t		var_octal(t_flag flg, unsigned long o, char **ct_str)
{
	void *p;

	p = *ct_str;
	if (flg.sharp && o != 0)
		*ct_str = ft_strcat(*ct_str, "0");
	if (flg.lng_mod >= 3 && flg.lng_mod <= 6)
		ftp_ulongtoa_base((unsigned long int)o, 8, ct_str);
	else if (flg.lng_mod == 1)
		ftp_ulongtoa_base((unsigned char)o, 8, ct_str);
	else if (flg.lng_mod == 2)
		ftp_ulongtoa_base((unsigned short)o, 8, ct_str);
	else
		ftp_ulongtoa_base((unsigned)o, 8, ct_str);
	return (p - (void *)*ct_str);
}

size_t		var_octal_long(t_flag flg, unsigned long o, char **ct_str)
{
	void *p;

	p = *ct_str;
	if (flg.sharp && o != 0)
		*ct_str = ft_strcat(*ct_str, "0");
	ftp_ulongtoa_base((unsigned long)o, 8, ct_str);
	return (p - (void *)*ct_str);
}
