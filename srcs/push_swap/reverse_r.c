#include "../../includes/push_swap.h"

void	reverse_a(t_stack *stack)
{
	int	tmp;
	int	len;

	len = stack->len_a;
	tmp = stack->a[len - 1];
	while (len-- > 0)
		stack->a[len] = stack->a[len - 1];
	stack->a[0] = tmp;
}

void	reverse_b(t_stack *stack)
{
	int	tmp;
	int	len;

	len = stack->len_b;
	tmp = stack->b[len - 1];
	while (len-- > 0)
		stack->b[len] = stack->b[len - 1];
	stack->b[0] = tmp;
}

void	reverse_ab(t_stack *stack, int a, int b, int c)
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
		reverse_a(stack);
	if (b)
		reverse_b(stack);
	if (!c)
	{
		if (a && b)
			ft_putstr_fd("rrr\n", 1);
		else if (a && !b)
			ft_putstr_fd("rra\n", 1);
		else if (!a && b)
			ft_putstr_fd("rrb\n", 1);
	}
}
