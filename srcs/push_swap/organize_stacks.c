#include "../../includes/push_swap.h"

// function to check if a given nb is closer to the end or the beggining of an array
// it will tell us if it's better to rotate or reverse rotate the stack
// if rotate, returns 1
// if reverse rotate returns 0
int r_or_rr(int *array, int len, int nb)
{
	int r = 0;
	int rr = len - 1;

	while (array[r] != nb)
		r++;

	while (array[rr] != nb)
		rr--;

	rr = len - rr;

	if (r > rr)
		return (0);
	else
		return (1);
}

void	do_the_three(t_stack *stack)
{
	int min = 0;
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

void	do_the_five(t_stack *stack)
{
	int max = 0;
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
	if (stack->len_a == 4)
	{
		max = get_max(stack->a, stack->len_a);
		max_i = 0;
		while (stack->a[max_i] != max)
			max_i++;
		while (stack->a[0] != max)
		{
			if (r)
				rotate_rr(stack, 1, 0, 0);
			else
				reverse_ab(stack, 1, 0, 0);
		}
		push_b(stack, 0);
	}
	do_the_three(stack);
	if (stack->b[0] < stack->b[1])
		swap_ab(stack, 0, 1, 0);
	push_a(stack, 0);
	push_a(stack, 0);
	rotate_rr(stack, 1, 0, 0);
	rotate_rr(stack, 1, 0, 0);
}

void    organize_stacks(t_stack *stack, int mdn)
{
	if (stack->len_a == 3)
		do_the_three(stack);
	else if (stack->len_a <= 5)
		do_the_five(stack);

	// divide stacks: a gets the smaller nbrs, b the bigger (not)
	// r = r_or_rr(stack->a, stack->len_a, mdn);
	// while (smaller_exists(stack->a, stack->len_a, mdn))
	// {
	// 	if (stack->a[0] <= mdn)
	// 	{
	// 		push_b(stack, 0);
	// 		if (stack->b[0] == mdn)
	// 		{
	// 			if(stack->a[0] > mdn)
	// 				rotate_rr(stack, 1, 1, 0);
	// 			else
	// 				rotate_rr(stack, 0, 1, 0);
	// 		}
	// 	}
	// 	else
	// 	{
	// 		if (stack->a[0] < stack->a[1])
	// 		{
	// 			if (stack->b[0] < stack->b[1])
	// 				swap_ab(stack, 1, 1, 0);
	// 			else
	// 				swap_ab(stack, 1, 0, 0);
	// 		}
	// 		else
	// 		{
	// 			if (r)
	// 				rotate_rr(stack, 1, 0, 0);
	// 			else
	// 				reverse_ab(stack, 1, 0, 0);
	// 		}
	// 	}
	// }

	// // get mdn_og to top of stack b and max nbr on top of stack a
	// min = get_min(stack->a, stack->len_a);
	// r = r_or_rr(stack->a, stack->len_a, min);

	// if (r)
	// {
	// 	reverse_ab(stack, 0, 1, 0);
	// 	while (stack->a[0] != min)
	// 		rotate_rr(stack, 1, 0, 0);
	// }
	// else
	// {
	// 	reverse_ab(stack, 1, 1, 0);
	// 	while (stack->a[0] != min)
	// 		reverse_ab(stack, 1, 0, 0);
	// }
	// push_b(stack, 0);

	// // empty stack a in decrescent order
	// while (not_in_order(stack->a, stack->len_a) || stack->len_a > 1)
	// {
	// 	min = get_min(stack->a, stack->len_a);
	// 	r = r_or_rr(stack->a, stack->len_a, min);

	// 	if (r)
	// 	{
	// 		while (stack->a[0] != min)
	// 			rotate_rr(stack, 1, 0, 0);
	// 		push_b(stack, 0);
	// 	}
	// 	else
	// 	{
	// 		while (stack->a[0] != min)
	// 			reverse_ab(stack, 1, 0, 0);
	// 		push_b(stack, 0);
	// 	}
	// }

	// // order stack a up to the mdn
	// while (stack->a[0] != mdn)
	// 	push_a(stack, 0);

	// // pass rest of stack b to stack a in decrescent order
	// while (not_empty(stack->b, stack->len_b))
	// {
	// 	max = get_max(stack->b, stack->len_b);
	// 	r = r_or_rr(stack->b, stack->len_b, max);

	// 	while (stack->b[0] != max)
	// 	{
	// 		if (r)
	// 			rotate_rr(stack, 0, 1, 0);
	// 		else
	// 			reverse_ab(stack, 0, 1, 0);
	// 	}
	// 	push_a(stack, 0);
	// }
	// push_a(stack, 0);

	// print_stacks(stack);
}