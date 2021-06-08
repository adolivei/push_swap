#include "../../includes/push_swap.h"

// pa : push a take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	push_a(t_stack *stack, int c)
{
	int len_a;
	int len_b;
	int i = 0;

		// ft_putstr_fd("push_a\n", 1);

	len_a = stack->len_a;
	len_b = stack->len_b;
	if (len_b)
	{
		while (len_a > 0)
		{
		   stack->a[len_a] = stack->a[len_a - 1];
		   len_a--;
		}
		stack->a[0] = stack->b[0];
		stack->len_a++;
		stack->len_b--;
		while (i < len_b - 1)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		if (!c)
			ft_putstr_fd("pa\n", 1);
		// print_stacks(stack);
	}
}

// pb : pushb- take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	push_b(t_stack *stack, int c)
{
	int len_a;
	int len_b;
	int i = 0;

			// ft_putstr_fd("push_b\n", 1);

	len_a = stack->len_a;
	len_b = stack->len_b;
	if (len_a)
	{
		while (len_b > 0)
		{
		   stack->b[len_b] = stack->b[len_b - 1];
		   len_b--;
		}
		stack->b[0] = stack->a[0];
		stack->len_b++;
		stack->len_a--;
		while (i < len_a - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		if (!c)
			ft_putstr_fd("pb\n", 1);
		// print_stacks(stack);
	}
}
