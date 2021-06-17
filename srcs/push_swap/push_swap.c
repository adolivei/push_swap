#include "../../includes/push_swap.h"

int main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	t_stack stack;

	// phony = (int *)malloc(sizeof(int) * (argc - 1));
	// stack.a = (int *)malloc(sizeof(int) * (argc - 1));
	// stack.b = (int *)malloc(sizeof(int) * (argc - 1));
	// stack.len_a = argc - 1;
	// stack.len_b = 0;
	// init_stack(&stack, argc - 1);

	// solution for when the function is called though terminal with ARG="3 4 1 5 6"
	// in this case, the array comes together as only one arg
	if (argc == 2)
	{
		string_to_array(argv[1]);
	}
	else if (argc > 2)
	{
		init_stack(&stack, argc - 1);
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
		organize_stacks(&stack);
	}
	// free(phony);
	free(stack.a);
	free(stack.b);
	return (0);
}
