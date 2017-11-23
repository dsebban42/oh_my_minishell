/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_var_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 15:42:19 by didier            #+#    #+#             */
/*   Updated: 2016/11/27 11:17:30 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int			fct_ptr_lcvar(t_list *iter, char *to_find, int absolute_match)
{
	t_local_var	*curr;

	curr = (t_local_var*)iter->content;
	if (absolute_match)
		if (!ft_strcmp(to_find, curr->name))
			return (1);
	if (ft_strnstr(to_find, curr->name, ft_strlen(curr->name)))
		return (1);
	return (0);
}

static void	new_local_var(t_global *gb, char *name, char *ptr)
{
	t_local_var	*curr;
	t_list		*list;
	int			i;

	i = 0;
	curr = ft_memalloc(sizeof(t_local_var));
	curr->name = name;
	while ((ptr[i]) && (ptr[i] != ' ' || ptr[i] != '	'))
		i++;
	curr->value = ft_strsub(ptr, 1, i);
	list = lst_create(&gb->lst_lc_var, 'f');
	ft_memset(&list->content, 0, sizeof(t_local_var));
	list->content = (t_local_var*)curr;
}

static void	modify_local_var(t_list *list, char *ptr)
{
	t_local_var	*curr;
	int			i;

	i = 0;
	curr = (t_local_var*)list->content;
	ft_memdel((void**)&curr->value);
	curr->value = NULL;
	while ((ptr[i]) && (ptr[i] != ' ' || ptr[i] != '	'))
		i++;
	curr->value = ft_strsub(ptr, 1, i);
}

void		local_var_manager(t_global *gb, char *str, int pos)
{
	t_list	*tmp;
	char	*name;
	int		end;

	tmp = NULL;
	end = pos;
	while (pos > 0 && (str[pos] != ' ' || str[pos] != '	'))
		pos--;
	name = ft_strsub(str, pos, (end - pos));
	if (!ft_strcmp(name, "$"))
	{
		ft_memdel((void**)&name);
		return ;
	}
	if ((tmp = is_var_used(gb->lst_lc_var, name, 1, &fct_ptr_lcvar)))
	{
		ft_memdel((void**)&name);
		modify_local_var(tmp, (str + end));
	}
	else
		new_local_var(gb, name, (str + end));
}
