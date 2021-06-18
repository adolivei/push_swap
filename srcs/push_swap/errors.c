#include "../../includes/push_swap.h"

int	is_repeated(int *array, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_not_nb(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9'))
			return (1);
		i++;
	}
	return (0);
}

int	error_list(char *array)
{
	int	i;

	i = 0;
	if (ft_atol((const char *)array) < INT_MIN
		|| ft_atol((const char *)array) > INT_MAX)
		return (1);
	if (is_not_nb(array))
		return (1);
	return (0);
}

int	check_errors(char *array)
{
	int	error;

	error = error_list(array);
	if (error)
		write(2, "Error\n", 6);
	return (error);
}
