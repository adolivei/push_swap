#include "../../includes/push_swap.h"

int	organize_stacks(t_stack *stack)
{
	int	mdn;
	int	*tmp;
	int	*phony;

	if (not_in_order(stack->a, stack->len_a))
	{
		phony = array_dup(stack->a, stack->len_a);
		bubble_sort(phony, stack->len_a);
		tmp = array_dup(stack->a, stack->len_a);
		free (stack->a);
		stack->a = get_abstract(tmp, phony, stack->len_a);
		free (tmp);
		free (phony);
		phony = array_dup(stack->a, stack->len_a);
		bubble_sort(phony, stack->len_a);
		mdn = get_median(phony, stack->len_a);
		free (phony);
		if (stack->len_a == 3)
			do_the_three(stack);
		else if (stack->len_a <= 5)
			do_the_five(stack, mdn);
		else
			do_the_huge(stack);
	}
	return (0);
}
