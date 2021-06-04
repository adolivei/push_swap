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
	printf("\033[0;31m"); // red
	printf("A: ");
	print_array(stack->a, stack->len_a);
	printf("\033[0m"); // reset color
	printf("\033[0;32m"); // green
	printf("B: ");
	print_array(stack->b, stack->len_b);
	printf("\033[0m");
	// printf("\033[0;33m"); // yellow
	// printf("len_a: %d, len_b: %d\n", stack->len_a, stack->len_b);
	printf("_____________________\n");
	// printf("\033[0m");
}