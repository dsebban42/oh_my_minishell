/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:57:00 by dsebban           #+#    #+#             */
/*   Updated: 2016/07/28 15:26:39 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ret;

	i = -1;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if ((ret = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	while (s1[++i])
		ret[i] = s1[i];
	j = 0;
	while (s2[j])
	{
		ret[i] = s2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}
