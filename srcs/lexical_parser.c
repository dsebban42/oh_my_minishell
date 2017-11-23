/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 12:18:37 by didier            #+#    #+#             */
/*   Updated: 2016/11/27 11:10:27 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

char	new_index_retlastparam(t_list **list, int i, char ret)
{
	t_list	*curr;

	curr = NULL;
	curr = lst_create(list, 'b');
	curr->content = NULL;
	curr->size = i;
	return (ret);
}

int		variablewithquote(char *str, int i)
{
	str_deloccur(&str, i);
	while (str && !ft_strchr("	 ", str[i]))
		i++;
	str_deloccur(&str, i - 1);
	return (i);
}

int		is_first_quote_and_var(char first_occur, char *str, int i)
{
	if (!first_occur && i >= 2 && ft_strchr("\'\"", str[i]) &&
		str[i - 1] == '=' && !ft_strchr(" 	", str[i - 2]))
		return (1);
	return (0);
}

int		ajust_line(char *str, int i)
{
	int oc;

	oc = i;
	while (str[i] && str[i] != ' ' && str[i] != '	')
		i++;
	i = str[i] == ' ' || str[i] == '	' ? i - 1 : i;
	strmvoccur(&str, oc, i);
	return (i - 1);
}

int		lexical_parser(char **s, t_list **list, int i)
{
	char	first_occur;

	first_occur = 0;
	*s = match_and_treat_exceptions(*s);
	while ((*s)[++i])
	{
		if (is_first_quote_and_var(first_occur, *s, i))
			variablewithquote(*s, i);
		if (is_quote(first_occur, *s, i))
		{
			if (!first_occur)
				first_occur = new_index_retlastparam(list, i, (*s)[i]);
			else if (first_occur == (*s)[i])
			{
				if ((*s)[i + 1] && (*s)[i + 1] != ' ' && (*s)[i + 1] != '	')
					i = ajust_line(*s, i);
				first_occur = new_index_retlastparam(list, i - 1, 0);
			}
		}
		else if (i >= 1 && ft_strchr("\'\"\\", (*s)[i]) && (*s)[i - 1] == '\\')
			str_deloccur(s, i - 1);
	}
	return (first_occur ? 1 : 0);
}
