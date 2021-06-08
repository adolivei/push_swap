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

// the same as r_or_rr but with > instead of !=
int r_or_rr_lol(int *array, int len, int nb)
{
	int r = 0;
	int rr = len - 1;

	while (array[r] > nb)
		r++;

	while (array[rr] > nb)
		rr--;

	rr = len - rr;

	if (r > rr)
		return (0);
	else
		return (1);
}

// similar to r_or_rr but to push nb to the top of a different array
// nb IS NOT in the array, and the array is ordered, contrarly to r_or_rr
// returns 1, rotate
// returns 0, reverse
int	r_or_rr_push(int *array, int len, int nb)
{
	int r = 0;
	int rr = len - 1;

	while (array[r] < nb)
		r++;

	while (array[rr] > nb)
		rr--;

	rr = len - rr;

	if (r > rr)
		return (0);
	else
		return (1);
}

// returns the nb of r or rr we need to get nb to top of stack upon r
int	get_rrr(int *array, int len, int nb, int r)
{
	int i;

	if (r)
	{
		i = 0;
		while (array[i] != nb)
			i++;
	}
	else
	{
		i = len - 1;
		while (array[i] != nb)
			i--;
		i = len - i;
	}
	return (i);
}

// int	get_rrr_push(int *array, int len, int nb)
// {
// 	int r = 0;
// 	int i;

// 	r = r_or_rr_push(array, len, nb);
// 	if (r)
// 	{
// 		i = 0;
// 		while (array[i] < nb)
// 			i++;
// 	}
// 	else
// 	{
// 		i = len - 1;
// 		while (array[i] < nb)
// 			i++;
// 		i = len - i;

// 	}
// 	return (i);
// }

// checks the various options in the flags struct and 
// activates the flag equivalent to the option with the shortest path
// it may return the min instead of void, i've not decided yet lol
void	get_total(t_flags *flag)
{
	int min = 0;
	int tmp = 0;

	if (flag->nra > flag->nrb)
		tmp = flag->nra;
	else
		tmp = flag->nrb;

	if (flag->nrra > flag->nrrb)
		min = flag->nrra;
	else
		min = flag->nrrb;

	if (min > tmp)
	{
		min = tmp;
		flag->b = 1; // rra + rrb
	}
	else
		flag->a = 1; // ra + rb

	if (flag->nra + flag->nrrb < min) // ra + rrb
	{
		min = flag->nra + flag->nrrb;
		flag->a = 0;
		flag->b = 0;
		flag->c = 1;
	}
	else if (flag->nrra + flag->nrb < min) // rra + rb
	{
		min = flag->nrra + flag->nrb;
		flag->a = 0;
		flag->b = 0;
		flag->d = 1;
	}
}

void	init_flags(t_flags *flag, t_stack *stack, int min, int mdn)
{
	flag->nra = get_rrr(stack->a, stack->len_a, min, 0);
	flag->nrb = get_rrr(stack->b, stack->len_b, mdn, 0);
	flag->nrra = get_rrr(stack->a, stack->len_a, min, 1);
	flag->nrrb = get_rrr(stack->b, stack->len_b, mdn, 1);
	flag->a = 0;
	flag->b = 0;
	flag->c = 0;
	flag->d = 0;
}

void	route_a(t_stack *stack, int min, int mdn)
{
	while (stack->a[0] != min && stack->b[0] != mdn)
		rotate_rr(stack, 1, 1, 0);
	while (stack->a[0] != min)
		rotate_rr(stack, 1, 0, 0);
	while (stack->b[0] != mdn)
		rotate_rr(stack, 0, 1, 0);
}

void	route_b(t_stack *stack, int min, int mdn)
{
	while (stack->a[0] != min && stack->b[0] != mdn)
		reverse_ab(stack, 1, 1, 0);
	while (stack->a[0] != min)
		reverse_ab(stack, 1, 0, 0);
	while (stack->b[0] != mdn)
		reverse_ab(stack, 0, 1, 0);
}

void	route_c(t_stack *stack, int min, int mdn)
{
	while (stack->a[0] != min)
		rotate_rr(stack, 1, 0, 0);
	while (stack->b[0] != mdn)
		reverse_ab(stack, 0, 1, 0);
}

void	route_d(t_stack *stack, int min, int mdn)
{
	while (stack->a[0] != min)
		reverse_ab(stack, 1, 0, 0);
	while (stack->b[0] != mdn)
		rotate_rr(stack, 0, 1, 0);
}

void	decision_rrr(t_stack *stack, int mdn)
{
	int min = INT_MAX;
	t_flags flag;

	min = get_min(stack->a, stack->len_a);
	init_flags(&flag, stack, min, mdn);
	get_total(&flag);

	if (flag.a) // ra + rb
		route_a(stack, min, mdn);
	else if (flag.b) // rra + rrb
		route_b(stack, min, mdn);
	else if (flag.c) // ra + rrb
		route_c(stack, min, mdn);
	else if (flag.d) // rra + rb
		route_d(stack, min, mdn);
}