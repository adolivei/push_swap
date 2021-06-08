#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>
#include <limits.h>

//// very important
// numbergenerator.org/randomnumbergenerator

typedef struct  s_stack
{
	int *a;
	int *b;
	int len_a;
	int len_b;
}               t_stack;

// flags a to d are the several options that may occur
// option a is for ra + rb
// option b is for rra + rrb
// option c is for ra + rrb
// option d is for rra + rb
typedef struct	s_flags
{
	int nra;
	int nrb;
	int nrra;
	int nrrb;
	int a;
	int b;
	int c;
	int d;

}				t_flags;

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
void    organize_stacks(t_stack *stack, int mdn, int tb);
void    do_the_hundred(t_stack *stack, int mdn, int tb);
void	do_the_three(t_stack *stack);

//// decisions
int		r_or_rr(int *array, int len, int nb);
int		r_or_rr_lol(int *array, int len, int nb);
int		r_or_rr_push(int *array, int len, int nb);
int		get_rrr(int *array, int len, int nb, int r);
// int		get_rrr_push(int *array, int len, int nb);
void	decision_rrr(t_stack *stack, int mdn);

///// utils
void	init_stack(t_stack *stack, int len);
int		not_in_order(int *array, int len);
int		not_empty(int *array, int len);
int		smaller_exists(int *array, int len, int nb);
int		get_min(int *array, int len);
int		get_max(int *array, int len);
int		get_tb(int *array, int len); // third bigger nb of the stack

//// debug
void	print_stacks(t_stack *stack);
void	print_array(int *array, int len);



#endif