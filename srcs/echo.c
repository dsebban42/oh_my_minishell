/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 21:25:04 by didier            #+#    #+#             */
/*   Updated: 2016/10/27 17:35:04 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static int	parse_echoopt(t_opt *opt, char *tmpstr)
{
	int	i;

	i = 1;
	if (tmpstr[0] == '-')
	{
		while ((tmpstr[i]) && (ft_strchr("neE", tmpstr[i])))
		{
			tmpstr[i] == 'n' ? opt->echo_opt |= 0x2 : 0;
			tmpstr[i] == 'e' ? opt->echo_opt |= 0x4 : 0;
			tmpstr[i] == 'E' ? opt->echo_opt |= 0x8 : 0;
			i++;
		}
		return (tmpstr[i] ? 1 : 0);
	}
	return (1);
}

void		read_str(char *str)
{
	char *ptr;

	if ((ptr = ft_strstr(str, "\\$")))
		str_deloccur(&str, ptr - str - 1);
	ft_printf("%s ", str);
}

int			ft_echo(t_global *gb, char **args)
{
	t_opt	opt;
	int		i;
	int		ret_opt;

	(void)gb;
	i = 1;
	opt.echo_opt = 0;
	ret_opt = 0;
	while (args[i] && !(ret_opt = parse_echoopt(&opt, args[i])))
		i++;
	if (ret_opt == -1)
		i--;
	if (args[i])
	{
		while (args[i])
		{
			read_str(args[i]);
			++i;
		}
	}
	if (!(opt.echo_opt & 0x2))
		ft_printf("\n");
	return (1);
}
