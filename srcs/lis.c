/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ak1337 <ak1337@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:50:22 by akezanna          #+#    #+#             */
/*   Updated: 2021/12/14 00:06:59 by ak1337           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

int	get_max(int *lis, int len)
{
	int	max;
	int	i;

	max = lis[0];
	i = 1;
	while (i < len)
	{
		if (lis[i] > max)
			max = lis[i];
		i++;
	}
	return (max);
}

void	ft_lis(t_array *arr, int len)
{
	int	i;
	int	j;

	arr->lis = malloc(len * sizeof(int));
	arr->lis[0] = 1;
	i = 0;
	while (++i < len)
	{
		arr->lis[i] = 1;
		j = -1;
		while (++j < i)
		{
			if (arr->array[i] > arr->array[j] && arr->lis[i] < arr->lis[j] + 1)
			{
				arr->lis[i] = arr->lis[j] + 1;
			}
		}
	}
}

void	insert_lis(t_array *arr, int len)
{
	int	max;
	int	i;
	int	j;
	int	k;

	ft_lis(arr, len);
	max = get_max(arr->lis, len);
	arr->lis_content = malloc(sizeof(int) * max);
	i = len - 1;
	j = 0;
	k = max;
	while (i > -1)
	{
		if (arr->lis[i] == k)
		{
			arr->lis_content[j++] = arr->array[i];
			k--;
		}
		i--;
	}
	free(arr->array);
}
