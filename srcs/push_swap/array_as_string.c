#include "../../includes/push_swap.h"

int	first_is_nb(char a, char b)
{
	if (ft_isdigit(a) || (a == '-' && ft_isdigit(b)) || (a == '+' && ft_isdigit(b)))
		return (1);
	return (0);
}

// this is the counter for get_stack_len
// each time theres a space with a nb in front of it we'll len++
int	n_is_nb(char a, char b, char c)
{
	if (a == ' ' && (ft_isdigit(b) || b == '-' && ft_isdigit(c) || b == '+' && ft_isdigit(c)))
		return (1);
	return (0);

}

int	invalid_char(char c)
{
	if (!ft_isdigit(c) && c != ' ' && c != '-' && c != '+')
		return (1);
	return (0);
}

// the sting can only have numbers or space as characters
// if it has anything else, it will print error
int get_stack_len(char *s)
{
	int len = 0;
	int i = 0;

	if (first_is_nb(s[0], s[1]))
		len++;

	while (s[i])
	{
		if (invalid_char(s[i]))
		{
			write(1, "Erorr\n", 6);
			return (0);
		}
		if (n_is_nb(s[i], s[i + 1], s[i + 2]))
			len++;
		i++;
	}
	return (len);
}

int	*get_stack(char *s, int len)
{
	int array_i = 0;
	int string_i = 0;
	int *array = NULL;

	array = (int *)malloc(sizeof(int) * len);
	if (!array)
		return (NULL);
	if (first_is_nb(s[0], s[1]))
	{
		array[array_i] = ft_atoi(&s[string_i]);
		array_i++;
		string_i++;
	}
	while (s[string_i])
	{
		if (n_is_nb(s[string_i], s[string_i + 1], s[string_i + 2]))
		{
			if (ft_atol(&s[string_i + 1]) < INT_MIN || ft_atol(&s[string_i + 1]) > INT_MAX)
			{
				free (array);
				return (NULL);
			}
			array[array_i] = ft_atoi(&s[string_i + 1]);
			array_i++;
		}
		string_i++;
	}
	return (array);
}

int look4error(int *array, int len)
{
	int i = 0;

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
	t_stack stack;
	int i = 0;

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