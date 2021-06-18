#include "../../includes/checker.h"

void	apply_orders(t_stack *stack, char *orders)
{
	if (ft_strncmp(orders, "sa", 2) == 0)
		swap_ab(stack, 1, 0, 1);
	else if (ft_strncmp(orders, "sb", 2) == 0)
		swap_ab(stack, 0, 1, 1);
	else if (ft_strncmp(orders, "ss", 2) == 0)
		swap_ab(stack, 1, 1, 1);
	else if (ft_strncmp(orders, "pa", 2) == 0)
		push_a(stack, 1);
	else if (ft_strncmp(orders, "pb", 2) == 0)
		push_b(stack, 1);
	else if (ft_strncmp(orders, "rra", 3) == 0)
		reverse_ab(stack, 1, 0, 1);
	else if (ft_strncmp(orders, "rrb", 3) == 0)
		reverse_ab(stack, 0, 1, 1);
	else if (ft_strncmp(orders, "rrr", 3) == 0)
		reverse_ab(stack, 1, 1, 1);
	else if (ft_strncmp(orders, "ra", 2) == 0)
		rotate_rr(stack, 1, 0, 1);
	else if (ft_strncmp(orders, "rb", 2) == 0)
		rotate_rr(stack, 0, 1, 1);
	else if (ft_strncmp(orders, "rr", 2) == 0)
		rotate_rr(stack, 1, 1, 1);
	else
		write(2, "Error\n", 6);
}

void	get_orders(t_stack *stack)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
		apply_orders(stack, line);
	if (not_in_order(stack->a, stack->len_a)
		|| not_empty(stack->b, stack->len_b))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char *argv[])
{
	t_stack	stack;
	int		i;

	i = 0;
	init_stack(&stack, argc - 1);
	if (argc > 2)
	{
		while (++i < argc)
		{
			if (check_errors(argv[i]))
				return (free_stacks(&stack, 0));
			stack.a[i - 1] = ft_atoi(argv[i]);
		}
		if (is_repeated(stack.a, stack.len_a))
		{
			write(2, "Error\n", 6);
			return (free_stacks(&stack, 0));
		}
		get_orders(&stack);
	}
	free_stacks(&stack, 0);
	return (0);
}
