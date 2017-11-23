/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:42:48 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/29 11:44:23 by dsebban          ###   ########.fr       */
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

static	int		it_isneg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char			*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*nbr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = it_get_len(n);
	sign = it_isneg(n);
	if (!(nbr = ft_strnew(len + sign + 1)))
		print_err("Malloc error: ft_itoa");
	if (sign)
		n = -n;
	nbr = nbr + sign + len;
	if (!n)
		*--nbr = '0';
	while (n)
	{
		*--nbr = n % 10 + '0';
		n /= 10;
	}
	if (sign)
		*--nbr = '-';
	return (nbr);
}
