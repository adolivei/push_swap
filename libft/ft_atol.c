#include "libft.h"

long	ft_atol(const char *str)
{
	long	res;
	int		neg;

	res = 0;
	neg = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res += *str - 48;
		str++;
	}
	return (res * neg);
}
