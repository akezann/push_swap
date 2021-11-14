/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:12:15 by akezanna          #+#    #+#             */
/*   Updated: 2021/09/26 15:12:16 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

t_stack *create_stack(int capacity)
{
	t_stack	*stack;
	stack = malloc(sizeof(stack));
	if (!stack)
		return NULL;
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = malloc(stack->capacity * sizeof(int));
	if (!stack->array)
		return NULL;
	return (stack);
}

void	s_push(t_stack *stack, int value)
{
	if (stack->top == stack->capacity - 1)
		return ;
	stack->top++;
	stack->array[stack->top] = value;
}

void	s_pop(t_stack *stack)
{
	if (stack->top == -1)
		return ;
	stack->top--;
}

int		ret_stack_value(t_stack *stack)
{
	return (stack->array[stack->top]);
}

int main(int argc, char **argv)
{
	t_stack *a = create_stack(argc - 1);
	push_argsToStack(a, argv, argc);
	//operation_ra_rb(a, "ra");
	while (a->top > -1)
	{
		printf("%d\n", a->array[a->top--]);
	}
	return 0;
}