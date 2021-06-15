#include "../../includes/push_swap.h"

int		*array_dup(int *array, int len)
{
	int i = 0;
	int *new;

	if (!array || len < 1)
		return (NULL);
	new = (int *)malloc(sizeof(int) * len);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = array[i];
		i++;
	}
	return (new);
}

int		get_index_position(int *array, int nb)
{
	int i = 0;

	while (array[i] != nb)
		i++;
	return (i);
}

// returns an array of ints which contains the ordered index of each int in real
// if real is [3947, -28, 0, 40], abstract will be [3, 0, 1, 2]
int		*get_abstract(int *real, int *fake, int len)
{
	int *abstract;
	int i = 0;

	abstract = (int *)malloc(sizeof(int) * len);
	if (!abstract)
		return (NULL);
	while (i < len)
	{
		abstract[i] = get_index_position(fake, real[i]);
		i++;
	}	
	return (abstract);
}

int		get_chunksize(int len)
{
	int size = 0;

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

// gets every chunk from stack a to stack b
void	do_the_chunk(t_stack *stack, int max, int chunk_size)
{
	static int chunk_min = 0;
	static int chunk_max = 0;
	int r = 0;

	if (chunk_max == 0)
		chunk_max = chunk_size - 1;

	while (smaller_exists(stack->a, stack->len_a, chunk_max))
	{
		r = r_or_rr_lol(stack->a, stack->len_a, chunk_max);
		if (r)
		{
			while (stack->a[0] > chunk_max)
			{
				rotate_rr(stack, 1, 0, 0);
			}
			push_b(stack, 0);

		}
		else
		{
			while (stack->a[0] > chunk_max)
			{
				reverse_ab(stack, 1, 0, 0);
			}
			push_b(stack, 0);
		}
	}

	chunk_min += chunk_size;
	chunk_max += chunk_size;
}

// goddam this is now brig bain time
void	do_the_huge(t_stack *stack, int *phony)
{
	int chunk_size = 0;
	int *tmp;
	int max = INT_MIN;
	int r = 0;


	if (not_in_order(stack->a, stack->len_a))
	{

		tmp = array_dup(stack->a, stack->len_a);
		free (stack->a);
		stack->a = get_abstract(tmp, phony, stack->len_a);
		free (tmp);
		max = get_max(stack->a, stack->len_a);
		chunk_size = get_chunksize(stack->len_a);
		while (stack->len_a > 1)
		{
			do_the_chunk(stack, max, chunk_size);
		}
		push_b(stack, 0);


		// numbers inside stack b are divided by chunks, but the chunks are not ordered within theirself
		// ex: first chunk has all the nbrs between 0 and 9 together but not ordered
		// and the second chunk (with 10-19) will be on top of chunk 1 and so on
		// we first need to order the last chunk inside stack a and then push everything from stack b to it, by order

		while (stack->b[0] != max)
		{
			rotate_rr(stack, 0, 1, 0);
		}
		push_a(stack, 0);
		while (not_empty(stack->b, stack->len_b))
		{
			r = r_or_rr(stack->b, stack->len_b, stack->a[0] - 1);
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
	}


	push_a(stack, 0);

	// print_stacks(stack);

}