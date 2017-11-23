/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:31:12 by dsebban           #+#    #+#             */
/*   Updated: 2015/12/12 16:12:37 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *str, int chr)
{
	while (*str)
	{
		if (*str == chr)
			return ((char *)str);
		str++;
	}
	if (chr == 0 && *str == 0)
		return ((char *)str);
	else
		return (NULL);
}
