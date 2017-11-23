/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printferror.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 14:18:22 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/26 14:18:41 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_printferror(const char *fmt, ...)
{
	va_list		ap;
	char		*ct_str;
	size_t		len;

	len = 0;
	ct_str = NULL;
	if (!*fmt)
		return (0);
	va_start(ap, fmt);
	len = va_foreach(ap, fmt, &ct_str, len);
	va_end(ap);
	write(2, ct_str, len);
	free(ct_str);
	return (len);
}
