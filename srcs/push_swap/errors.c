#include "../../includes/push_swap.h"

int		is_repeated(int *array, int len)
{
	int i = 0;
	int j = 0;

	while (i++ < len - 1)
	{
		j = i + 1;
		while (j++ < len - 1)
		{
			if (array[i] == array[j])
				return (1);
		}
	}
	return (0);
}

int is_not_nb(char *s)
{
	int i = 0;

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

int		error_list(char *array)
{
	int i = 0;

	if (ft_atol((const char *)array) < INT_MIN || ft_atol((const char *)array) > INT_MAX)
	 	return (1);
	if (is_not_nb(array))
		return(2);
	return (0);
}

// checks every element of the str for errors
// if an error is found, "Error" will be written in stdout and the error # will be returned
int     check_errors(char *array)
{
	int error = 0;

	error = error_list(array);
	if (error)
	{
		ft_putstr_fd("Error #", 1);
		ft_putnbr_fd(error, 1);
		ft_putchar_fd('\n', 1);
		// write(2, "Error\n", 6); // 2 is the std error
	}
	return (error);
}

// Errors:
// #1: nb is bigger or smaller than int limits
// #2: one of the arguments isn't a number
// #3: the nb is repeated