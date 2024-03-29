/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:38:41 by akezanna          #+#    #+#             */
/*   Updated: 2021/12/14 18:40:34 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	get_min_index(t_stack *a, t_instructs *inst)
{
	int	min;
	int	i;
	int	min_ind;

	min = a->array[a->top];
	i = a->top - 1;
	min_ind = a->top;
	while (i > -1)
	{
		if (min > a->array[i])
		{
			min = a->array[i];
			min_ind = i;
		}
		i--;
	}
	inst->min_index = min_ind;
}

void	sort_stack(t_stack *a, t_instructs *inst)
{
	int	i;

	i = 0;
	get_min_index(a, inst);
	if (a->top - inst->min_index < inst->min_index + 1)
	{
		while (i++ < a->top - inst->min_index)
		{
			operation_ra_rb(a, "ra");
		}
	}
	else
	{
		while (i++ < inst->min_index + 1)
		{
			operation_rra_rrb(a, "rra");
		}
	}
}

int	get_total(int aup, int adown, int bup, int bdown)
{
	int	amove;
	int	bmove;

	amove = 0;
	bmove = 0;
	if (aup < adown)
		amove = aup;
	else
		amove = adown;
	if (bup < bdown)
		bmove = bup;
	else
		bmove = bdown;
	return (amove + bmove);
}

void	init_algo_data(t_stack *a, t_stack *b, t_array *arr, int len)
{
	int			c;
	t_instructs	inst;

	if (is_sorted(a))
		return ;
	if (a->top < 3)
	{
		sort_stack_three(a);
		return ;
	}
	if (a->top < 5)
	{
		sort_stack_five(a, b, &inst);
		return ;
	}
	c = a->top;
	while (c > -1)
	{
		if (check_element_existence(arr->lis_content, a->array[a->top],
				get_max(arr->lis, len)))
			operation_ra_rb(a, "ra");
		else
			operation_pa_pb(a, b, "pb");
		c--;
	}
}
