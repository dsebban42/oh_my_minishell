/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 19:38:12 by dsebban           #+#    #+#             */
/*   Updated: 2016/05/31 19:17:42 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>
#include <stdlib.h>

static int	ft_length(char *hex)
{
	int length;

	length = 0;
	while (hex[length])
		length++;
	return (length);
}

int			ft_hex_to_int(char *hex)
{
	char		*hex_str;
	int			length;
	const int	base = 16;
	int			decimal;
	int			i;

	i = 0;
	decimal = 0;
	length = ft_length(hex);
	hex_str = hex;
	while (hex_str[i] && i < length)
	{
		if (hex_str[i] >= 48 && hex_str[i] <= 57)
			decimal += (((int)(hex_str[i])) - 48) * pow(base, length - i - 1);
		else if (hex_str[i] >= 65 && hex_str[i] <= 70)
			decimal += (((int)(hex_str[i])) - 55) * pow(base, length - i - 1);
		else if (hex_str[i] >= 97 && hex_str[i] <= 102)
			decimal += (((int)(hex_str[i])) - 87) * pow(base, length - i - 1);
		else
			return (0xFFFFFF);
		i++;
	}
	return (decimal);
}
