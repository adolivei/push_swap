#include "../../includes/push_swap.h"

// rra : reverse rotate a - shift down all elements of stack a by 1.
// The last element becomes the first one.
void	reverse_a(t_stack *stack)
{
	int tmp;
	int len = 0;

	len = stack->len_a;
	tmp = stack->a[len - 1];
	while (len-- > 0)
		stack->a[len] = stack->a[len - 1];
	stack->a[0] = tmp;
	// printf("i: %d, a[i]: %d, a[i - 1]: %d\n", i, stack->a[i], stack->a[i + 1]);
	// printf("tmp: %d\n", stack->a[tmp]);
}


// rrb : reverse rotate b - shift down all elements of stack b by 1.
// The flast element becomes the first one.
void	reverse_b(t_stack *stack)
{
	int tmp;
	int len = 0;

	len = stack->len_b;
	tmp = stack->b[len - 1];
	while (len-- > 0)
		stack->b[len] = stack->b[len - 1];
	stack->b[0] = tmp;

}

// rrr : rra and rrb at the same time.
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
			print_stacks(stack);
}