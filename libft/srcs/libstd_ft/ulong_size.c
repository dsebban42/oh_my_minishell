/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulong_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 16:13:11 by dsebban           #+#    #+#             */
/*   Updated: 2016/07/20 16:16:41 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ulong_size(size_t content)
{
	int		ret;
	size_t	digit;

	ret = 1;
	digit = content;
	if (digit == 0)
		return (1);
	while (digit > 9)
	{
		digit /= 10;
		ret++;
	}
	return (ret);
}
