/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_slice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:03:09 by dsebban           #+#    #+#             */
/*   Updated: 2016/11/05 17:15:56 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdlib.h>

char	**array_slice(char **src, int start, int end)
{
	char **ret;

	ret = NULL;
	if (!src || !src[start] || !src[end])
		return (NULL);
	ret = tabdup(src + start, (end - start));
	return (ret);
}
