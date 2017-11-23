/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:32:30 by dsebban           #+#    #+#             */
/*   Updated: 2015/11/26 13:36:14 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *str, int chr)
{
	const char *ret;

	ret = NULL;
	while (*str)
	{
		if (*str == chr)
			ret = str;
		str++;
	}
	if (ret != NULL)
		return ((char *)ret);
	if (chr == 0)
		return ((char *)str);
	return (NULL);
}
