#include "../../includes/checker.h"

void	apply_orders(t_stack *stack, char *orders)
{
	if (ft_strncmp(orders, "sa", 2) == 0)
	{
		swap_ab(stack, 1, 0, 1);
	}
	else if (ft_strncmp(orders, "sb", 2) == 0)
	{
		swap_ab(stack, 0, 1, 1);
	}
	else if (ft_strncmp(orders, "ss", 2) == 0)
	{
		swap_ab(stack, 1, 1, 1);
	}
	else if (ft_strncmp(orders, "pa", 2) == 0)
	{
		push_a(stack, 1);
	}
	else if (ft_strncmp(orders, "pb", 2) == 0)
	{
		push_b(stack, 1);
	}
	else if (ft_strncmp(orders, "rra", 3) == 0)
	{
		reverse_ab(stack, 1, 0, 1);
	}
	else if (ft_strncmp(orders, "rrb", 3) == 0)
	{
		reverse_ab(stack, 0, 1, 1);
	}
	else if (ft_strncmp(orders, "rrr", 3) == 0)
	{
		reverse_ab(stack, 1, 1, 1);
	}
	else if (ft_strncmp(orders, "ra", 2) == 0)
	{
		rotate_rr(stack, 1, 0, 1);
	}
	else if (ft_strncmp(orders, "rb", 2) == 0)
	{
		rotate_rr(stack, 0, 1, 1);
	}
	else if (ft_strncmp(orders, "rr", 2) == 0)
	{
		rotate_rr(stack, 1, 1, 1);
	}
	else
		write(2, "Error #4\n", 9);
	// printf("%s\n", orders);
}

void	get_orders(t_stack *stack)
{
	char *line = NULL;
	// char *orders = NULL;
	int i = 0;

	while (get_next_line(0, &line))
	{
		// orders = ft_strdup(line);
		apply_orders(stack, line);
	}

	// print_stacks(stack);

	if (not_in_order(stack->a, stack->len_a) || not_empty(stack->b, stack->len_b))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);

	free(line);
}

int	main(int argc, char *argv[])
{
	t_stack stack;
	int i = 0;
	int j = 0;

	// stack.len_a = argc - 1;
	// stack.len_b = 0;
	// stack.a = (int *)malloc(sizeof(int) * stack.len_a);
	// stack.b = (int *)malloc(sizeof(int) * stack.len_a);
	init_stack(&stack, argc - 1);

	if (argc > 1)
	{
		while (++i < argc)
		{
			if (check_errors(argv[i]))
			{
				free(stack.a);
				free(stack.b);
				return (0);
			}
			stack.a[j] = ft_atoi(argv[i]);
			j++;
		}
		if (is_repeated(stack.a, stack.len_a))
		{
			ft_putstr_fd("Error #3\n", 1);
			free(stack.a);
			free(stack.b);
			return (0);
		}
		get_orders(&stack);

		// ft_putstr_fd(*orders.orders, 1);
		// print_array(stack, len);
	}
	free(stack.a);
	free(stack.b);
	return (0);
}