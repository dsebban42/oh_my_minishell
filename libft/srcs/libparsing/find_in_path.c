/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:58:39 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/29 16:53:14 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <dirent.h>
#include <stdlib.h>

char	*find_in_path(char **tab, char *to_find)
{
	DIR				*dir;
	struct dirent	*dp;
	int				i;
	char			*tmp;
	char			*ret;

	i = -1;
	if (!to_find || !tab)
		return (NULL);
	while (tab[++i])
		if ((dir = opendir(tab[i])))
		{
			while ((dp = readdir(dir)))
				if (ft_strcmp(dp->d_name, ".") && ft_strcmp(dp->d_name, "..") &&
					!ft_strcmp(dp->d_name, to_find))
				{
					tmp = ft_strjoin(tab[i], "/");
					ret = ft_strjoin(tmp, dp->d_name);
					free(tmp);
					closedir(dir);
					return (ret);
				}
			closedir(dir);
		}
	return (NULL);
}
