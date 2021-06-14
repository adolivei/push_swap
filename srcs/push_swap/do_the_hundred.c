#include "../../includes/push_swap.h"

int		update_size(t_stack *stack)
{
	int size = 0;

	if (stack->len_a <= 20)
		size = 1;
	else if (stack->len_a > 20 && stack->len_a <= 40)
		size = 2;
	else if (stack->len_a > 40 && stack->len_a <= 60)
		size = 3;
	else if (stack->len_a > 60 && stack->len_a <= 80)
		size = 4;
	else if (stack->len_a > 80 && stack->len_a <= 100)
		size = 5;
	return (size);
}

void	do_the_hundred(t_stack *stack, int mdn)
{
	int r = 0;
	int min = INT_MAX;
	int max = INT_MIN;
	// int size = 0;
	// int rotate_size = 0;

	// size = update_size(stack);

	// while (size > 0)
	// {
		// if (stack->len_a > 20)
		// 	stack->len_a = 20;
		// rotate_size = stack->len_a;
		// divide stacks: b gets the smaller nbrs, a the bigger
		while (smaller_exists(stack->a, stack->len_a, mdn))
		{
			if (stack->a[0] <= mdn)
				push_b (stack, 0);
			else
			{
				r = r_or_rr_lol(stack->a, stack->len_a, mdn);
				if (r)
					rotate_rr(stack, 1, 0, 0);
				else
					reverse_ab(stack, 1, 0, 0);
			}
		}

		// while (rotate_size > 0)
		// {
		// 	rotate_rr(stack, 1, 0, 0);
		// 	rotate_size--;
		// }


		// get mdn to top of stack b and min nbr to top of stack a
		decision_rrr(stack, mdn);
		push_b(stack, 0);

		// now we have stack a with the bigger nbrs and b with the smaller
		// we will push the nbrs from stack a, in decrescent order (minimum first) to stack b,
		// so we can then push them back to stack a.
		// after doing this, we'll have the bottom half of the stack already ordered in stack a,
		// while the top half continues, without order, in stack b
		while (stack->len_a > 3 && not_in_order(stack->a, stack->len_a))
		{
			min = get_min(stack->a, stack->len_a);
			r = r_or_rr(stack->a, stack->len_a, min);
			if (r)
			{
				while (stack->a[0] != min)
					rotate_rr(stack, 1, 0, 0);
				push_b(stack, 0);
			}
			else
			{
				while (stack->a[0] != min)
					reverse_ab(stack, 1, 0, 0);
				push_b(stack, 0);
			}
		}
		if (stack->len_a == 3)
			do_the_three(stack);

		while (not_empty(stack->b, stack->len_b))
		{
			max = get_max(stack->b, stack->len_b);
			r = r_or_rr(stack->b, stack->len_b, max);
			while (stack->b[0] != max)
			{
				if (r)
					rotate_rr(stack, 0, 1, 0);
				else
					reverse_ab(stack, 0, 1, 0);
			}
			push_a(stack, 0);
		}
		push_a(stack, 0);
	// 	size--;
	// }
}