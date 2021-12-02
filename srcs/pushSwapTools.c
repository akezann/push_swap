/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushSwapTools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ak1337 <ak1337@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:12:15 by akezanna          #+#    #+#             */
/*   Updated: 2021/12/01 22:20:36 by ak1337           ###   ########.fr       */
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
	int c = a->top;
	printf("\n");
	while (c > -1)
	{
		if (check_element_existence(arr.lisContent, a->array[a->top],  get_max(lis, argc - 1)))
			operation_ra_rb(a, "ra");
		else
			operation_pa_pb(a, b, "pb");
		c--;
	}
	//fill_arrays(a, b, &inst);
	//get_number_of_instructions(a,b, &inst);
	//  int i = 0;
	// printf("\n");
    // while (i < inst.len_a)
    // {
    //     printf("|%d|", inst.arr_of_a[i++]);
    // }
	// printf("\n");
	// i = 0;
    // while (i < inst.len_b)
    // {
    //     printf("|%d|", inst.arr_of_b[i++]);
    // }
	
	// printf("\nupa: %d--downa: %d--upb: %d--downb: %d |%d - %d|\n",inst.a_up, inst.a_down, inst.b_up, inst.b_down, inst.median_a, inst.median_b);
	// i = 0;
	// int instruct = 0;
	// if (inst.a_up > inst.a_down)
	// 	while (i < inst.a_down)
	// 	{
	// 		operation_rra_rrb(a, "rra");
	// 		i++;
	// 	}
	// else
	// 	while (i < inst.a_up)
	// 	{
	// 		operation_ra_rb(a, "ra");
	// 		i++;
	// 	}
	// operation_pa_pb(a,b,"pa");
	exec_algorithme(a, b, &inst);
	// operation_ra_rb(a,"ra");
	// operation_ra_rb(a,"ra");
	//printf("%d==%d\n", a->top, b->top);
	while (a->top > -1)
	{
		printf("|%d|", a->array[a->top--]);
	}
	printf("\n");
	while (b->top > -1)
	{
		printf("|%d|", b->array[b->top--]);
	}
	return 0;
}