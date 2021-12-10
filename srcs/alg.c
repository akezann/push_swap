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

int     get_total(int aup, int adown, int bup, int bdown)
{
    int amove;
    int bmove;

    if (aup < adown)
        amove = aup;
    else
        amove = adown;
    if (bup < bdown)
        bmove = bup;
    else
        bmove = bdown;
    return (amove + bmove);
}

void     push_to_a(t_stack *a, t_stack *b, int up, int down)
{
    int i;

    i = 0;
    if (up < down)
        while (i++ < up)
            operation_ra_rb(b, "rb");
    else
        while (i++ < down)
            operation_rra_rrb(b, "rrb");
    operation_pa_pb(a, b, "pa");
}

int     scan_stack_a(t_stack *a, t_stack *b, t_instructs *inst, int ind)
{
    int i;

    i = a->top;

    while (i > 0)
    {
        if (b->array[ind] > a->array[i] && b->array[ind] < a->array[i - 1])
        {
            inst->a_up = a->top - i + 1;
            inst->a_down = i;
            return (1);
        }
        else
            push_to_a(a, b, b->top - ind, ind + 1);
        i--;
    }
    return (0);
}

int    scan_stack_b(t_stack *a, t_stack *b, t_instructs *inst)
{
    int i;
    int bup;
    int bdown;

    if (a->array[a->top] > b->array[b->top])
    {
        operation_pa_pb(a, b, "pa");
    }
    if (a->array[0] < b->array[b->top])
    {
        operation_pa_pb(a, b, "pa");
        operation_ra_rb(b, "ra");
    }
    i = b->top;
    inst->total = a->top + b->top;
    while (i > -1)
    {
        bup = b->top - i;
        bdown = i + 1;
        if (scan_stack_a(a, b, inst, i))
        {
            if (get_total(inst->a_up, inst->a_down, bup, bdown) < inst->total)
            {
                inst->b_up = bup;
                inst->b_down = bdown;
                inst->total = get_total(inst->a_up, inst->a_down, inst->b_up, inst->b_down);
                return (1);
            }
        }
        i--;
    }
    return (0);
}

void    push_to_b(t_stack *a, t_stack *b, t_instructs *inst)
{
    int i;

    i = 0;
    inst->a_down = 0;
    inst->a_up = 0;
    inst->b_up = 0;
    inst->b_down = 0;
    
    while (b->top > -1)
    {
        if (scan_stack_b(a, b, inst))
        {i = 0;
        if (inst->a_up > 0 || inst->a_down > 0)
        {  
            if (inst->a_up < inst->a_down)
                while (i++ < inst->a_up)
                    operation_ra_rb(a, "ra");
            else
                while (i++ < inst->a_down)
                    operation_rra_rrb(a, "rra");
        }
        push_to_a(a, b, inst->b_up, inst->b_down);}
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