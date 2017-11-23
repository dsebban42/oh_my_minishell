/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 22:05:42 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/29 11:46:47 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		it_get_len(int n)
{
	int		len;

	len = 0;
	while (n /= 10)
		++len;
	return (len);
}

char			*ft_unsigned_itoa(unsigned int n)
{
	int		len;
	char	*nbr;

	len = it_get_len(n);
	nbr = ft_strnew(len + 1);
	if (!nbr)
		print_err("Malloc error: ft_unsigned_itoa");
	nbr = nbr + len;
	if (!n)
		*--nbr = '0';
	while (n)
	{
		*--nbr = n % 10 + '0';
		n /= 10;
	}
	return (nbr);
}
