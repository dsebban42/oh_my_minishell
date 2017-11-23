/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_to_commandline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 13:30:27 by didier            #+#    #+#             */
/*   Updated: 2017/09/14 18:13:39 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

char	*set_st(char *ptr, char **arg, int i)
{
	return (((i = ptr - *arg) > 0) ? ft_strsub(*arg, 0, i) : NULL);
}

char	*set_end(t_environ *element, char *ptr, int i)
{
	return ((ptr + (i = ft_strlen(element->name) + 1)) ?
	ft_strdup(ptr + i) : NULL);
}

void	reset_tab(t_environ *element, char **arg, char *home, char *ptr)
{
	int		i;
	char	*st;
	char	*end;
	char	*tmp;

	tmp = NULL;
	i = 0;
	st = set_st(ptr, arg, i);
	end = set_end(element, ptr, i);
	if (st)
		tmp = ft_strjoin(st, !home ? element->value : home);
	else
		tmp = ft_strdup(element->value);
	if (end)
	{
		ptr = tmp ? ft_strjoin(tmp, end) : ft_strdup(end);
		ft_memdel((void*)&tmp);
		tmp = ptr;
	}
	ft_memdel((void**)arg);
	*arg = tmp;
	ft_memdel((void*)&home);
	ft_memdel((void*)&st);
	ft_memdel((void*)&end);
}

void	var_to_commandline(t_global *gb, char *ptr, char ***tab, int i)
{
	t_list	*one_var;
	char	**tmptab;
	char	*home;

	home = NULL;
	tmptab = *tab;
	if ((one_var = is_var_used(gb->lst_env_var, ptr + 1, 0, &fct_ptr_envar)))
	{
		if (ft_strnstr(ptr + 1, "HOME", 4))
			set_home(gb, &home);
		reset_tab((void*)((t_environ*)one_var->content), &tmptab[i], home, ptr);
	}
	else if ((one_var = is_var_used(gb->lst_lc_var, ptr + 1, 0,
			&fct_ptr_lcvar)))
		reset_tab((void*)((t_local_var*)one_var->content),
		&tmptab[i], home, ptr);
	else if (tmptab[i])
		tab_rm_element(&tmptab, i);
	*tab = tmptab;
}
