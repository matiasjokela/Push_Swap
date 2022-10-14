/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:57:26 by mjokela           #+#    #+#             */
/*   Updated: 2022/07/19 16:57:31 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*	Do nothing if stack a is already sorted. If not then set segment count
	based on the amount of numbers to be sorted. If this is less than 60,
	use a separate sort_small algorithm. Otherwise get and push segments
	to stack b based on segment count. After this sort the remaining
	three numbers in stack a and store minimum value from stack b.
	Use minimax to push either smallest or largest number from stack b to
	stack a depending on which requires fewer moves. Do this until stack b is
	empty. Finally loop stack a so that the smallest value is first */
void	solve_stacks(t_stack **a, t_stack **b, t_psdata *data)
{
	if (is_sorted(*a))
		return ;
	if (data->stack_depth_a < 60)
	{
		get_segments(*a, data, 6);
		sort_small(a, b, data);
		return ;
	}
	if (data->stack_depth_a > 200)
		data->seg_count = 32;
	else
		data->seg_count = 12;
	get_segments(*a, data, data->seg_count);
	push_segments(a, b, data);
	sort_three(a, b, data);
	min_b(*b, data);
	data->global_min = data->min_b;
	while ((*b)->next != NULL)
		minimax(a, b, data);
	while ((*a)->value != data->global_min)
		rra(a, b, data, 1);
}

/*	Rotate stack b until max value is found. Use the direction that
	requires fewer moves. Push that value to stack a. If second highest
	value is found on the way to highest value, push that too and then 
	swap them in stack a after pushing the highest value */
void	push_max_b(t_stack **a, t_stack **b, t_psdata *data)
{
	max_b((*b), data);
	data->rot_dir = 1;
	data->rot_needed = data->d_to_max_b;
	if (data->stack_depth_b - data->d_to_max_b < data->rot_needed)
		data->rot_dir = 2;
	while ((*b)->value != data->max_b)
	{
		if ((*b)->value == data->sec_max_b)
			pa(a, b, data, 1);
		else if (data->rot_dir == 1)
			rb(a, b, data, 1);
		else
			rrb(a, b, data, 1);
	}
	pa(a, b, data, 1);
	if ((*a)->value > (*a)->next->value)
		sa(*a, *b, data, 1);
}

/*	Determine whether it is optimal to push min or max value and the 
	direction stack b should rotated. Dispatch to push_min or push_max
	based on that information */
void	push_next(t_stack **a, t_stack **b, t_psdata *data)
{
	data->rot_dir = 1;
	data->rot_needed = data->d_to_min_b;
	data->min_or_max = 'm';
	if (data->stack_depth_b - data->d_to_min_b < data->rot_needed)
	{
		data->rot_dir = 2;
		data->rot_needed = data->stack_depth_b - data->d_to_min_b;
	}
	if (data->d_to_max_b < data->rot_needed)
	{
		data->rot_dir = 1;
		data->rot_needed = data->d_to_max_b;
		data->min_or_max = 'M';
	}
	if (data->stack_depth_b - data->d_to_max_b < data->rot_needed)
	{
		data->rot_dir = 2;
		data->min_or_max = 'M';
	}
	if (data->min_or_max == 'm')
		push_min(a, b, data);
	else
		push_max(a, b, data);
}

/*	Rotate stack b until min value is found. Use the direction that
	requires fewer moves. Push that value to stack a. If second lowest
	value is found on the way to lowest value, push that too. Rotate values
	to the bottom of stack a */
void	push_min(t_stack **a, t_stack **b, t_psdata *data)
{
	int	pushed_sec;

	pushed_sec = 0;
	while ((*b)->value != data->min_b)
	{
		if ((*b)->value == data->sec_min_b)
		{
			pa(a, b, data, 1);
			pushed_sec = 1;
		}
		else if (data->rot_dir == 1)
			rb(a, b, data, 1);
		else
			rrb(a, b, data, 1);
	}
	pa(a, b, data, 1);
	if (pushed_sec == 1)
		ra(a, b, data, 1);
	ra(a, b, data, 1);
}

/*	Rotate stack b until max value is found. Use the direction that
	requires fewer moves. Push that value to stack a. If second highest
	value is found on the way to highest value, push that too and then 
	swap them in stack a after pushing the highest value */
void	push_max(t_stack **a, t_stack **b, t_psdata *data)
{
	while ((*b)->value != data->max_b)
	{
		if ((*b)->value == data->sec_max_b)
			pa(a, b, data, 1);
		else if (data->rot_dir == 1)
			rb(a, b, data, 1);
		else
			rrb(a, b, data, 1);
	}
	pa(a, b, data, 1);
	if ((*a)->value > (*a)->next->value)
		sa(*a, *b, data, 1);
}
