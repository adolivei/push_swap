#include "../../includes/push_swap.h"

int	not_in_order(int *array, int len)
{
	int	i;
	int	j;
	int	*ar;

	i = 0;
	j = 0;
	ar = array;
	while (i < len - 1)
	{
		if (ar[i] > ar[i + 1])
			j = 1;
		i++;
	}
	return (j);
}

int	not_empty(int *array, int len)
{
	int	i;
	int	j;
	int	*ar;

	i = 0;
	j = 0;
	ar = array;
	while (i < len)
	{
		if (ar[i] != 0)
			j = 1;
		i++;
	}
	return (j);
}

int	smaller_exists(int *array, int len, int nb)
{
	int	i;
	int	j;
	int	*ar;

	i = 0;
	j = 0;
	ar = array;
	while (i < len - 1)
	{
		if (ar[i] <= nb)
			j = 1;
		i++;
	}
	return (j);
}

int	bigger_exists(int *array, int len, int nb)
{
	int	i;
	int	j;
	int	*ar;

	i = 0;
	j = 0;
	ar = array;
	while (i < len)
	{
		if (ar[i] >= nb)
			j = 1;
		i++;
	}
	return (j);
}
