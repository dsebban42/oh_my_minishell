/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_utf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:34:55 by dsebban           #+#    #+#             */
/*   Updated: 2016/02/02 20:05:48 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_utf(wchar_t c)
{
	static unsigned char b_static[5];

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
	ft_putstr((const char *)b_static);
}
