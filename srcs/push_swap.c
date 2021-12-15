/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:49:40 by akezanna          #+#    #+#             */
/*   Updated: 2021/12/14 19:04:19 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

void	free_memory(t_stack *a, t_stack *b, t_array *arr)
{
	free(arr->lis_content);
	free(arr->lis);
	free(a->array);
	free(b->array);
	free(a);
	free(b);
}

t_stack	*create_stack(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = malloc(stack->capacity * sizeof(int));
	if (!stack)
		return (NULL);
	if (!stack->array)
		return (NULL);
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

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_instructs	inst;
	t_array		arr;

	inst.argv = get_argv_split(argv, &argc);
	a = create_stack(argc);
	b = create_stack(argc);
	push_args_to_stack(a, inst.argv, argc);
	push_args_to_array(&arr, inst.argv, argc);
	insert_lis(&arr, argc);
	init_algo_data(a, b, &arr, argc);
	start_sorting(a, b, &inst);
	free_memory(a, b, &arr);
	free_split(inst.argv);
	return (0);
}
