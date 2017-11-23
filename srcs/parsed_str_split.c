/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsed_str_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 12:19:16 by didier            #+#    #+#             */
/*   Updated: 2016/11/27 11:50:34 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			is_home_special_str(char *combinaison)
{
	if (!ft_strcmp(combinaison, "~") || !ft_strcmp(combinaison, "--")
		|| !ft_strcmp(combinaison, "~/"))
		return (1);
	return (0);
}

static void	concatenate_home_arg(t_global *gb, char **arg, char **ptr)
{
	char *tmp;

	tmp = NULL;
	set_home(gb, &tmp);
	*arg = ft_strjoin(tmp, *ptr + 1);
	ft_memdel((void**)ptr);
	ft_memdel((void**)&tmp);
}

void		parsing_special_combinaison(t_global *gb, char **tab,
			int is_normal, int is_simplequote)
{
	int			i;
	char		*ptr;
	int			pos;

	i = -1;
	pos = 1;
	while (tab[++i])
	{
		if (!is_simplequote && (ptr = ft_strstr(tab[i], "$"))
			&& ft_isprint(ptr[1]))
		{
			pos = ptr - tab[i];
			if ((!pos) || (pos && ptr[-1] != '\\'))
				var_to_commandline(gb, ptr, &tab, i);
			if ((is_normal) && (tab[i]) && is_home_special_str(tab[i]))
				set_home(gb, &tab[i]);
		}
		else if (is_normal && tab[i] && (ptr = ft_strnstr(tab[i], "~/", 2)))
			concatenate_home_arg(gb, &tab[i], &ptr);
	}
	parse_command_separator(gb, &tab, is_normal);
}

void		split_parsed_str(t_global *gb, char *str, t_list *list)
{
	t_list		*curr;
	int			st;
	int			i;
	char		**tab;

	i = -1;
	st = 0;
	tab = NULL;
	curr = list;
	while (str[++i])
		if (curr && curr->next && i == (int)curr->size)
		{
			(i != st) ? parsing_special_combinaison(gb,
				without_delimiters_args(tab, str, st, i), 1, 0) : 0;
			parsing_special_combinaison(gb, with_delimiters_args(tab, str,
				curr->size, curr->next->size + 1 - curr->size), 0,
				str[curr->size] == '\'' ? 1 : 0);
			st = curr->next->size + 2;
			i = curr->next->size;
			curr = curr->next->next;
		}
	(i != st) ? parsing_special_combinaison(gb,
		without_delimiters_args(tab, str, st, i), 1, 0) : 0;
}
