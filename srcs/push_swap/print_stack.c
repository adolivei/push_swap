#include "../../includes/push_swap.h"

void	print_array(int *array, int len)
{
	int i;
	
	i = 0;
	while (i < len)
	{
		// ft_putnbr_fd(array[i], 1)
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
}

void	print_stacks(t_stack *stack)
{
	printf("A:\n");
	print_array(stack->a, stack->len_a);
	printf("B:\n");
	print_array(stack->b, stack->len_b);
	printf("len_a: %d, len_b: %d\n", stack->len_a, stack->len_b);
}