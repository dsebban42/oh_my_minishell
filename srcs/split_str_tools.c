/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_str_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 13:25:00 by didier            #+#    #+#             */
/*   Updated: 2016/11/27 11:17:58 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_trailing_sp(char **str)
{
	char *tmp;

	while ((tmp = ft_strstr(*str, "  ")))
		str_deloccur(str, (tmp - *str));
}

static void	tab_to_sp(char **str)
{
	char *tmp;

	while ((tmp = ft_strchr(*str, '\t')))
		ft_memset(tmp, ' ', 1);
}

char		**without_delimiters_args(char **tab, char *str, int st, int i)
{
	char *tmp;
	char **rettab;
	char **tmptab;

	tmp = ft_strsub(str, st, (i - st));
	tab_to_sp(&tmp);
	remove_trailing_sp(&tmp);
	rettab = ft_strsplit(tmp, ' ');
	ft_memdel((void**)&tmp);
	if (!tab)
		tab = tabdup(rettab, -1);
	else
	{
		tmptab = tabjoin(tab, rettab);
		free_tab((void***)&tab);
		tab = tmptab;
	}
	free_tab((void***)&rettab);
	return (tab);
}

char		**with_delimiters_args(char **tab, char *str, int st, int len)
{
	char *tmp;
	char **tmp_tab;

	tmp = ft_strsub(str, st + 1, len - 1);
	tmp_tab = tab;
	tab = tab_add_element(tab, tmp);
	ft_memdel((void**)&tmp);
	free_tab((void***)&tmp_tab);
	return (tab);
}
