/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:45:50 by dsebban           #+#    #+#             */
/*   Updated: 2015/12/11 12:04:24 by dsebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *ptr)
{
	int sign;
	int digit;
	int result;

	result = 0;
	sign = 1;
	while ((*ptr >= 9 && *ptr <= 13) || *ptr == 32)
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (*ptr && (*ptr >= 48 && *ptr <= 57))
	{
		digit = *ptr - 48;
		result = (result * 10) + digit;
		ptr++;
	}
	return (sign == -1) ? -result : result;
}
