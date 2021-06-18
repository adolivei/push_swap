#include "../../includes/push_swap.h"

void	swap_a(t_stack *stack)
{
	int	tmp;

	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
}

void	swap_b(t_stack *stack)
{
	int	tmp;

	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
}

void	swap_ab(t_stack *stack, int a, int b, int c)
{
	if (a && stack->len_a > 1)
		a = 1;
	else
		a = 0;
	if (b && stack->len_b > 1)
		b = 1;
	else
		b = 0;
	if (a)
		swap_a(stack);
	if (b)
		swap_b(stack);
	if (!c)
	{
		if (a && b)
			ft_putstr_fd("ss\n", 1);
		else if (a && !b)
			ft_putstr_fd("sa\n", 1);
		else if (!a && b)
			ft_putstr_fd("sb\n", 1);
	}
}
