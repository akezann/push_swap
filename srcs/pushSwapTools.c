/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushSwapTools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ak1337 <ak1337@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:12:15 by akezanna          #+#    #+#             */
/*   Updated: 2021/12/12 01:36:10 by ak1337           ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_stack *a = create_stack(argc - 1);
	t_stack *b = create_stack(argc - 1);
	char	**split;
	t_instructs inst;
	t_array arr;
	int		*lis;
	
	// if (argc == 2 && ft_strchr(argv[1], ' '))
	// {
	// 	split = ft_split(argv[1], " ");
	// 	int i = 0;
	// 	while (split[i])
	// 		i++;
	// 	push_args_to_stack(a, split, i + 1);
	// 	push_args_to_array(&arr, split, i);	
	// }
	// else
	// {
		push_args_to_stack(a, argv, argc);
		push_args_to_array(&arr, argv, argc);
	// }
	if (is_sorted(a))
		return (0);
	arr.lisContent = insert_lis(arr.array, argc - 1);
	lis = ft_lis(arr.array, argc - 1);
	int c = a->top;
	while (c > -1)
	{
		if (check_element_existence(arr.lisContent, a->array[a->top],   get_max(lis, argc -1)))
			operation_ra_rb(a, "ra");
		else
			operation_pa_pb(a, b, "pb");
		c--;
	}
	start_sorting(a, b, &inst);
	while (a->top > -1)
		printf("%d|", a->array[a->top--]);
	return 0;
}