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

// still need to apply a way to decide the chunk size upon the lenght of the input
void	do_the_chunk(t_stack *stack, int max)
{
	static int chunk_min = 0;
	static int chunk_max = 39;
	int r = 0;

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

	chunk_min += 40;
	chunk_max += 40;
}

// goddam this is now brig bain time
void	do_the_huge(t_stack *stack, int *phony)
{
	int chunks = 0;
	int *tmp;
	int max = INT_MIN;
	int r = 0;

	tmp = array_dup(stack->a, stack->len_a);
	free (stack->a);
	stack->a = get_abstract(tmp, phony, stack->len_a);
	free (tmp);
	max = get_max(stack->a, stack->len_a);
	chunks = stack->len_a / 10 + 1;
	while (chunks > 0)
	{
		do_the_chunk(stack, max);
		chunks--;
	}
	push_b(stack, 0);


	// numbers inside stack b are divided by chunks, but the chunks are not ordered within itself
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

			push_a(stack, 0);
		// print_stacks(stack);




}