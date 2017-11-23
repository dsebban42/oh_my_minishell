/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:33:00 by dsebban           #+#    #+#             */
/*   Updated: 2015/12/10 16:18:06 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	int i;

	i = 0;
	if (tofind[i] == 0)
		return ((char *)str);
	while (*str && len > 0)
	{
		if (tofind[i] == *str)
			i++;
		else if (tofind[i] != *str)
		{
			str -= i;
			len += i;
			i = 0;
		}
		if (tofind[i] == '\0')
		{
			str -= i - 1;
			return ((char *)str);
		}
		str++;
		len--;
	}
	return (NULL);
}
