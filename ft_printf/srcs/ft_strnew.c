/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:25:32 by dsebban           #+#    #+#             */
/*   Updated: 2016/07/26 18:43:29 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

char	*ft_strnew(size_t size)
{
	char *ret;

	if ((ret = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (0);
	ft_bzero(ret, size + 1);
	return (ret);
}
