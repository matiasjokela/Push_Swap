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
	int				segment;
	struct s_stack	*next;
}					t_stack;

typedef struct s_psdata
{
	int		v_flag;
	int		c_flag;
	int		stack_depth_a;
	int		stack_depth_b;
	int		min_b;
	int		max_b;
	int		sec_min_b;
	int		sec_max_b;
	int		d_to_min_b;
	int		d_to_max_b;
	int		rot_dir;
	int		rot_needed;
	char	min_or_max;
	int		global_min;
	int		seg_count;
	int		min_seg;
	int		max_seg;
	int		marked;
	int		move_count;
}			t_psdata;

void		print_error(void);
void		init_data(t_psdata *data);
t_stack		*new_node(int nbr);
void		read_input(t_stack *stack_a, int argc, char **argv, t_psdata *data);
void		check_flags(char **argv, t_psdata *data, int *i);
void		read_values(t_stack **stack_a, char *str, t_psdata *data);
long long	ps_atoi(char *str, int *i);
void		check_duplicates(t_stack *a);
void		print_stacks(t_stack *a, t_stack *b);
void		swap(t_stack *stack);
void		push(t_stack **src, t_stack **dst);
void		rotate(t_stack **stack);
void		rev_rotate(t_stack **stack);
void		solve_stacks(t_stack **a, t_stack **b, t_psdata *data);
int			is_sorted(t_stack *stack);
void		min_b(t_stack *b, t_psdata *data);
void		max_b(t_stack *a, t_psdata *data);
void		minimax(t_stack **a, t_stack **b, t_psdata *data);
void		sa(t_stack *a, t_stack *b, t_psdata *data, int print);
void		sb(t_stack *a, t_stack *b, t_psdata *data, int print);
void		ss(t_stack *a, t_stack *b, t_psdata *data, int print);
void		pa(t_stack **a, t_stack **b, t_psdata *data, int print);
void		pb(t_stack **a, t_stack **b, t_psdata *data, int print);
void		ra(t_stack **a, t_stack **b, t_psdata *data, int print);
void		rb(t_stack **a, t_stack **b, t_psdata *data, int print);
void		rr(t_stack **a, t_stack **b, t_psdata *data, int print);
void		rra(t_stack **a, t_stack **b, t_psdata *data, int print);
void		rrb(t_stack **a, t_stack **b, t_psdata *data, int print);
void		rrr(t_stack **a, t_stack **b, t_psdata *data, int print);
void		push_next(t_stack **a, t_stack **b, t_psdata *data);
void		push_min(t_stack **a, t_stack **b, t_psdata *data);
void		push_max(t_stack **a, t_stack **b, t_psdata *data);
void		get_segments(t_stack *stack_a, t_psdata *data, int seg_count);
void		push_segments(t_stack **a, t_stack **b, t_psdata *data);
void		push_max_b(t_stack **a, t_stack **b, t_psdata *data);
void		sort_small(t_stack **a, t_stack **b, t_psdata *data);
void		get_values(t_stack *a, int *min, int *mid, int *max);
void		sort_three(t_stack **a, t_stack **b, t_psdata *data);
void		visualize(t_stack *a, t_stack *b, t_psdata *data);
void		execute_commands(t_stack **a, t_stack **b, t_psdata *data);
void		print_colours(t_stack *a, t_stack *b, t_psdata *data, char *cmd);
void		check_line(t_stack **a, t_stack **b, t_psdata *data, char *line);
void		push_next_segments(t_stack **a, t_stack **b, t_psdata *data, int j);
int			get_next_min(t_stack *tmp);

#endif
