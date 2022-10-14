/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:57:10 by mjokela           #+#    #+#             */
/*   Updated: 2022/07/19 16:57:15 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*	Loop through stack a until all nodes have a segment assigned to them.
	On each iteration find the smallest value with no segment assigned
	and assign it based on segment count and how many numbers have 
	already been assigned to current segment */
void	get_segments(t_stack *stack_a, t_psdata *data, int seg_count)
{
	t_stack	*tmp;
	int		min;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (data->marked < data->stack_depth_a)
	{
		if (j > data->stack_depth_a / seg_count)
		{
			j = 0;
			i++;
		}
		tmp = stack_a;
		min = get_next_min(tmp);
		while (tmp->value != min)
			tmp = tmp->next;
		if (data->stack_depth_a - data->marked < 4)
			tmp->segment = 0;
		else
			tmp->segment = i;
		data->marked += 1;
		j++;
	}
}

/* Get smallest value with unassigned segment from stack */
int	get_next_min(t_stack *tmp)
{
	int	min;

	min = 2147483647;
	while (tmp->next != NULL)
	{
		if (tmp->value < min && tmp->segment == -1)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

/*	Push four segments at a time from stack a to stack b starting from
	the middle segments. Do this until all segments over 0 are pushed.
	Segment 0 is for the three largest values, which are left in stack a */
void	push_segments(t_stack **a, t_stack **b, t_psdata *data)
{
	data->min_seg = ((data->seg_count / 2) - 1);
	data->max_seg = ((data->seg_count / 2) + 2);
	while (data->min_seg > 0)
	{
		push_next_segments(a, b, data, data->stack_depth_a);
		data->min_seg -= 2;
		data->max_seg += 2;
	}
}

/*	Loop through stack a once and push to stack b all nodes whose segment
	is between min_seg and max_seg inclusive. Leave min_seg and max_seg
	on top of stack b and rotate the other two to the bottom */
void	push_next_segments(t_stack **a, t_stack **b, t_psdata *data, int j)
{
	int	i;

	i = 0;
	while (i++ < j)
	{
		if ((*a)->segment >= data->min_seg && (*a)->segment <= data->max_seg)
		{
			pb(a, b, data, 1);
			if ((*b)->segment == (data->min_seg + 1) || \
			(*b)->segment == (data->max_seg - 1))
			{
				if ((*a)->segment >= data->min_seg && \
				(*a)->segment <= data->max_seg)
					rb(a, b, data, 1);
				else
				{
					rr(a, b, data, 1);
					i++;
				}
			}
		}
		else
			ra(a, b, data, 1);
	}
}
