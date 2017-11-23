/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 18:26:56 by dsebban           #+#    #+#             */
/*   Updated: 2016/07/20 18:32:04 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	hash(unsigned char *str)
{
	unsigned long	hash;
	int				c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	hash *= 33 + c;
	return (hash);
}
