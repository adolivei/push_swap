#include "../../includes/push_swap.h"

void	rotate_a(t_stack *stack)
{
	int	tmp;
	int	i;
	int	len;

	i = -1;
	len = stack->len_a;
	tmp = stack->a[0];
	while (i++ < len - 1)
		stack->a[i] = stack->a[i + 1];
	stack->a[len - 1] = tmp;
}

void	rotate_b(t_stack *stack)
{
	int	tmp;
	int	i;
	int	len;

	i = -1;
	len = stack->len_b;
	tmp = stack->b[0];
	while (i++ < len - 1)
		stack->b[i] = stack->b[i + 1];
	stack->b[len - 1] = tmp;
}

void	rotate_rr(t_stack *stack, int a, int b, int c)
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
		rotate_a(stack);
	if (b)
		rotate_b(stack);
	if (!c)
	{
		if (a && b)
			ft_putstr_fd("rr\n", 1);
		else if (a && !b)
			ft_putstr_fd("ra\n", 1);
		else if (!a && b)
			ft_putstr_fd("rb\n", 1);
	}
}
