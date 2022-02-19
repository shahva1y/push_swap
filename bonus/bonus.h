#ifndef BONUS_H
# define BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../push_swap.h"
# include "../libft/libft.h"

void	ft_execute_commands(t_stack **stack_a, t_stack **stack_b);

void	ft_p_stack(t_stack **src, t_stack **dst);
void	ft_r_stack(t_stack **stack);
void	ft_rr_stack(t_stack **stack);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_s_stack(t_stack *stack);
void	ft_ss(t_stack **a, t_stack **b);

#endif