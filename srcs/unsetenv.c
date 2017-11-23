/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 21:53:02 by didier            #+#    #+#             */
/*   Updated: 2016/11/27 11:18:11 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_unsetenv(t_global *gb, char **args)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (args[++i])
	{
		if (!ft_strcmp(args[i], "PATH"))
			free_tab((void***)&gb->g_path);
		if ((tmp = is_var_used(gb->lst_env_var, args[i], 1,
			&fct_ptr_envar)))
		{
			ft_memdel((void**)&((t_environ*)tmp->content)->name);
			ft_memdel((void**)&((t_environ*)tmp->content)->value);
			ft_lstdelone(&gb->lst_env_var, tmp);
		}
	}
	return (i);
}
