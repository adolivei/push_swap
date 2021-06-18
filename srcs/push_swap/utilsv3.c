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
