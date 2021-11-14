/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:12:31 by akezanna          #+#    #+#             */
/*   Updated: 2021/09/26 15:14:23 by akezanna         ###   ########.fr       */
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

#endif
