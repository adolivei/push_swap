#include "../includes/push_swap.h"

int main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	int len = 0;
	int    *a;
	// int    *b;

	// a = (char *)malloc(sizeof(char) * )

	if (argc > 2)
	{
		while (++i < argc)
		{
			len += ft_strlen(argv[i]);
			printf("len: %d\n", len);
		}
		a = (int *)malloc(sizeof(int) * len + 1);
		i = 0;
		while (++i < argc)
		{
			a[j++] = ft_atoi(argv[i]); 
		}
		a[j] = '\0';
		i = 0;
		while (a[i])
		{
			ft_putnbr_fd(a[i], 1);
			i++;
		}
	}
	return (0);
}