/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:13:11 by dsebban           #+#    #+#             */
/*   Updated: 2015/11/27 19:33:07 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *str, const char *tofind)
{
	int i;

	i = 0;
	if (tofind[i] == 0)
		return ((char *)str);
	while (*str)
	{
		if (tofind[i] == *str)
			i++;
		else if (tofind[i] != *str)
		{
			str -= i;
			i = 0;
		}
		if (tofind[i] == '\0')
		{
			str -= i - 1;
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}
