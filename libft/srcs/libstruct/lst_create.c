/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:58:33 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/29 11:49:14 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_list	*list_push_back(t_list *new, t_list **root)
{
	t_list *tmp;

	tmp = *root;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

static t_list	*list_push_front(t_list *new, t_list **root)
{
	new->next = *root;
	*root = new;
	return (new);
}

t_list			*lst_create(t_list **root, char c)
{
	t_list *new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		print_err("Malloc Error: lst_create");
	new->next = NULL;
	if ((*root) == NULL)
		return ((*root) = new);
	if (c == 'b')
		new = list_push_back(new, root);
	if (c == 'f')
		new = list_push_front(new, root);
	return (new);
}
