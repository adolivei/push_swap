#include "../../includes/push_swap.h"

void	do_the_three(t_stack *stack)
{
	int min = INT_MAX;
	int min_i = 0;

	min = get_min(stack->a, stack->len_a);
	while(stack->a[min_i] != min)
		min_i++;

	if (min_i == 0 && stack->a[1] > stack->a[2])
	{
		reverse_ab(stack, 1, 0, 0);
		if (stack->b[0] < stack->b[1])
			swap_ab(stack, 1, 1, 0);
		else
			swap_ab(stack, 1, 0, 0);
	}
	else if (min_i == 1 && stack->a[0] > stack->a[2])
	{
		rotate_rr(stack, 1, 0, 0);
	}
	else if (min_i == 1 && stack->a[0] < stack->a[2])
	{
		if (stack->b[0] < stack->b[1])
			swap_ab(stack, 1, 1, 0);
		else
			swap_ab(stack, 1, 0, 0);
	}
	else if (min_i == 2 && stack->a[0] > stack->a[1])
	{
		if (stack->b[0] < stack->b[1])
			swap_ab(stack, 1, 1, 0);
		else
			swap_ab(stack, 1, 0, 0);
		reverse_ab(stack, 1, 0, 0);
	}
	else if (min_i == 2 && stack->a[0] < stack->a[1])
	{
		reverse_ab(stack, 1, 0, 0);
	}

}

void	do_the_four(t_stack *stack)
{
	int max = INT_MIN;
	int max_i = 0;
	int r = 0;

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
	int r = 0;

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
				{
					if (stack->a[stack->len_a - 1] < stack->a[1])
						r = 1;
					if (r)
						rotate_rr(stack, 1, 0, 0);
					else
						reverse_ab(stack, 1, 0, 0);
				}
			}
			do_the_three(stack);
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
	}
}

int    organize_stacks(t_stack *stack)
{
	int mdn;
	int	*tmp;
	int *phony;

	if (not_in_order(stack->a, stack->len_a))
	{

		print_stacks(stack);

		phony = array_dup(stack->a, stack->len_a);
		bubble_sort(phony, stack->len_a);
		tmp = array_dup(stack->a, stack->len_a);
		free (stack->a);
		stack->a = get_abstract(tmp, phony, stack->len_a);
		free (tmp);
		free (phony);
		phony = array_dup(stack->a, stack->len_a);
		bubble_sort(phony, stack->len_a);
		mdn = get_median(phony, stack->len_a);
		free (phony);


		print_stacks(stack);

		if (stack->len_a == 3)
			do_the_three(stack);
		else if (stack->len_a <= 5)
			do_the_five(stack, mdn);
		else
			do_the_huge(stack);

		
		print_stacks(stack);
	}
	return (0);
}