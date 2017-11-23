/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 19:44:18 by dsebban           #+#    #+#             */
/*   Updated: 2016/08/08 20:01:15 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned long	hex_size(unsigned long hx)
{
	unsigned long i;

	i = 0;
	while (hx > 0)
	{
		hx /= 16;
		i++;
	}
	return (i);
}
