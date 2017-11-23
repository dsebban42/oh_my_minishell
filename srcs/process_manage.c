/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_manage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:03:09 by dsebban           #+#    #+#             */
/*   Updated: 2016/11/27 11:21:21 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 500
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include "my_errno.h"
#include "libft.h"
#include "minishell.h"

int		valid_execheck(char *path)
{
	struct stat	sb;

	if (stat(path, &sb) == -1)
		ft_printferror("minishell: %s %s\n", return_error(ENOENT), path);
	else if ((sb.st_mode & S_IFMT) == S_IFDIR)
		ft_printferror("minishell: %s %s\n", path, return_error(EISDIR));
	else if ((sb.st_mode & S_IFMT) != S_IFREG)
		ft_printferror("minishell: %s: Is not a file\n", path);
	else if (access(path, X_OK) == -1)
		ft_printferror("minishell: %s %s\n", path, return_error(EACCES));
	else
		return (0);
	return (-1);
}

int		launch_localprocess(t_global *gb, char **args, char *exec_name)
{
	char	*path;
	char	*tmp;
	int		process_ret;

	tmp = args[0];
	if (valid_execheck(args[0]) == -1)
		return (-1);
	else
	{
		path = ft_strdup(args[0]);
		args[0] = exec_name;
		process_ret = process_manage(path, environ_lsttotab(gb), args);
		args[0] = tmp;
		return (process_ret);
	}
	ft_printferror("minishell: %s: %s\n", return_error(ENOENT), args[0]);
	return (-1);
}

int		fork_child(char *path, char **envtab, char **args)
{
	pid_t	child;

	child = fork();
	if (child >= 0)
	{
		if (child == 0)
		{
			if (execve(path, args, envtab) == -1)
				return (-1);
		}
		else
			return (child);
	}
	return (child);
}

int		process_manage(char *path, char **envtab, char **args)
{
	int				child_state;
	int				child_return;

	if (valid_execheck(path) == -1)
		return (-1);
	child_return = fork_child(path, envtab, args);
	wait(&child_state);
	if (child_return == -1)
	{
		ft_printferror("minishell: %s: %s\n", args[0], return_error(ENOEXEC));
		exit(-1);
	}
	if (child_state == 4)
		ft_printferror("minishell: Illegal Instruction: %s\n", args[0]);
	else if (child_state == 6)
		ft_printferror("minishell: Abort trap: %s\n", args[0]);
	else if (child_state == 8)
		ft_printferror("minishell: Floating point exception: %s\n", args[0]);
	else if (child_state == 10 || child_state == 7)
		ft_printferror("minishell: Bus error: %s\n", args[0]);
	else if (child_state == 11)
		ft_printferror("minishell: segmentation fault: %s\n", args[0]);
	free_tab((void***)&envtab);
	ft_memdel((void**)&path);
	return (child_state);
}
