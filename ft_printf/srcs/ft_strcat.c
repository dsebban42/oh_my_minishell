/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:11:06 by dsebban           #+#    #+#             */
/*   Updated: 2016/07/26 18:43:15 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t i;

	i = ft_strlen(dst);
	ft_strcpy(dst + i, src);
	return (dst);
}
