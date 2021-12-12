/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:08:23 by akezanna          #+#    #+#             */
/*   Updated: 2021/12/12 20:09:39 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int	check_element_existence(int *arr, int element, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == element)
			return (1);
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	int	i;
	int	j;

	i = a->top;
	while (i > -1)
	{
		j = i - 1;
		while (j > -1)
		{
			if (a->array[i] > a->array[j])
				return (0);
			j--;
		}
		i--;
	}
	return (1);
}
