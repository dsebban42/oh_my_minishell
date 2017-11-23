/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:11:20 by dsebban           #+#    #+#             */
/*   Updated: 2016/09/16 13:14:47 by didier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lst_find_occurence(t_list **root, char *str)
{
	t_list	*current;

	current = *root;
	while (current && current->content && str)
	{
		if (!ft_strcmp(current->content, str))
			return (current);
		current = current->next;
	}
	return (NULL);
}
