#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_stack
{
	unsigned int		value;
	struct s_stack		*up;
	struct s_stack		*down;
	unsigned long long	index;
} t_stack;

typedef	struct s_status
{
	unsigned long long max;
	unsigned long long mid;
	unsigned long long min;
} t_status;

void	ft_push_swap_sort(unsigned int *stack_a, unsigned long long length);
int		ft_is_representable(char *str);

t_stack *create_stack(unsigned int *stack_a, unsigned int length);
void ft_print_stack(t_stack *stack, unsigned int length);
void ft_reverse_print_stack(t_stack *stack, unsigned int length);

void ft_swap(t_stack *stack, char stack_name);
void ft_both_swap(t_stack **a, t_stack **b);
void ft_rotate(t_stack **stack, char stack_name);
void ft_both_rotate(t_stack **a, t_stack **b);
void ft_reverse_rotate(t_stack **stack, char stack_name);
void ft_both_reverse_rotate(t_stack **a, t_stack **b);
void ft_push(t_stack **src, t_stack **dst, char dst_name);

unsigned long long	ft_get_stack_length(t_stack *stack);
unsigned long long ft_find_lis(t_stack **stack);

void ft_stack_sort(t_stack **stack, char stack_name);
void ft_stack_reverse_sort(t_stack **stack, char stack_name);

//sorts algo
void	ft_quick_sort(t_stack **stack_a, t_stack **stack_b, t_status *status);
void	ft_merge_sort(t_stack **stack_a, t_stack **stack_b, t_status *status);

//parse_utils
int	ft_duplicate_exist(int *tmp, unsigned int length);
void	ft_index(int *tmp, unsigned int *stack, unsigned int length);

void	ft_increase_index(t_stack *stack);
void	ft_index_insert_sort(t_stack **src, t_stack **dst, char stack_name, t_status *status);
void	ft_status_update(t_stack **stack, t_status *status);

//quick_sort_utils.c
t_stack	*ft_last_less_element(t_stack **stack, t_status *status);
t_stack	*ft_last_greater_element(t_stack **stack, t_status *status);
t_stack *ft_push_less(t_stack **stack_src, t_stack **stack_dst, t_status *status);
void ft_push_greater(t_stack **stack_src, t_stack **stack_dst, t_status *status);

#endif //PUSH_SWAP_H