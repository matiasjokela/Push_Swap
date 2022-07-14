

#include "../includes/push_swap.h"

void	solve_stacks(t_stack **a, t_stack **b, t_psdata *data)
{
	int	seg_count;

	if (is_sorted(*a))
		return ;
	if (data->stack_depth_a < 60)
	{
		get_segments(*a, data, 6);
		sort_small(a, b, data);
		return ;
	}
	if (data->stack_depth_a > 200)
		seg_count = 32;
	else
		seg_count = 12;
	get_segments(*a, data, seg_count);
	push_segments(a, b, data, seg_count);
	sort_three(a, b, data);
	min_b(*b, data);
	data->global_min = data->min_b;
	while ((*b)->next != NULL)
		minimax(a, b, data);
	while ((*a)->value != data->global_min)
		rra(a, b, data, 1);
}

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

