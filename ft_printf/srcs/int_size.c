/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 19:43:03 by dsebban           #+#    #+#             */
/*   Updated: 2016/08/08 20:48:59 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		int_size(int i)
{
	int ret;
	int digit;

	digit = 0;
	ret = 1;
	digit = i;
	if (digit == -2147483648)
		return (11);
	if (digit < 0)
	{
		digit *= -1;
		ret++;
	}
	if (digit == 0)
		return (1);
	while (digit > 9)
	{
		digit /= 10;
		ret++;
	}
	return (ret);
}
