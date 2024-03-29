/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:23:38 by akezanna          #+#    #+#             */
/*   Updated: 2021/12/14 15:00:56 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	set_stack_a(t_stack *a, int up, int down)
{
	int	i;

	i = -1;
	if (up < down)
		while (++i < up)
			operation_ra_rb(a, "ra");
	else
		while (++i < down)
			operation_rra_rrb(a, "rra");
}

void	set_stack_b(t_stack *b, int up, int down)
{
	int	i;

	i = -1;
	if (up < down)
		while (++i < up)
			operation_ra_rb(b, "rb");
	else
		while (++i < down)
			operation_rra_rrb(b, "rrb");
}

void	scan_stack_b(t_stack *a, t_stack *b, t_instructs *inst)
{
	inst->j = a->top + 1;
	init_instructs(a, b, inst);
	while (--inst->j > 0)
	{
		inst->i = b->top + 1;
		while (--inst->i > -1)
		{
			if (b->array[inst->i] > a->array[inst->j] && b->array[inst->i]
				< a->array[inst->j - 1])
			{
				if (get_total(a->top - inst->j + 1, inst->j, b->top
						- inst->i, inst->i + 1) < inst->total)
				{
					inst->a_up = a->top - inst->j + 1;
					inst->a_down = inst->j;
					inst->b_up = b->top - inst->i;
					inst->b_down = inst->i + 1;
					inst->total = get_total(a->top - inst->j + 1, inst->j,
							b->top - inst->i, inst->i + 1);
				}
			}
		}
	}
}

void	start_sorting(t_stack *a, t_stack *b, t_instructs *inst)
{
	while (b->top > -1)
	{
		scan_stack_b(a, b, inst);
		set_stack_b(b, inst->b_up, inst->b_down);
		if ((inst->a_up > 0 && inst->a_down > 0)
			|| (b->array[b->top] < a->array[a->top]
				&& b->array[b->top] > a->array[0]))
		{
			set_stack_a(a, inst->a_up, inst->a_down);
			operation_pa_pb(a, b, "pa");
		}
		else
		{
			sort_stack(a, inst);
			operation_pa_pb(a, b, "pa");
		}
	}
	sort_stack(a, inst);
}
