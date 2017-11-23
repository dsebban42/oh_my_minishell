/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 15:04:14 by dsebban           #+#    #+#             */
/*   Updated: 2016/08/08 20:46:28 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

size_t		var_lower_hexa(t_flag flg, void *content, char **ct_str)
{
	void *p;

	p = *ct_str;
	if (flg.width && !flg.decalage)
		largeur_champ(flg, ct_str, hex_size((unsigned long)content));
	if (flg.sharp && content != NULL)
		*ct_str = ft_strcat(*ct_str, "0x");
	ft_dec_to_hex(content, flg.lng_mod, ct_str);
	if (flg.width && flg.decalage)
		largeur_champ(flg, ct_str, hex_size((unsigned long)content));
	return (p - (void*)*ct_str);
}

size_t		var_upper_hexa(t_flag flg, void *content, char **ct_str)
{
	void *p;

	p = *ct_str;
	if (flg.width && !flg.decalage)
		largeur_champ(flg, ct_str, hex_size((unsigned long)content));
	if (flg.sharp && content != NULL)
		*ct_str = ft_strcat(*ct_str, "0X");
	ft_dec_to_hex_upper(content, flg.lng_mod, ct_str);
	if (flg.width && flg.decalage)
		largeur_champ(flg, ct_str, hex_size((unsigned long)content));
	return (p - (void*)*ct_str);
}

size_t		var_adress(t_flag flg, void *i, char **ct_str)
{
	size_t	ret;
	char	tmp[20];

	ft_memset(tmp, 0, 20);
	ft_p(flg, i, tmp);
	ret = ft_strlen(tmp);
	if (flg.width && !flg.decalage && flg.fill != '0')
		largeur_champ(flg, ct_str, ret);
	*ct_str = ft_strncat(*ct_str, tmp, ret);
	if ((flg.width && flg.decalage) || (flg.width && flg.fill == '0'))
		largeur_champ(flg, ct_str, ret);
	return (ret);
}

size_t		var_longtoa(t_flag flg, long l, char **ct_str)
{
	void *p;

	(void)flg;
	p = *ct_str;
	ftp_longtoa_base(l, 10, ct_str);
	return (p - (void*)*ct_str);
}
