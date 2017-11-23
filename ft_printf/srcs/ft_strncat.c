/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:11:23 by dsebban           #+#    #+#             */
/*   Updated: 2016/07/27 17:59:29 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	int i;

	i = ft_strlen(dst);
	ft_strncpy(dst + i, src, n);
	return (dst);
}
