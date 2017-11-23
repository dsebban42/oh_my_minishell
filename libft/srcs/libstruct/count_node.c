/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 14:51:55 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/28 14:51:56 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_node(t_list *list)
{
	int		node;
	t_list	*tmp;

	node = 0;
	tmp = list;
	while (tmp)
	{
		node++;
		tmp = tmp->next;
	}
	return (node);
}
