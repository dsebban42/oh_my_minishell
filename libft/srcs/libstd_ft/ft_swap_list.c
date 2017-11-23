/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 21:51:23 by dsebban           #+#    #+#             */
/*   Updated: 2016/06/02 21:55:17 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*find_prev(t_list *root, t_list *curr)
{
	t_list *ite;

	ite = root;
	if (curr == root)
		return (ite);
	while (ite->next && ite->next != curr)
		ite = ite->next;
	return (ite);
}

t_list				*ft_swap_list(t_list *first, t_list *second,
					t_list *root, t_list *tmp)
{
	t_list *f_prev;
	t_list *s_prev;

	f_prev = find_prev(root, first);
	s_prev = find_prev(root, second);
	if (second->next)
		tmp = second->next;
	else
		return (root);
	if (first != root)
		f_prev->next = second;
	else
		root = second;
	if (first->next == second)
	{
		second->next = first;
		first->next = tmp;
	}
	else
	{
		second->next = first->next;
		first->next = tmp;
		s_prev->next = first;
	}
	return (root);
}
