/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:33:19 by akezanna          #+#    #+#             */
/*   Updated: 2021/07/13 15:06:47 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	check_positivity(int n)
{
	if (n < 0)
		return ('-');
	return ('0');
}

static int	get_size(int n)
{
	int		size;

	size = 1;
	if (n < 0)
		size++;
	while (n / 10 != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		j;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = get_size(n);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	j = size - 1;
	if (n <= 0)
	{
		str[0] = check_positivity(n);
		n = -n;
	}
	while (n != 0)
	{
		str[j--] = n % 10 + '0';
		n = n / 10;
	}
	str[size] = '\0';
	return (str);
}
