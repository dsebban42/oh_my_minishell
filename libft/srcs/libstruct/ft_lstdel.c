/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 13:48:17 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/13 17:18:11 by didier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **root)
{
	t_list *current;
	t_list *next;

	current = *root;
	while (current != NULL)
	{
		next = current->next;
		if (current->content)
			free(current->content);
		current->content = NULL;
		free(current);
		current = next;
	}
	*root = NULL;
}
