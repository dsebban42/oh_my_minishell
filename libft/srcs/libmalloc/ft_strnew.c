/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:25:32 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/29 11:45:50 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ret;

	if ((ret = (char *)malloc(size + 1)) == NULL)
		print_err("Malloc error: ft_strnew");
	ft_bzero(ret, size + 1);
	return (ret);
}
