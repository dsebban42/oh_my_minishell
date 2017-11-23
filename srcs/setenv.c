/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:50:33 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/28 18:27:56 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "my_errno.h"

int		ft_setenv(t_global *gb, char **args)
{
	char	*ptr;
	int		nb_args;
	int		i;

	i = 0;
	if ((nb_args = checkvar_condition(args + 1)))
		while (args[++i] && i < nb_args)
		{
			ptr = ft_strchr(args[i], '=');
			env_manager(gb, args[i], ptr - args[i], 1);
		}
	else if (count_array(args) < 2)
		ft_lstiter(gb->lst_env_var, &print_env);
	else
		ft_printferror("%s\n", return_error(EINVAL));
	return (1);
}
