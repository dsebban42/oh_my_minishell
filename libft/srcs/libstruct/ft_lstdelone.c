/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:50:02 by didier            #+#    #+#             */
/*   Updated: 2016/10/13 20:54:56 by didier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **root, t_list *one)
{
	t_list *prev;

	prev = *root;
	while (prev->next != one)
		prev = prev->next;
	if (one == *root)
		*root = one->next;
	else
		prev->next = one->next;
	if (one->content)
		free(one->content);
	free(one);
}
