/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:13:41 by didier            #+#    #+#             */
/*   Updated: 2016/10/13 17:54:55 by didier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstcopy(t_list *origin, t_list **dup, int size_ct,
		void (*f)(t_list *, t_list *))
{
	t_list *iter;
	t_list *dup_curr;

	iter = origin;
	dup_curr = NULL;
	while (iter)
	{
		dup_curr = lst_create(dup, 'b');
		dup_curr->content = ft_memalloc(size_ct);
		f(dup_curr, iter);
		iter = iter->next;
	}
}
