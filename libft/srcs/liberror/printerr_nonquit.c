/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerr_nonquit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 14:53:14 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/28 14:53:15 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	print_err(char *err_str)
{
	ft_putstr_fd(err_str, 2);
	ft_putchar_fd('\n', 2);
}
