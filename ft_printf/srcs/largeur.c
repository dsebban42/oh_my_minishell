/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largeur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 11:32:48 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/26 13:21:52 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>
#include <stdarg.h>
#include <wchar.h>
#include <stdlib.h>

void		largeur_champ(t_flag flg, char **ct_str, int size)
{
	if (size > flg.width)
		return ;
	ft_memset(*ct_str + ft_strlen(*ct_str), flg.fill, flg.width - size);
}
