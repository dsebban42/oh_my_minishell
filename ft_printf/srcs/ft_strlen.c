/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:17:05 by dsebban           #+#    #+#             */
/*   Updated: 2016/02/19 15:25:57 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long unsigned int	ft_strlen(const char *str)
{
	unsigned long int	len;
	unsigned			x;

	len = 0;
	while (1)
	{
		x = *(unsigned*)str;
		if ((x & 0xFF) == 0)
			return (len);
		if ((x & 0xFF00) == 0)
			return (len + 1);
		if ((x & 0xFF0000) == 0)
			return (len + 2);
		if ((x & 0xFF000000) == 0)
			return (len + 3);
		str += 4;
		len += 4;
	}
}
