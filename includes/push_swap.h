/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:07:25 by mjokela           #+#    #+#             */
/*   Updated: 2022/06/15 18:08:04 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include ".././libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct s_psdata
{
	int	v_flag;
	int	c_flag;
	int	stack_depth_a;
	int	stack_depth_b;
}		t_psdata;

void		print_error(void);
void		init_data(t_psdata *data);
t_stack		*new_node(int nbr);
void		read_input(t_stack *stack_a, int argc, char **argv, t_psdata *data);
void		check_flags(char **argv, t_psdata *data, int *i);
void		read_values(t_stack **stack_a, char *str, t_psdata *data);
long long	ps_atoi(char *str, int *i);
void		print_stacks(t_stack *a, t_stack *b);
void		swap(t_stack *stack);
void		push(t_stack **src, t_stack **dst);
void		rotate(t_stack **stack);
void		rev_rotate(t_stack **stack);
void		solve_stacks(t_stack **a, t_stack **b, t_psdata *data);
int			is_sorted(t_stack *a, t_stack *b);
int			find_min(t_stack *a);


#endif
