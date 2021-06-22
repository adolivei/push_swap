#include "../../includes/push_swap.h"

int	get_chunksize(int len)
{
	int	size;

	size = 0;
	if (len < 50)
		size = len;
	else if (len >= 50 && len < 99)
		size = 30;
	else if (len >= 99 && len < 200)
		size = 20;
	else
		size = 40;
	return (size);
}

void	path(t_stack *stack, int r, int chunk_max)
{
	if (r)
	{
		while (stack->a[0] > chunk_max)
			rotate_rr(stack, 1, 0, 0);
		push_b(stack, 0);
	}
	else
	{
		while (stack->a[0] > chunk_max)
			reverse_ab(stack, 1, 0, 0);
		push_b(stack, 0);
	}
}

void	do_the_chunk(t_stack *stack, int chunk_size)
{
	static int	chunk_min;
	static int	chunk_max;
	int			r;

	r = 0;
	if (!chunk_min)
		chunk_min = 0;
	if (!chunk_max)
		chunk_max = chunk_size - 1;
	while (smaller_exists(stack->a, stack->len_a, chunk_max))
	{
		r = r_or_rr_lol(stack->a, stack->len_a, chunk_max);
		path(stack, r, chunk_max);
	}
	chunk_min += chunk_size;
	chunk_max += chunk_size;
}

void	path2(t_stack *stack, int r)
{
	if (r)
	{
		while (stack->b[0] != stack->a[0] - 1)
			rotate_rr(stack, 0, 1, 0);
		push_a(stack, 0);
	}
	else
	{
		while (stack->b[0] != stack->a[0] - 1)
			reverse_ab(stack, 0, 1, 0);
		push_a(stack, 0);
	}
}

// goddam this is now brig bain time
void	do_the_huge(t_stack *stack)
{
	int	chunk_size;
	int	max;
	int	r;

	if (not_in_order(stack->a, stack->len_a))
	{
		max = get_max(stack->a, stack->len_a);
		chunk_size = get_chunksize(stack->len_a);
		while (stack->len_a > 1)
			do_the_chunk(stack, chunk_size);
		push_b(stack, 0);
		while (stack->b[0] != max)
			rotate_rr(stack, 0, 1, 0);
		push_a(stack, 0);
		while (not_empty(stack->b, stack->len_b))
		{
			r = r_or_rr(stack->b, stack->len_b, stack->a[0] - 1);
			path2(stack, r);
		}
	}
	push_a(stack, 0);
}
