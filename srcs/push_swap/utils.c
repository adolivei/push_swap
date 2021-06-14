#include "../../includes/push_swap.h"

void	init_stack(t_stack *stack, int len)
{
	stack->a = (int *)malloc(sizeof(int) * len);
	stack->b = (int *)malloc(sizeof(int) * len);
	stack->len_a = len;
	stack->len_b = 0;
}

// returns 0 if the array it's in order 
// 1 otherwise
int		not_in_order(int *array, int len)
{
	int i = 0;
	int j = 0;
	int *ar;

	ar = array;
	while (i < len - 1)
	{
		if (ar[i] > ar[i + 1])
			j = 1;
		i++;
	}
	return (j);
}

// returns 0 if stack b is empty
// 1 otherwise
int		not_empty(int *array, int len)
{
	int i = 0;
	int j = 0;
	int *ar;

	ar = array;
	while (i < len)
	{
		if (ar[i] != 0)
			j = 1;
		i++;
	}
	return (j);
}

// returns 1 if one of the elements in the array is bigger than nb
// 0 otherwise
int		smaller_exists(int *array, int len, int nb)
{
	int i = 0;
	int j = 0;
	int *ar;

	ar = array;
	while (i < len - 1)
	{
		if (ar[i] <= nb)
			j = 1;
		i++;
	}
	return (j);
}

// returns 1 if one of the elements in the array is bigger than nb
// 0 otherwise
int		bigger_exists(int *array, int len, int nb)
{
	int i = 0;
	int j = 0;
	int *ar;

	ar = array;
	while (i < len)
	{
		if (ar[i] >= nb)
			j = 1;
		i++;
	}
	return (j);
}



int		get_min(int *array, int len)
{
	int min = INT_MAX;
	int i = 0;

	min = array[0];
	while (i++ < len - 1)
	{
		if (array[i] < min)
			min = array[i];
	}
	return (min);
}

int		get_max(int *array, int len)
{
	int max = INT_MIN;
	int i = 0;

	max = array[0];
	while (i++ < len - 1)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

int		get_tb(int *array, int len)
{
	int tb = INT_MIN;
	int i = 0;
	int max = get_max(array, len);
	int sb = INT_MIN;

	while (i < len - 1)
	{
		if (sb < array[i] && array[i] < max)
			sb = array[i];
		i++;
	}
	// printf("%d\n", max);
	// printf("%d\n", sb);
	i = 0;
	while (i < len - 1)
	{
		if (tb < array[i] && array[i] < sb)
			tb = array[i];
		i++;
	}
	// printf("%d\n", tb);

	return (tb);
}