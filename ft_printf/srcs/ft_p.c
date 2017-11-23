/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 12:20:59 by dsebban           #+#    #+#             */
/*   Updated: 2016/08/08 20:53:37 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static int	ft_size(unsigned long int d)
{
	int ret;

	ret = 0;
	while (d > 0)
	{
		d /= 16;
		ret++;
	}
	return (ret);
}

static char	*ft_zero_fill(t_flag flg, char *sum)
{
	int		len;
	char	*z_fill;
	char	*to_concat;

	len = (flg.width - ft_strlen(sum) + 2);
	z_fill = ft_strnew(len);
	ft_memset(z_fill, '0', len);
	to_concat = ft_strjoin(z_fill, sum);
	flg.width -= len;
	free(sum);
	free(z_fill);
	return (to_concat);
}

void		ft_p(t_flag flg, void *content, char *ct_str)
{
	unsigned long int	dec;
	int					dec_size;
	char				*sum;
	int					i;

	i = 0;
	dec_size = 0;
	dec = (unsigned long int)content;
	sum = ft_strnew(dec_size += (ft_size(dec) - 1));
	while (dec > 0)
	{
		if (((sum[dec_size] = (dec % 16) + 48)) > 57)
			sum[dec_size] += 39;
		dec /= 16;
		i++;
		dec_size--;
	}
	ft_strcat(ct_str, "0x");
	if (flg.fill == '0')
		sum = ft_zero_fill(flg, sum);
	else if (!content)
		ft_strcat(ct_str, "0");
	else
		ft_strcat(ct_str, sum);
	free(sum);
}
