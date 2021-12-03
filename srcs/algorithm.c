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
    int i = 0;
    inst->arr_of_a = malloc(sizeof(int) * inst->len_a);
    while (len_a > -1)
    {
        inst->arr_of_a[i++] = a->array[len_a--];
    }
}

void     the_min_in_stack(t_stack *a, t_stack *b, t_instructs *inst)
{
    fill_arrays(a, b, inst);
    int min = inst->arr_of_a[0];
    int i = 0;
    inst->min_index = 0;
    while (i < inst->len_a)
    {
        if (min > inst->arr_of_a[i])
        {
            min = inst->arr_of_a[i];
            inst->min_index = i;
        }
        i++;
    }
}

void     get_number_of_instructions(t_stack *a, t_stack *b, t_instructs *inst)
{
    int backup_a = a->top;
    int i = a->top;
    inst->a_up = 0;
    inst->a_down = 0;
    while (i > 0)
    {
        if (b->array[b->top] > a->array[i] && b->array[b->top] < a->array[i - 1])
        {
            inst->a_up = backup_a - i + 1;
            //inst->a_down = inst->len_a - i - 1;
        }
        else if (b->array[b->top] < a->array[i] && b->array[b->top] > a->array[i - 1])
        {
            inst->a_up = backup_a - i - 1;
            //inst->a_down = inst->len_a - i - 1;
        }
        i--;
    }
    a->top = backup_a;
}

void    exec_algorithme(t_stack *a, t_stack *b, t_instructs *inst)
{
    int i;
    int pos;
    while (b->top > -1)
    {
        fill_arrays(a, b, inst);
        get_number_of_instructions(a, b, inst);
        
        i = 0;
       // if (inst->a_up < inst->a_down)
            while (i < inst->a_up)
            {
                operation_ra_rb(a, "ra");
                i++;
            }
    //
        operation_pa_pb(a, b, "pa");
        the_min_in_stack(a, b, inst);
        i = 0;
        if ((inst->len_a - inst->min_index < inst->min_index))
            while (i < inst->len_a - inst->min_index)
            {
                operation_rra_rrb(a, "rra");
                i++;
            }
        else
            while (i < inst->min_index)
            {
                operation_ra_rb(a, "ra");
                i++;
            }
    }
}