/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:12:31 by akezanna          #+#    #+#             */
/*   Updated: 2021/12/10 17:07:28 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "./../libft/libft.h"

typedef struct s_stack
{
	int	capacity;
	int top;
	int	*array;
}		t_stack;

typedef struct s_array
{
	int	*array;
	int *lisContent;
}		t_array;

typedef struct s_instucts
{
	int	len_a;
	int	len_b;
	int	*arr_of_a;
	int *arr_of_b;
	int	total;
	int	a_up;
	int	a_down;
	int	b_up;
	int	b_down;
	int	a_move;
	int	b_move;
	int found;
	int	min_index;
	int max_index;
}		t_instructs;

void    push_to_b(t_stack *a, t_stack *b, t_instructs *inst);
void    exec_algorithme(t_stack *a, t_stack *b, t_instructs *inst);
void     fill_arrays(t_stack *a, t_stack *b, t_instructs *inst);
t_stack		*create_stack(int capacity);
void		s_push(t_stack *stack, int value);
void		s_pop(t_stack *stack);
int			ret_stack_value(t_stack *stack);
void		parse_args(char **ar, int argc);
int			check_dig_arg(char *str);
void		push_argsToStack(t_stack *s, char **arg, int argc);
void    	operation_sa_sb(t_stack *stack, char *op_name);
void		operation_pa_pb(t_stack *stack_a, t_stack *stack_b, char *op_name);
void    	operation_ra_rb(t_stack *stack, char *op_name);
void    	operation_rra_rrb(t_stack *stack, char *op_name);
void    	ft_exitError(void);
void		sortStackOfThree(t_stack *stack, char *op);
void		pushArgsToArray(t_array *arr, char **arg, int argc);
void		quickSort(int *array, int low, int high);
void		stackPartition(t_array *arr, t_stack *a, t_stack *b, int argc);
int     	*ft_lis(int *arr, int n);
int    		*insert_lis(int *arr, int len);
int     	get_max(int *lis, int len);
int        	check_element_existence(int *arr, int element, int len);
void		get_number_of_instructions(t_stack *a, t_stack *b, t_instructs *inst);
void     	the_min_in_stack(t_stack *a, t_stack *b, t_instructs *inst);

#endif
