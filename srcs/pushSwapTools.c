/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushSwapTools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ak1337 <ak1337@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:12:15 by akezanna          #+#    #+#             */
/*   Updated: 2021/12/05 01:40:19 by ak1337           ###   ########.fr       */
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
	t_stack *b = create_stack(argc - 1);
	t_instructs inst;
	t_array arr;
	int		*lis;
	push_argsToStack(a, argv, argc);
	pushArgsToArray(&arr, argv, argc);
	arr.lisContent = insert_lis(arr.array, argc);
	lis = ft_lis(arr.array, argc - 1);
	int i = 0;
	printf("\n");
	while (i < argc - 1)
	{
		printf("|%d|", lis[i++]);
	}
	printf("\n");
	i = 0;
	while (i < get_max(lis, argc -1))
	{
		printf("|%d|", arr.lisContent[i++]);
	}
	printf("\n");
	while (a->top > -1)
	{
		printf("|%d|", a->array[a->top--]);
	}
	int c = a->top;
	while (c > -1)
	{
		if (check_element_existence(arr.lisContent, a->array[a->top],   get_max(lis, argc -1)))
			operation_ra_rb(a, "ra");
		else
			operation_pa_pb(a, b, "pb");
		c--;
	}
	printf("\n");
	while (a->top > -1)
	{
		printf("|%d|", a->array[a->top--]);
	}
	// exec_algorithme(a, b, &inst);
	// // printf("\n");
	// // while (a->top > -1)
	// // {
	// // 	printf("|%d|", a->array[a->top--]);
	// // }
	return 0;
}