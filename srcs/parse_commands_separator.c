/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands_separator.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:54:35 by dsebban           #+#    #+#             */
/*   Updated: 2016/11/27 11:50:53 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void		parse_command_separator(t_global *gb, char ***tab, int is_normal)
{
	int			i;
	char		*ptr;
	char		**tmparray;
	t_command	*curr;

	curr = NULL;
	tmparray = NULL;
	i = -1;
	curr = init_current_position(&gb->lst_cmd);
	if (!is_normal)
		curr = add_args_to_command(curr, *tab);
	else
	{
		while ((*tab)[++i])
		{
			if ((ptr = ft_strchr((*tab)[i], ';')))
				curr = separator_match(gb, curr, &tmparray);
			else
				tmparray = separator_no_match(tmparray, (*tab)[i]);
		}
		tmparray ? curr = cpy_args(curr, tmparray) : 0;
		free_tab((void***)&tmparray);
		free_tab((void***)tab);
	}
}
