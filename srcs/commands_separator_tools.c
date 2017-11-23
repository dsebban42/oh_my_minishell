/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_separator_tools.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 10:17:11 by dsebban           #+#    #+#             */
/*   Updated: 2017/11/23 16:37:54 by didier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

t_command	*add_args_to_command(t_command *curr, char **tab)
{
	char **tmparray;

	tmparray = curr->args;
	curr->args = tab_add_element(curr->args, tab[0]);
	free_tab((void***)&tab);
	free_tab((void***)&tmparray);
	return (curr);
}

t_command	*init_current_position(t_command **root)
{
	t_command *curr;

	if (!*root)
		curr = new_command(root);
	else
	{
		curr = *root;
		while (curr->next)
			curr = curr->next;
	}
	return (curr);
}

t_command	*separator_match(t_global *gb, t_command *curr, char ***tmparray)
{
	char		**buffarray;

	buffarray = curr->args;
	if (tmparray)
	{
		curr->args = curr->args ?
		tabjoin(curr->args, *tmparray) : tabdup(*tmparray, -1);
		free_tab((void***)&buffarray);
		free_tab((void***)tmparray);
	}
	return (new_command(&gb->lst_cmd));
}

char		**separator_no_match(char **tmparray, char *str)
{
	char **buffarray;

	buffarray = tmparray;
	tmparray = tab_add_element(tmparray, str);
	free_tab((void***)&buffarray);
	return (tmparray);
}

t_command	*cpy_args(t_command *curr, char **tmparray)
{
	curr->args = curr->args ? tabjoin(curr->args, tmparray) :
	tabdup(tmparray, -1);
	return (curr);
}
