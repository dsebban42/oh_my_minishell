/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <dsebban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 11:51:32 by dsebban           #+#    #+#             */
/*   Updated: 2016/10/26 13:48:17 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		if_precision(const char *fmt, int i, t_flag *flg)
{
	if (fmt[i] == '.')
	{
		flg->precision = -1;
		i++;
		if (ft_isdigit(fmt[i]))
			flg->precision++;
		while (ft_isdigit(fmt[i]))
		{
			flg->precision = (flg->precision * 10) + (fmt[i] - 48);
			i++;
		}
	}
	return (i);
}

int				get_conv_engine(t_flag *flg, const char **fmt, int i)
{
	int		lg;
	int		j;

	lg = 0;
	while (i)
	{
		j += i = 0;
		i += j = ft_flags(*fmt, 0, flg);
		*fmt += j;
		while (*fmt && ft_isdigit(**fmt))
		{
			!lg ? flg->width = (flg->width * 10) + ((**fmt) - 48) : 0;
			i++;
			(*fmt)++;
		}
		flg->width ? lg++ : lg;
		i += j = if_precision(*fmt, 0, flg);
		*fmt += j;
		i += j = length_modif(*fmt, 0, flg);
		*fmt += j;
	}
	return (i);
}

void			get_conv(const char **fmt, char **ct_str, va_list ap)
{
	char	*tmp;
	t_flag	flg;

	flg = (t_flag){0, 0, 0, ' ', 0, 0, 0, 0};
	tmp = NULL;
	(*fmt)++;
	get_conv_engine(&flg, fmt, -1);
	if (verif_conv(**fmt) != -1)
	{
		**fmt != '%' ? tmp = va_arg(ap, void *) : 0;
		ft_select(tmp, **fmt, ct_str, flg);
		(*fmt)++;
	}
}

int				va_foreach(va_list ap, const char *fmt, char **ct_str,
				size_t len)
{
	size_t		lenlanding;

	lenlanding = 1;
	while (*fmt)
	{
		if (len == 0 || len >= (lenlanding * B_SIZE))
		{
			*ct_str = ft_realloc(*ct_str, lenlanding * B_SIZE);
			lenlanding++;
		}
		if (*fmt == '%' && ft_strlen(fmt) > 1)
			get_conv(&fmt, ct_str, ap);
		else
		{
			if (*fmt != '%')
				*ct_str = ft_strncat(*ct_str, fmt, 1);
			fmt++;
		}
		len = ft_strlen(*ct_str);
	}
	return (len);
}

int				ft_printf(const char *fmt, ...)
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
	write(1, ct_str, len);
	free(ct_str);
	return (len);
}
