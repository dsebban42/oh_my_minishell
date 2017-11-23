/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:03:40 by dsebban           #+#    #+#             */
/*   Updated: 2016/11/27 11:20:29 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <termcap.h>
#include <signal.h>
#include "libft.h"
#include "minishell.h"
#include "my_errno.h"

t_command	*input_parsing(t_global *gb, t_list **delimiters, char **str)
{
	char		*tmp;
	char		*tmp_line;

	tmp = NULL;
	tmp_line = NULL;
	while (lexical_parser(str, delimiters, -1))
	{
		ft_putstr("\n>	> ");
		get_next_line(0, &tmp_line);
		if (tmp_line)
		{
			tmp = *str;
			*str = ft_strjoin(*str, tmp_line);
			ft_memdel((void**)&tmp);
			ft_memdel((void**)&tmp_line);
			ft_lstdel(delimiters);
		}
	}
	tmp = ft_strtrim(*str);
	split_parsed_str(gb, tmp, *delimiters);
	ft_memdel((void**)&tmp);
	return (NULL);
}

void		inthandler(int sig)
{
	ft_printf("\n%s", PROMPT);
	signal(sig, SIG_IGN);
	signal(SIGINT, inthandler);
}

int			ft_exit(t_global *gb, char *line)
{
	char	**args;
	int		i;

	i = -1;
	args = ft_strsplit(line, ' ');
	if (count_array(args) > 2)
	{
		ft_printferror("minishell: %s\n", return_error(E2BIG));
		return (gb->status = -1);
	}
	while (args[1] && args[1][++i])
		if (!ft_isdigit(args[1][i]) && args[1][0] != '-')
		{
			ft_printferror("%s\n", "Numeric argument required");
			free_tab((void***)&args);
			return (gb->status = -1);
		}
	gb->status = args[1] ? ft_atoi(args[1]) : gb->status;
	free_tab((void***)&args);
	ft_memdel((void**)&line);
	return (0);
}

void		input_manager(t_global *gb)
{
	char		*line;
	t_list		*delimiters;
	t_command	*curr_cmd;

	ft_putstr(PROMPT);
	signal(SIGINT, inthandler);
	while (get_next_line(0, &line))
	{
		delimiters = NULL;
		if ((!ft_strcmp(line, "exit") ||
				ft_strnstr(line, "exit ", 5)) && !ft_exit(gb, line))
			return ;
		input_parsing(gb, &delimiters, &line);
		if ((curr_cmd = gb->lst_cmd))
			while (curr_cmd)
			{
				if (curr_cmd->args && curr_cmd->args[0])
					command_finder(gb, curr_cmd->args);
				curr_cmd = curr_cmd->next;
			}
		ft_putstr(PROMPT);
		ft_memdel((void**)&line);
		del_commands(&gb->lst_cmd);
		delimiters ? ft_lstdel(&delimiters) : 0;
	}
}
