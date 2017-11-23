/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:47:08 by dsebban           #+#    #+#             */
/*   Updated: 2016/05/09 15:22:45 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		loop_read(char **st_line, char **line, int fd, int *ret)
{
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	ft_bzero(buf, BUFF_SIZE + 1);
	while ((*ret = read(fd, buf, BUFF_SIZE)))
	{
		tmp = *st_line;
		if (*st_line == NULL)
			*st_line = ft_strdup(buf);
		else
			*st_line = ft_strjoin(*st_line, buf);
		free(tmp);
		ft_bzero(buf, BUFF_SIZE + 1);
		if (ft_strchr(*st_line, '\n'))
			break ;
	}
	if (!*st_line)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (1);
}

static int		ft_read(int fd, char **line, char **st_line)
{
	int		ret;
	char	*tmp;

	if (!loop_read(st_line, line, fd, &ret))
		return (0);
	if ((tmp = ft_strchr(*st_line, '\n')) != NULL)
	{
		ret = tmp - *st_line;
		tmp = ft_strsub(*st_line, 0, ret);
		*line = ft_strdup(tmp);
		free(tmp);
		tmp = *st_line;
		*st_line = ft_strdup(*st_line + ret + 1);
		free(tmp);
		return (1);
	}
	if (**st_line)
	{
		*line = ft_strdup(*st_line);
		*st_line = NULL;
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	int				ret;
	static char		*st_line = NULL;

	if (read(fd, 0, 0) < 0 || fd == 1 || BUFF_SIZE <= 0)
		return (-1);
	ret = ft_read(fd, line, &st_line);
	return (ret);
}
