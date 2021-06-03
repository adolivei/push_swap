#include "../../includes/push_swap.h"

// sa : swap a - swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements).
// len is the nb of elements in stack a
void    swap_a(t_stack *stack)
{
    int tmp;

    tmp = 0;
    tmp = stack->a[0];
    stack->a[0] = stack->a[1];
    stack->a[1] = tmp;

}

// sb : swap b - swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements).
void    swap_b(t_stack *stack)
{
    int tmp;

    tmp = 0;
    tmp = stack->b[0];
    stack->b[0] = stack->b[1];
    stack->b[1] = tmp;
}

// ss : sa and sb at the same time.
void    swap_ab(t_stack *stack, int a, int b, int c)
{
    if (a && stack->len_a > 1)
        a = 1;
    else
        a = 0;

    if (b && stack->len_b > 1)
        b = 1;
    else
        b = 0;
        
    if (a)
        swap_a(stack);
    if (b)
        swap_b(stack);

    if (!c)
    { 
        if (a && b)
            ft_putstr_fd("ss\n", 1);
        else if (a && !b)
            ft_putstr_fd("sa\n", 1);
        else if (!a && b)
            ft_putstr_fd("sb\n", 1);
    }
    		print_stacks(stack);
}