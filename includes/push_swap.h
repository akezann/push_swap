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
#include "./../libft/libft.h"

typedef struct s_stack
{
	int	capacity;
	int top;
	int	*array;
}		t_stack;

t_stack		*create_stack(int capacity);
void		push(t_stack *stack, int value);
void		pop(t_stack *stack);
int			ret_stack_value(t_stack *stack);



#endif
