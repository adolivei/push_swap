#include "../../includes/push_swap.h"

int	r_or_rr(int *array, int len, int nb)
{
	int	r;
	int	rr;

	rr = len - 1;
	r = 0;
	while (array[r] != nb)
		r++;
	while (array[rr] != nb)
		rr--;
	rr = len - rr;
	if (r > rr)
		return (0);
	else
		return (1);
}

int	r_or_rr_lol(int *array, int len, int nb)
{
	int	r;
	int	rr;

	rr = len - 1;
	r = 0;
	while (array[r] > nb)
		r++;
	while (array[rr] > nb)
		rr--;
	rr = len - rr;
	if (r > rr)
		return (0);
	else
		return (1);
}
