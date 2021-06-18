#include "../../includes/push_swap.h"

void	condition_one(t_stack *stack)
{
	reverse_ab(stack, 1, 0, 0);
	if (stack->b[0] < stack->b[1])
		swap_ab(stack, 1, 1, 0);
	else
		swap_ab(stack, 1, 0, 0);
}

void	condition_two(t_stack *stack)
{
	if (stack->b[0] < stack->b[1])
		swap_ab(stack, 1, 1, 0);
	else
		swap_ab(stack, 1, 0, 0);
}

void	condition_three(t_stack *stack)
{
	if (stack->b[0] < stack->b[1])
		swap_ab(stack, 1, 1, 0);
	else
		swap_ab(stack, 1, 0, 0);
	reverse_ab(stack, 1, 0, 0);
}

void	do_the_three(t_stack *stack)
{
	int	min;
	int	min_i;

	min_i = 0;
	min = get_min(stack->a, stack->len_a);
	while (stack->a[min_i] != min)
		min_i++;
	if (min_i == 0 && stack->a[1] > stack->a[2])
		condition_one(stack);
	else if (min_i == 1 && stack->a[0] > stack->a[2])
		rotate_rr(stack, 1, 0, 0);
	else if (min_i == 1 && stack->a[0] < stack->a[2])
		condition_two(stack);
	else if (min_i == 2 && stack->a[0] > stack->a[1])
		condition_three(stack);
	else if (min_i == 2 && stack->a[0] < stack->a[1])
		reverse_ab(stack, 1, 0, 0);
}
