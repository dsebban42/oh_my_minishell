/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_zise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:32:54 by dsebban           #+#    #+#             */
/*   Updated: 2016/06/13 21:19:44 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		int_size(int content)
{
	int ret;
	int digit;

	ret = 1;
	digit = content;
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
