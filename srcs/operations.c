/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:59:49 by akezanna          #+#    #+#             */
/*   Updated: 2021/12/13 16:03:43 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	operation_sa_sb(t_stack *stack, char *op_name)
{
	int	tmp;

	if (stack->top == -1 || stack->top == 0)
		return ;
	else
	{
		tmp = stack->array[stack->top];
		stack->array[stack->top] = stack->array[stack->top - 1];
		stack->array[stack->top - 1] = tmp;
	}
	printf("%s\n", op_name);
}

void	operation_pa_pb(t_stack *stack_a, t_stack *stack_b, char *op_name)
{
	if (op_name[0] == 'p' && op_name[1] == 'a')
	{
		if (stack_b->top == -1)
			return ;
		else
		{
			s_push(stack_a, stack_b->array[stack_b->top]);
			s_pop(stack_b);
		}
	}
	if (op_name[0] == 'p' && op_name[1] == 'b')
	{
		if (stack_a->top == -1)
			return ;
		else
		{
			s_push(stack_b, stack_a->array[stack_a->top]);
			s_pop(stack_a);
		}
	}
	printf("%s\n", op_name);
}

void	operation_ra_rb(t_stack *stack, char *op_name)
{
	int	*save_stack;
	int	i;
	int	j;

	save_stack = malloc(stack->capacity * sizeof(int));
	i = stack->top;
	j = 0;
	while (stack->top > -1)
	{
		save_stack[j] = stack->array[stack->top];
		stack->top--;
		j++;
	}
	s_push(stack, save_stack[0]);
	while (i > 0)
	{
		s_push(stack, save_stack[i]);
		i--;
	}
	printf("%s\n", op_name);
	free(save_stack);
}

void	operation_rra_rrb(t_stack *stack, char *op_name)
{
	int	*save_stack;
	int	tmp;
	int	i;
	int	j;

	save_stack = malloc(stack->capacity * sizeof(int));
	i = stack->top;
	j = 0;
	while (stack->top > -1)
	{
		save_stack[j] = stack->array[stack->top];
		j++;
		stack->top--;
	}
	j = i;
	tmp = save_stack[j];
	j--;
	while (j > -1)
	{
		s_push(stack, save_stack[j]);
		j--;
	}
	s_push(stack, tmp);
	printf("%s\n", op_name);
	free(save_stack);
}
