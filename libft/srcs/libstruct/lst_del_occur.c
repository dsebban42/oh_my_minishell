/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del_occur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 22:18:11 by dsebban           #+#    #+#             */
/*   Updated: 2016/07/25 22:18:17 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	lstdel_occur(t_list **root, char *occur)
{
	t_list *ite;
	t_list *prev;

	ite = *root;
	prev = NULL;
	while (ite)
	{
		if (!(ft_strcmp(ite->content, occur)))
		{
			if (ite == *root)
				*root = ite->next;
			else
				prev->next = ite->next;
			if (ite->content)
				free(ite->content);
			free(ite);
		}
		else
			prev = ite;
		ite = ite->next;
	}
}
