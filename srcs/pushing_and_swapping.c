/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_and_swapping.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:55:53 by mjokela           #+#    #+#             */
/*   Updated: 2022/07/19 16:55:58 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Swap first two elements in stack a */
void	sa(t_stack *a, t_stack *b, t_psdata *data, int print)
{
	swap(a);
	data->move_count++;
	if (print)
		ft_printf("sa\n");
	if (data->v_flag == 1)
		print_stacks(a, b);
	else if (data->c_flag == 1)
		print_colours(a, b, data, "sa");
}

/* Swap first two elements in stack b */
void	sb(t_stack *a, t_stack *b, t_psdata *data, int print)
{
	swap(b);
	data->move_count++;
	if (print)
		ft_printf("sb\n");
	if (data->v_flag == 1)
		print_stacks(a, b);
	else if (data->c_flag == 1)
		print_colours(a, b, data, "sb");
}

/* Swap first two elements in both stacks a and b */
void	ss(t_stack *a, t_stack *b, t_psdata *data, int print)
{
	swap(a);
	swap(b);
	data->move_count++;
	if (print)
		ft_printf("ss\n");
	if (data->v_flag == 1)
		print_stacks(a, b);
	else if (data->c_flag == 1)
		print_colours(a, b, data, "ss");
}

/* Push first element from stack b to stack a */
void	pa(t_stack **a, t_stack **b, t_psdata *data, int print)
{
	push(b, a);
	data->move_count++;
	data->stack_depth_a++;
	data->stack_depth_b--;
	if (print)
		ft_printf("pa\n");
	if (data->v_flag == 1)
		print_stacks((*a), (*b));
	else if (data->c_flag == 1)
		print_colours(*a, *b, data, "pa");
}

/* Push first element from stack a to stack b */
void	pb(t_stack **a, t_stack **b, t_psdata *data, int print)
{
	push(a, b);
	data->move_count++;
	data->stack_depth_a--;
	data->stack_depth_b++;
	if (print)
		ft_printf("pb\n");
	if (data->v_flag == 1)
		print_stacks((*a), (*b));
	else if (data->c_flag == 1)
		print_colours(*a, *b, data, "pb");
}
