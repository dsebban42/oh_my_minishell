/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:10:41 by dsebban           #+#    #+#             */
/*   Updated: 2016/07/28 14:11:54 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

int	ftp_putstr(char const *str)
{
	size_t ret;

	write(1, str, ret = ft_strlen(str));
	return (ret);
}
