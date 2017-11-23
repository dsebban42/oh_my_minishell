/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:47:34 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/26 13:19:20 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char		*masque_utf(wchar_t c)
{
	static unsigned char	b_static[5];

	INIT(unsigned char, *b, b_static);
	if (c < (1 << 7))
		*b++ = (unsigned char)(c);
	else if (c < (1 << 11))
	{
		*b++ = (unsigned char)((c >> 6) | 0XC0);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 16))
	{
		*b++ = (unsigned char)(((c >> 12)) | 0xE0);
		*b++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 21))
	{
		*b++ = (unsigned char)(((c >> 18)) | 0xF0);
		*b++ = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		*b++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	*b = '\0';
	return ((const char *)b_static);
}

int				convert_utf(wchar_t c, char **ct_str)
{
	ft_strcat(*ct_str, masque_utf(c));
	return (ft_strlen(masque_utf(c)));
}
