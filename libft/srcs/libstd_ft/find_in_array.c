/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 14:39:37 by didier            #+#    #+#             */
/*   Updated: 2016/10/28 14:57:27 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_in_array(char **ar, char *to_find, int len)
{
	int i;

	i = -1;
	while (ar[++i])
	{
		if (len && ft_strnstr(ar[i], to_find, len))
			return (i);
		else if (!len && ft_strstr(ar[i], to_find))
			return (i);
	}
	return (-1);
}
