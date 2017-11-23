/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:56:37 by dsebban           #+#    #+#             */
/*   Updated: 2015/11/30 14:03:28 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *buf, int c, size_t lng)
{
	while (lng > 0)
	{
		if (*(unsigned char*)buf == (unsigned char)c)
			return ((void *)buf);
		buf++;
		lng--;
	}
	return (NULL);
}
