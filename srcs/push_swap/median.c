#include "../../includes/push_swap.h"

int	*bubble_sort(int *array, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	j = 0;
	tmp = 0;
	while (i < len)
	{
		if (array[j] > array[i])
		{
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
		}
		i++;
		j++;
	}
	if (not_in_order(array, len))
		bubble_sort(array, len);
	return (array);
}

int	seek_median(int *array, int len)
{
	int	i;
	int	half;

	i = 0;
	half = len / 2;
	while (i < half)
		i++;
	return (array[i]);
}

int	get_median(int *array, int len)
{
	int	mdn;

	array = bubble_sort(array, len);
	mdn = seek_median(array, len);
	return (mdn);
}
