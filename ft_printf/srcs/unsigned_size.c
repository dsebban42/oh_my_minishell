/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 19:53:43 by dsebban           #+#    #+#             */
/*   Updated: 2016/08/08 20:47:14 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned		unsigned_size(unsigned u)
{
	unsigned ret;
	unsigned digit;

	digit = 0;
	ret = 1;
	digit = u;
	if (digit == 0)
		return (1);
	while (digit > 9)
	{
		digit /= 10;
		ret++;
	}
	return (ret);
}
