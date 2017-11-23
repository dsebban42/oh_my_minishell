/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:00:33 by dsebban           #+#    #+#             */
/*   Updated: 2016/11/11 18:36:40 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

static t_command	*list_push_back(t_command *new, t_command **root)
{
	t_command *tmp;

	tmp = *root;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

t_command			*new_command(t_command **root)
{
	t_command *new;

	if ((new = (t_command *)malloc(sizeof(t_command))) == NULL)
		print_err("Malloc Error: lst_create");
	ft_memset(new, 0, sizeof(t_command));
	new->next = NULL;
	if ((*root) == NULL)
		return ((*root) = new);
	return (new = list_push_back(new, root));
}
