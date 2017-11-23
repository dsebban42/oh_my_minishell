/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didier <didier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 17:40:04 by didier            #+#    #+#             */
/*   Updated: 2016/11/27 12:09:56 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 500
#include "libft.h"
#include "my_errno.h"
#include "minishell.h"

static void	error_manager(int *valid_path, char *p1, int p2)
{
	*valid_path = -1;
	if (!p1 && !p2)
		ft_printferror("cd: %s\n", return_error(E2BIG));
	if (p1 && p2 == 1)
		ft_printferror("cd: %s: %s\n", p1, return_error(ENOENT));
	if (p1 && p2 == 2)
		ft_printferror("cd: %s: %s\n", p1, return_error(ENOTDIR));
	if (p1 && p2 == 3)
		ft_printferror("cd: %s: %s\n", p1, return_error(ENAMETOOLONG));
	if (p1 && p2 == 4)
		ft_printferror("cd: %s: %s\n", p1, return_error(EACCES));
}

void		action_decision(t_global *gb,
			char to_go[512], char *home, char *arg)
{
	char tmp[512];

	if (!arg)
		change_wd(gb->oldpwd, home);
	else if (!ft_strcmp(arg, "--"))
		change_wd(gb->oldpwd, home);
	else if (!ft_strcmp(arg, "~"))
		change_wd(gb->oldpwd, home);
	else if (!ft_strcmp(arg, "/"))
		change_wd(gb->oldpwd, "/");
	else if (!ft_strcmp(arg, "-"))
	{
		ft_strcpy(tmp, gb->oldpwd);
		change_wd(gb->oldpwd, tmp);
	}
	else if (arg[0] == '/')
		ft_strcpy(to_go, arg);
	else
		build_path(arg, to_go, "./");
}

void		path_validity_check(t_global *gb,
			int *valid_path, char to_go[512], char *arg)
{
	struct stat	sb;
	int			stat_status;

	if (!arg)
		return ;
	if ((stat_status = stat(to_go, &sb) == -1 && !is_special_char(arg)))
		error_manager(valid_path, arg, 1);
	else if (!is_special_char(arg) &&
	((sb.st_mode & S_IFMT) != S_IFDIR))
		error_manager(valid_path, arg, 2);
	else
		lstat(to_go, &sb);
	if (stat_status != -1)
		gb->mode = (sb.st_mode & S_IFMT);
	else
		gb->mode = -1;
	if (stat_status == 0 && !(sb.st_mode & S_IXUSR))
		error_manager(valid_path, to_go, 4);
}

int			chdir_manager(t_global *gb, char **args)
{
	char		*home;
	char		cwd[512];
	char		to_go[512];
	int			valid_path;

	valid_path = 0;
	home = NULL;
	initbuff(cwd, to_go);
	if (args[1] && ft_strlen(args[1]) > 511)
		error_manager(&valid_path, args[1], 3);
	if (count_array(args) > 3)
		error_manager(&valid_path, NULL, 0);
	if (valid_path != -1)
	{
		set_home(gb, &home);
		action_decision(gb, to_go, home, args[1]);
		path_validity_check(gb, &valid_path, to_go, args[1]);
		ft_memdel((void**)&home);
	}
	if (args[1] && valid_path != -1 && !is_special_char(args[1]))
		change_wd(gb->oldpwd, to_go);
	if (args[1] && valid_path != -1)
		reset_wd(gb, to_go, cwd);
	gb->status = valid_path;
	return (0);
}
