/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm->c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ak1337 <ak1337@student->42->fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:40:14 by ak1337            #+#    #+#             */
/*   Updated: 2021/12/01 22:14:33 by ak1337           ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/push_swap.h"


void     fill_arrays(t_stack *a, t_stack *b, t_instructs *inst)
{
    int len_a = a->top;
    inst->len_a = len_a + 1;
    int len_b = b->top;
    inst->len_b = len_b + 1;
    int i = 0, j = 0;
    inst->arr_of_a = malloc(sizeof(int) * len_a);
    inst->arr_of_b = malloc(sizeof(int) * len_b);
    while (len_a > -1)
    {
        inst->arr_of_a[i] = a->array[len_a--];
        i++;
    }
     while (len_b > -1)
    {
        inst->arr_of_b[j] = b->array[len_b--];
        j++;
    }
}

void     get_number_of_instructions(t_stack *a, t_stack *b, t_instructs *inst)
{
    int i = 0;
    int j = 0;
    inst->median_a = inst->len_a / 2;
    inst->median_b = inst->len_b / 2;
    inst->a_up = 0;
    inst->b_up = 0;
    inst->a_down = 0;
    inst->b_down = 0;
    while (i < inst->len_a)
    {
        if (inst->arr_of_b[0] > inst->arr_of_a[i] && inst->arr_of_b[0] < inst->arr_of_a[i + 1])
            inst->a_up = i + 1;
        else
            inst->a_down = inst->len_a - i;
        i++;
    }
}

void    exec_algorithme(t_stack *a, t_stack *b, t_instructs *inst)
{
    int i = 0;
    fill_arrays(a, b, inst);
    while (b->top > -1)
    {
        get_number_of_instructions(a, b, inst);
        if (inst->a_up > inst->a_down)
            while (i < inst->a_down)
            {
                operation_rra_rrb(a, "rra");
                i++;
            }
        else
            while (i < inst->a_up)
            {
                operation_ra_rb(a, "ra");
                i++;
            }
        operation_pa_pb(a,b,"pa");
        b->top--;
    }
}