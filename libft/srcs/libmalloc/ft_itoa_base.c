/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 22:04:57 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/29 11:43:00 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		it_get_len(int n, int base)
{
	int		len;

	len = 0;
	while (n /= base)
		++len;
	return (len);
}

static	int		it_isneg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char			*ft_itoa_base(int n, int base)
{
	int		len;
	int		sign;
	char	*nbr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = it_get_len(n, base);
	sign = it_isneg(n);
	if (!(nbr = ft_strnew(len + sign + 1)))
		print_err("Malloc error: ft_itoa_base");
	if (sign)
		n = -n;
	nbr = nbr + sign + len;
	if (!n)
		*--nbr = '0';
	while (n)
	{
		*--nbr = n % base + '0';
		n /= base;
	}
	if (sign)
		*--nbr = '-';
	return (nbr);
}
