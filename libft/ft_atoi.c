/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:03:46 by akezanna          #+#    #+#             */
/*   Updated: 2021/07/13 13:50:37 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long		res;
	int			sgn;

	res = 0;
	sgn = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		sgn = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - 48;
		str++;
		if (sgn == 1 && res < 0)
			return (-1);
		if (sgn == -1 && res < 0)
			return (0);
	}
	return (sgn * res);
}
