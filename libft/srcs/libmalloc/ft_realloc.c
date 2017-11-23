/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 12:31:05 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/29 11:44:58 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_realloc(char *ret_str, size_t len)
{
	char	*new_str;

	new_str = NULL;
	if (!ret_str)
		return (ret_str = ft_strnew(len));
	if (!(new_str = ft_strnew(len)))
		print_err("Malloc error: ft_realloc");
	new_str = ft_strcpy(new_str, ret_str);
	free(ret_str);
	return (new_str);
}
