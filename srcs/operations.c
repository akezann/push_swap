#include "./../includes/push_swap.h"

void    operation_sa_sb(t_stack *stack, char *op_name)
{
    int tmp;

    if (stack->top == -1 || stack->top == 0)
        return ;
    else
    {
        tmp = stack->array[stack->top];
        stack->array[stack->top] = stack->array[stack->top - 1];
        stack->array[stack->top - 1] = tmp;
    }
    printf("%s\n", op_name);
}

void    operation_pa_pb(t_stack *stack_a, t_stack *stack_b, char *op_name)
{
    if (op_name[0] == 'p' && op_name[1] == 'a')
    {
        if (stack_b->top == -1)
            return ;
        else
        {
            s_push(stack_a, stack_b->array[stack_b->top]);
            s_pop(stack_b);
        }
    }
    if (op_name[0] == 'p' && op_name[1] == 'b')
    {
        if (stack_a->top == -1)
            return ;
        else
        {
            s_push(stack_b, stack_a->array[stack_a->top]);
            s_pop(stack_a);
        }
    }
    printf("%s\n", op_name);
}

void    operation_ra_rb(t_stack *stack, char *op_name)
{
    t_stack *tmp_stack = create_stack(stack->capacity);

    while (stack->top > -1)
    {
        s_push(tmp_stack, stack->array[stack->top]);
        stack->top--;
    }
    s_push(stack, tmp_stack->array[0]);
    while (tmp_stack->top > 0)
    {
        s_push(stack, tmp_stack->array[tmp_stack->top]);
        tmp_stack->top--;
    }
   printf("%s\n", op_name);
}

void    operation_rra_rrb(t_stack *stack, char *op_name)
{
    t_stack *tmp_stack = create_stack(stack->capacity);
    while (stack->top > -1)
    {
        s_push(tmp_stack, stack->array[stack->top]);
        stack->top--;
    }

    int tmp = tmp_stack->array[tmp_stack->top];
    tmp_stack->top--;
    while (tmp_stack->top > -1)
    {
        s_push(stack, tmp_stack->array[tmp_stack->top]);
        tmp_stack->top--;
    }
    s_push(stack, tmp);
    printf("%s\n", op_name);
}