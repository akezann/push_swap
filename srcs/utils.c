/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ak1337 <ak1337@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:08:23 by akezanna          #+#    #+#             */
/*   Updated: 2021/12/14 00:36:37 by ak1337           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	init_instructs(t_stack *a, t_stack *b, t_instructs *inst)
{
	inst->a_up = 0;
	inst->a_down = 0;
	inst->b_up = 0;
	inst->b_down = 0;
	inst->total = a->top + b->top;
}

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

int	count_args(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	return (i);
}

void	free_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
	//return (0);
}
