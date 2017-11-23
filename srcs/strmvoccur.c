/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmvoccur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 17:29:07 by didier            #+#    #+#             */
/*   Updated: 2016/10/27 17:51:57 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	strmvoccur(char **str, int oc, int dest)
{
	char tmp;

	if (!*str)
		return ;
	while (str[0][oc + 1] && oc != dest)
	{
		tmp = str[0][oc + 1];
		str[0][oc + 1] = str[0][oc];
		str[0][oc] = tmp;
		oc += oc < dest ? +1 : -1;
	}
}
