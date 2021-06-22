#include "../../includes/push_swap.h"

int	get_min(int *array, int len)
{
	int	min;
	int	i;

	i = 0;
	min = array[0];
	while (i++ < len - 1)
	{
		if (array[i] < min)
			min = array[i];
	}
	return (min);
}

int	get_max(int *array, int len)
{
	int	max;
	int	i;

	i = 0;
	max = array[0];
	while (i++ < len - 1)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
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
