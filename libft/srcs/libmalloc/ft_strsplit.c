/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:24:48 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/29 11:46:13 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static inline int	get_len(const char *s, char c)
{
	int	i;
	int st;
	int j;

	i = 0;
	j = 0;
	st = 0;
	while (s[i])
	{
		if (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			st = i;
			while (s[i] && s[i] != c)
				i++;
			if (i - st != 0)
				j++;
		}
	}
	return (j);
}

char				**ft_strsplit(const char *s, char c)
{
	INIT(int, st, 0);
	INIT(char **, tab, NULL);
	INIT(int, line, 0);
	INIT(int, i, 0);
	if (!(tab = (char **)malloc(sizeof(char *) * (get_len(s, c) + 1))))
		print_err("Malloc error: ft_strsplit");
	if (s == NULL || *s == 0)
		return (tab);
	while (s[i])
	{
		(s[i] && s[i] == c) ? i++ : i;
		if (s[i] && s[i] != c)
		{
			st = i;
			while (s[i] && s[i] != c)
				i++;
			if ((i - st) != 0 && ((tab[line] = ft_strsub(s, st, i - st))
						&& tab[line] != NULL))
				line++;
			else
				return (NULL);
		}
	}
	tab[line] = NULL;
	return (tab);
}
