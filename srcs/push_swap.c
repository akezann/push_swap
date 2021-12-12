/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:49:40 by akezanna          #+#    #+#             */
/*   Updated: 2021/12/12 22:05:58 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"

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

	a = create_stack(argc - 1);
	b = create_stack(argc - 1);
	push_args_to_stack(a, argv, argc);
	push_args_to_array(&arr, argv, argc);
	arr.lis_content = insert_lis(arr.array, argc - 1);
	inst.lis = ft_lis(arr.array, argc - 1);
	if (is_sorted(a))
		return (0);
	inst.c = a->top;
	while (inst.c > -1)
	{
		if (check_element_existence(arr.lis_content, a->array[a->top],
				get_max(inst.lis, argc -1)))
			operation_ra_rb(a, "ra");
		else
			operation_pa_pb(a, b, "pb");
		inst.c--;
	}
	start_sorting(a, b, &inst);
	free(a);
	free(b);
	free(arr.lis_content);
	free(inst.lis);
	free(arr.array);
	free(a->array);
	free(b->array);
	return (0);
}
