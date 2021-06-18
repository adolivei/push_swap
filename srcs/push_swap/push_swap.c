#include "../../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	t_stack	stack;

	i = 0;
	j = 0;
	if (argc == 2)
		string_to_array(argv[1]);
	else if (argc > 2)
	{
		init_stack(&stack, argc - 1);
		while (++i < argc)
		{
			if (check_errors(argv[i]))
				return (free_stacks(&stack, 0));
			stack.a[j] = ft_atoi(argv[i]);
			j++;
		}
		if (is_repeated(stack.a, stack.len_a))
			return (free_stacks(&stack, 1));
		organize_stacks(&stack);
	}
	return (free_stacks(&stack, 0));
}
