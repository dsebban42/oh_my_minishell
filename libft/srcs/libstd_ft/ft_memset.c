/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:04:25 by dsebban           #+#    #+#             */
/*   Updated: 2015/11/24 15:08:04 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *ptr, int val, size_t num)
{
	unsigned char *ret;

	ret = (unsigned char*)ptr;
	while (num > 0)
	{
		*ret = (unsigned char)val;
		ret++;
		num--;
	}
	return (ptr);
}
