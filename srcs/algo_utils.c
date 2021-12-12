/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:38:41 by akezanna          #+#    #+#             */
/*   Updated: 2021/12/12 19:39:49 by akezanna         ###   ########.fr       */
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
