#include "../../includes/push_swap.h"

void	condition_four(t_stack *stack)
{
	if (stack->b[0] > stack->b[1])
	{
		push_a(stack, 0);
		push_a(stack, 0);
		rotate_rr(stack, 1, 0, 0);
		rotate_rr(stack, 1, 0, 0);
	}
	else if (stack->b[0] < stack->b[1])
	{
		push_a(stack, 0);
		rotate_rr(stack, 1, 0, 0);
		push_a(stack, 0);
		rotate_rr(stack, 1, 0, 0);
	}
}

void	condition_five(t_stack *stack)
{
	int	r;

	r = 0;
	if (stack->a[stack->len_a - 1] < stack->a[1])
		r = 1;
	if (r)
		rotate_rr(stack, 1, 0, 0);
	else
		reverse_ab(stack, 1, 0, 0);
}

void	do_the_four(t_stack *stack)
{
	int	max;
	int	max_i;
	int	r;

	max_i = 0;
	max = get_max(stack->a, stack->len_a);
	while (stack->a[max_i] != max)
		max_i++;
	r = r_or_rr(stack->a, stack->len_a, max);
	while (stack->a[0] != max)
	{
		if (r)
			rotate_rr(stack, 1, 0, 0);
		else
			reverse_ab(stack, 1, 0, 0);
	}
	push_b(stack, 0);
	do_the_three(stack);
	push_a(stack, 0);
	rotate_rr(stack, 1, 0, 0);
}

void	do_the_five(t_stack *stack, int mdn)
{
	if (not_in_order(stack->a, stack->len_a))
	{
		if (stack->len_a == 4)
			do_the_four(stack);
		else
		{
			while (stack->len_a > 3)
			{
				if (stack->a[0] > mdn)
					push_b(stack, 0);
				else
					condition_five(stack);
			}
			do_the_three(stack);
			condition_four(stack);
		}
	}
}
