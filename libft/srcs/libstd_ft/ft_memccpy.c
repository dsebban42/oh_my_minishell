/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:08:15 by dsebban           #+#    #+#             */
/*   Updated: 2015/12/01 16:41:27 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned const char	*s;
	unsigned char		*d;

	s = src;
	d = dst;
	if (n)
	{
		while (n != 0)
		{
			if ((*d++ = *s++) == (unsigned char)c)
				return (d);
			--n;
		}
	}
	return (NULL);
}
