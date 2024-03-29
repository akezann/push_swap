/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:49:53 by akezanna          #+#    #+#             */
/*   Updated: 2021/12/14 19:15:40 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "./../libft/libft.h"

typedef struct s_stack
{
	int	capacity;
	int	top;
	int	*array;
}		t_stack;

typedef struct s_array
{
	int	*array;
	int	*lis_content;
	int	*lis;
}		t_array;

typedef struct s_instructs
{
	int		i;
	int		j;
	int		total;
	int		a_up;
	int		a_down;
	int		b_up;
	int		b_down;
	int		a_move;
	int		b_move;
	int		min_index;
	int		c;
	int		check_argc;
	char	**argv;
}		t_instructs;

t_stack		*create_stack(int capacity);
void		sort_stack_three(t_stack *a);
void		sort_stack_five(t_stack *a, t_stack *b, t_instructs *inst);
void		s_push(t_stack *stack, int value);
void		s_pop(t_stack *stack);
void		parse_args(char **ar, int argc);
int			check_dig_arg(char *str);
void		push_args_to_stack(t_stack *s, char **arg, int argc);
void		operation_sa_sb(t_stack *stack, char *op_name);
void		operation_pa_pb(t_stack *stack_a, t_stack *stack_b, char *op_name);
void		operation_ra_rb(t_stack *stack, char *op_name);
void		operation_rra_rrb(t_stack *stack, char *op_name);
void		ft_exit_error(void);
void		push_args_to_array(t_array *arr, char **arg, int argc);
void		ft_lis(t_array *arr, int n);
void		insert_lis(t_array *arr, int len);
int			get_max(int *lis, int len);
int			check_element_existence(int *arr, int element, int len);
int			is_sorted(t_stack *a);
void		start_sorting(t_stack *a, t_stack *b, t_instructs *inst);
void		init_instructs(t_stack *a, t_stack *b, t_instructs *inst);
void		get_min_index(t_stack *a, t_instructs *inst);
void		sort_stack(t_stack *a, t_instructs *inst);
int			get_total(int aup, int adown, int bup, int bdown);
void		set_stack_b(t_stack *b, int up, int down);
void		set_stack_a(t_stack *a, int up, int down);
void		scan_stack_b(t_stack *a, t_stack *b, t_instructs *inst);
void		init_algo_data(t_stack *a, t_stack *b, t_array *arr, int len);
void		free_memory(t_stack *a, t_stack *b, t_array *arr);
void		free_split(char **argv);
char		**get_argv_split(char **argv, int *argc);
void		check_for_duplicate(int	*array, int len);

#endif
