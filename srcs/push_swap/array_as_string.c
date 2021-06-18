#include "../../includes/push_swap.h"

int	look4error(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (is_repeated(array, len))
			return (1);
		i++;
	}
	return (0);
}

int	string_to_array(char *s)
{
	t_stack	stack;
	int		i;

	i = 0;
	stack.len_a = get_stack_len(s);
	init_stack(&stack, stack.len_a);
	free(stack.a);
	stack.a = get_stack(s, stack.len_a);
	if (!stack.a)
	{
		ft_putstr_fd("error", 1);
		return (0);
	}
	else if (look4error(stack.a, stack.len_a))
	{
		ft_putstr_fd("error", 1);
		return (0);
	}
	organize_stacks(&stack);
	return (0);
}
