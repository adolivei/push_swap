#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>
#include <limits.h>

typedef struct  s_stack
{
	int *a;
	int *b;
	int len_a;
	int len_b;
}               t_stack;

//// swaps
void    swap_ab(t_stack *stack, int a, int b, int c);

//// pushes
void	push_a(t_stack *stack, int c);
void	push_b(t_stack *stack, int c);

//// rotate
void	rotate_rr(t_stack *stack, int a, int b, int c);

//// reverse
void	reverse_ab(t_stack *stack, int a, int b, int c);

//// error
int     check_errors(char *array);
int		is_repeated(int *array, int len);

//// median
int		get_median(int *array, int len);
// int		*bubble_sort(int *array, int len);

//// organize_stacks
void    organize_stacks(t_stack *stack, int mdn);

///// utils
void	init_stack(t_stack *stack, int len);
int		not_in_order(int *array, int len);
int		not_empty(int *array, int len);
int		smaller_exists(int *array, int len, int nb);
int		get_min(int *array, int len);
int		get_max(int *array, int len);

//// debug
void	print_stacks(t_stack *stack);
void	print_array(int *array, int len);



#endif