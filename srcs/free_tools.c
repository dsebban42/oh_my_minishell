/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 15:42:47 by didier            #+#    #+#             */
/*   Updated: 2016/11/27 11:20:08 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void		del_commands(t_command **root)
{
	t_command *current;
	t_command *next;

	current = *root;
	while (current != NULL)
	{
		next = current->next;
		if (current->args)
			free_tab((void***)&current->args);
		ft_memdel((void**)&current);
		current = next;
	}
	*root = NULL;
}

void		del_envar(t_list *lst)
{
	t_environ *envar;

	envar = (t_environ*)lst->content;
	ft_memdel((void**)&envar->name);
	ft_memdel((void**)&envar->value);
}

static void	del_lcvar(t_list *lst)
{
	t_local_var	*lc_var;

	lc_var = (t_local_var*)lst->content;
	ft_memdel((void**)&lc_var->name);
	ft_memdel((void**)&lc_var->value);
}

void		del_manager(t_global *gb)
{
	ft_lstiter(gb->lst_lc_var, &del_lcvar);
	ft_lstiter(gb->lst_env_var, &del_envar);
	ft_lstdel(&gb->lst_lc_var);
	ft_lstdel(&gb->lst_env_var);
	free_tab((void***)&gb->g_path);
}
