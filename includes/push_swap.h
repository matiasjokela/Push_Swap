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

typedef struct s_flags
{
	int		v_flag;
	int		c_flag;
}					t_flags;

void		print_error(void);
void		init_flags(t_flags *flags);
t_stack		*new_node(int nbr);
void		read_input(t_stack *stack_a, int argc, char **argv, t_flags *flags);
void		check_flags(char **argv, t_flags *flags, int *i);
void		read_values(t_stack **stack_a, char *str);
long long	ps_atoi(char *str, int *i);
void		print_stacks(t_stack *a, t_stack *b);
void		swap(t_stack *stack);
void		push(t_stack **src, t_stack **dst);
void		rotate(t_stack **stack);
void		rev_rotate(t_stack **stack);


#endif
