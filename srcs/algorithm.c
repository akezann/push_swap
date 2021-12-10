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

void fill_arrays(t_stack *a, t_stack *b, t_instructs *inst)
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

void the_min_in_stack(t_stack *a, t_stack *b, t_instructs *inst)
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

void sort_stack(t_stack *a)
{
    int min = a->array[a->top];
    int i = a->top - 1;
    int min_ind = a->top;
    while (i > -1)
    {
        if (min > a->array[i])
        {
            min = a->array[i];
            min_ind = i;
        }
        i--;
    }
    i = 0;
    if (a->top - min_ind < min_ind + 1)
    {
        while (i++ < a->top - min_ind)
        {
            operation_ra_rb(a, "ra");
        }
    }
    else
    {
        while (i++ < min_ind + 1)
        {
            operation_rra_rrb(a, "rra");
        }
    }
}

int get_total(int aup, int adown, int bup, int bdown)
{
    int amove = 0;
    int bmove = 0;

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

void set_stack_a(t_stack *a, int up, int down)
{
    int i;

    i = 0;
    if (up < down)
        while (i++ < up)
            operation_ra_rb(a, "ra");
    else
        while (i++ < down)
            operation_rra_rrb(a, "rra");
}

void push_to_a(t_stack *a, t_stack *b, int up, int down)
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

void scan_stack_b(t_stack *a, t_stack *b, t_instructs *inst)
{
    int i;
    int j;
    int aup = 0;
    int adown = 0;
    int bup = 0;
    int bdown = 0;
    inst->a_up = 0;
    inst->a_down = 0;
    inst->b_up = 0;
    inst->b_down = 0;
    j = a->top;
    inst->total = a->top + b->top;

    while (j > 0)
    {
        i = b->top;
        while (i > -1)
        {
            if (b->array[i] > a->array[j] && b->array[i] < a->array[j - 1])
            {
                inst->found = 1;
                aup = a->top - j + 1;
                adown = j;
                bup = b->top - i;
                bdown = i + 1;
                if (get_total(aup, adown, bup, bdown) < inst->total)
                {
                    inst->a_up = aup;
                    inst->a_down = adown;
                    inst->b_up = bup;
                    inst->b_down = bdown;
                    inst->total = get_total(aup, adown, bup, bdown);
                }
            }
            i--;
        }
        j--;
    }
}

void push_to_b(t_stack *a, t_stack *b, t_instructs *inst)
{
    while (b->top > -1)
    {
        scan_stack_b(a, b, inst);
            if (inst->a_up > 0 || inst->a_down > 0)
            {
                set_stack_a(a, inst->a_up, inst->a_down);
                push_to_a(a, b, inst->b_up, inst->b_down);
            }
            else
            {
                sort_stack(a);
                push_to_a(a, b, inst->b_up, inst->b_down);
                if (a->array[a->top] > a->array[0])
                    operation_ra_rb(a, "ra");
            }
    }
    sort_stack(a);
}