/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:14:44 by akezanna          #+#    #+#             */
/*   Updated: 2021/12/14 15:34:32 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	sort_stack_three(t_stack *a)
{
	if (a->array[0] < a->array[a->top] && a->array[0] < a->array[a->top - 1])
	{
		if (a->array[a->top] < a->array[a->top - 1])
			operation_rra_rrb(a, "rra");
		else
		{
			operation_sa_sb(a, "sa");
			operation_rra_rrb(a, "rra");
		}
	}	
	if (a->array[0] > a->array[a->top] && a->array[0] > a->array[a->top - 1])
		if (a->array[a->top] > a->array[a->top - 1])
			operation_sa_sb(a, "sa");
	if (a->array[0] > a->array[a->top] && a->array[0] < a->array[a->top - 1])
	{
		operation_rra_rrb(a, "rra");
		operation_sa_sb(a, "sa");
	}
}

void	sort_stack_five(t_stack *a, t_stack *b, t_instructs *inst)
{
	if (a->top < 4)
		operation_pa_pb(a, b, "pb");
	else if (a->top < 5)
	{
		operation_pa_pb(a, b, "pb");
		operation_pa_pb(a, b, "pb");
	}
	sort_stack_three(a);
	start_sorting(a, b, inst);
}
