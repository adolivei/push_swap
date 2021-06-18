#include "../../includes/push_swap.h"

int	*array_dup(int *array, int len)
{
	int	i;
	int	*new;

	i = 0;
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

int	get_index_position(int *array, int nb)
{
	int	i;

	i = 0;
	while (array[i] != nb)
		i++;
	return (i);
}

// returns an array of ints which contains the ordered index of each int in real
// if real is [3947, -28, 0, 40], abstract will be [3, 0, 1, 2]
int	*get_abstract(int *real, int *fake, int len)
{
	int	*abstract;
	int	i;

	i = 0;
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

void	init_stack(t_stack *stack, int len)
{
	stack->a = (int *)malloc(sizeof(int) * len);
	stack->b = (int *)malloc(sizeof(int) * len);
	stack->len_a = len;
	stack->len_b = 0;
}

int	free_stacks(t_stack *stack, int w)
{
	if (w)
		write(2, "Error\n", 6);
	free(stack->a);
	free(stack->b);
	return (0);
}
