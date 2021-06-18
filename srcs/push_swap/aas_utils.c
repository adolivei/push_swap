#include "../../includes/push_swap.h"

int	first_is_nb(char a, char b)
{
	if (ft_isdigit(a) || (a == '-' && ft_isdigit(b))
		|| (a == '+' && ft_isdigit(b)))
		return (1);
	return (0);
}

int	n_is_nb(char a, char b, char c)
{
	if (a == ' ' && (ft_isdigit(b) || (b == '-' && ft_isdigit(c))
			|| (b == '+' && ft_isdigit(c))))
		return (1);
	return (0);
}

int	invalid_char(char c)
{
	if (!ft_isdigit(c) && c != ' ' && c != '-' && c != '+')
		return (1);
	return (0);
}

int	get_stack_len(char *s)
{
	int	len;
	int	i;

	len = 0;
	if (first_is_nb(s[0], s[1]))
		len++;
	i = 0;
	while (s[i])
	{
		if (invalid_char(s[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (n_is_nb(s[i], s[i + 1], s[i + 2]))
			len++;
		i++;
	}
	return (len);
}

int	do_your_shit(char *s, int string_i, int *array, int array_i)
{
	while (s[string_i])
	{
		if (n_is_nb(s[string_i], s[string_i + 1], s[string_i + 2]))
		{
			if (ft_atol(&s[string_i + 1]) < INT_MIN || ft_atol(&s[string_i + 1]) > INT_MAX)
			{
				free (array);
				return (1);
			}
			array[array_i] = ft_atoi(&s[string_i + 1]);
			array_i++;
		}
		string_i++;
	}
	return (0);
}

int	*get_stack(char *s, int len)
{
	int	array_i;
	int	string_i;
	int	*array;

	array = (int *)malloc(sizeof(int) * len);
	if (!array)
		return (NULL);
	array_i = 0;
	string_i = 0;
	if (first_is_nb(s[0], s[1]))
	{
		array[array_i] = ft_atoi(&s[string_i]);
		array_i++;
		string_i++;
	}
	if (do_your_shit(s, string_i, array, array_i))
		return (NULL);
	return (array);
}


// while (s[string_i])
// {
// 	if (n_is_nb(s[string_i], s[string_i + 1], s[string_i + 2]))
// 	{
// 		if (ft_atol(&s[string_i + 1]) < INT_MIN || ft_atol(&s[string_i + 1]) > INT_MAX)
// 		{
// 			free (array);
// 			return (NULL);
// 		}
// 		array[array_i] = ft_atoi(&s[string_i + 1]);
// 		array_i++;
// 	}
// 	string_i++;
// }