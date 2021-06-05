#include "../../includes/push_swap.h"

void	do_the_hundred(t_stack *stack, int mdn, int tb)
{
	int r = 0;
	int min = INT_MAX;
	int max = INT_MIN;

	// while (smaller_exists(stack->a, stack->len_a, tb))
	// {
	// 	if (stack->a[0] < tb)
	// 	{
	// 		if (stack->b[0] < stack->b[stack->len_b])
	// 		{
	// 			if (stack->a[0] >= tb)
	// 				rotate_rr(stack, 1, 1, 0);
	// 			else
	// 				rotate_rr(stack, 0, 1, 0);
	// 		}
	// 		if (stack->b[0] < stack->b[1])
	// 		{
	// 			if (stack->a[0] > stack->a[1])
	// 				swap_ab(stack, 1, 1, 0);
	// 			else
	// 				swap_ab(stack, 0, 1, 0);
	// 		}
	// 		push_b(stack, 0);
	// 	}
	// 	else
	// 		rotate_rr(stack, 1, 0, 0);
	// }
	// do_the_three(stack);

	// divide stacks: a gets the smaller nbrs, b the bigger (not)
	r = r_or_rr(stack->a, stack->len_a, mdn);
	while (smaller_exists(stack->a, stack->len_a, mdn))
	{
		if (stack->a[0] <= mdn)
		{
			push_b(stack, 0);
			if (stack->b[0] == mdn)
			{
				if(stack->a[0] > mdn)
					rotate_rr(stack, 1, 1, 0);
				else
					rotate_rr(stack, 0, 1, 0);
			}
		}
		else
		{
			if (stack->a[0] < stack->a[1])
			{
				if (stack->b[0] < stack->b[1])
					swap_ab(stack, 1, 1, 0);
				else
					swap_ab(stack, 1, 0, 0);
			}
			else
			{
				if (r)
					rotate_rr(stack, 1, 0, 0);
				else
					reverse_ab(stack, 1, 0, 0);
			}
		}
	}

	// get mdn_og to top of stack b and max nbr on top of stack a
	min = get_min(stack->a, stack->len_a);
	r = r_or_rr(stack->a, stack->len_a, min);

	if (r)
	{
		reverse_ab(stack, 0, 1, 0);
		while (stack->a[0] != min)
			rotate_rr(stack, 1, 0, 0);
	}
	else
	{
		reverse_ab(stack, 1, 1, 0);
		while (stack->a[0] != min)
			reverse_ab(stack, 1, 0, 0);
	}
	push_b(stack, 0);


	// empty stack a in decrescent order
	while (not_in_order(stack->a, stack->len_a) && stack->len_a > 3)
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
	if (not_in_order(stack->a, stack->len_a))
		do_the_three(stack);

	// pass rest of stack b to stack a in decrescent order
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

}