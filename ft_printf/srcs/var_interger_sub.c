/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_interger_sub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 13:49:16 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/26 13:49:28 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*var_integer_sub1(t_flag *flg, char *ct_str, void *i)
{
	flg->width--;
	return ((int)i < 0 ? ct_str : ft_strcat(ct_str, "+"));
}

char	*var_integer_sub2(t_flag *flg, char *ct_str)
{
	flg->width--;
	return (ft_strcat(ct_str, " "));
}
