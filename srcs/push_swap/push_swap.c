#include "../../includes/push_swap.h"

int main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	t_stack stack;
	int mdn;
	int	*phony;

	phony = (int *)malloc(sizeof(int) * (argc - 1));
	// stack.a = (int *)malloc(sizeof(int) * (argc - 1));
	// stack.b = (int *)malloc(sizeof(int) * (argc - 1));
	// stack.len_a = argc - 1;
	// stack.len_b = 0;
	init_stack(&stack, argc - 1);

	if (argc > 2)
	{
		while (++i < argc)
		{
			if (check_errors(argv[i]))
			{
				free(phony);
				free(stack.a);
				free(stack.b);
				return (0);
			}
			stack.a[j] = ft_atoi(argv[i]);
			phony[j] = ft_atoi(argv[i]);
			j++;
		}
		if (is_repeated(phony, stack.len_a))
		{
			ft_putstr_fd("Error #3\n", 1);
			free(phony);
			free(stack.a);
			free(stack.b);
			return (0);
		}
		mdn = get_median(phony, stack.len_a);
		free(phony);
		organize_stacks(&stack, mdn);
	}
	free(stack.a);
	free(stack.b);
	return (0);
}
