

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
		seg_count = 16;
	else
		seg_count = 8;
	get_segments(*a, data, seg_count);
	push_segments(a, b, data, seg_count);
	sort_three(a, b, data);

	// print_stacks(*a, *b);
	// ft_printf("move count: %d\n", data->move_count);
	// exit(0);
	min_b(*b, data);
	data->global_min = data->min_b;
	//ft_printf("%-31s %d\n", "move count after push_segments:", data->move_count);

	while ((*b)->next != NULL)
		minimax(a, b, data);
	while ((*a)->value != data->global_min)
		rra(a, b, data, 1);
	
	//ft_printf("%-31s %d\n", "final move count:", data->move_count);

}



int	is_sorted(t_stack *stack)
{
	int	tmp;

	while (stack->next->next != NULL)
	{
		tmp = stack->value;
		stack = stack->next;
		if (tmp > stack->value)
			return (0);
	}
	return (1);
}

void	min_b(t_stack *b, t_psdata *data)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = b;
	data->min_b = b->value;
	data->sec_min_b = 2147483647;
	data->d_to_min_b = data->stack_depth_b;
	while (b->next != NULL)
	{
		if (b->value < data->min_b)
		{
			data->min_b = b->value;
			data->d_to_min_b = i;
		}
		b = b->next;
		i++;
	}
	while (tmp->next != NULL)
	{
		if (tmp->value < data->sec_min_b && tmp->value != data->min_b)
			data->sec_min_b = tmp->value;
		tmp = tmp->next;
	}
}

void	max_b(t_stack *b, t_psdata *data)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = b;
	data->max_b = b->value;
	data->sec_max_b = -2147483648;
	data->d_to_max_b = data->stack_depth_b;
	while (b->next != NULL)
	{
		if (b->value > data->max_b)
		{
			data->max_b = b->value;
			data->d_to_max_b = i;
		}
		b = b->next;
		i++;
	}
	while (tmp->next != NULL)
	{
		if (tmp->value > data->sec_max_b && tmp->value != data->max_b)
			data->sec_max_b = tmp->value;
		tmp = tmp->next;
	}
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
		// visualize(*a, *b, data);
		// sleep(1);
		if ((*b)->value == data->sec_max_b)
			pa(a, b, data, 1);
		else if (data->rot_dir == 1)
			rb(a, b, data, 1);
		else
			rrb(a, b, data, 1);
	}
	// int	prev_seg = (*a)->segment;
	pa(a, b, data, 1);
	if ((*a)->value > (*a)->next->value)
		sa(*a, *b, data, 1);
	// if ((*a)->segment != prev_seg)
	// 	ft_printf("move count after segment %d:     %d\n", prev_seg, data->move_count);
}


void	minimax(t_stack **a, t_stack **b, t_psdata *data)
{
	min_b(*b, data);
	max_b(*b, data);
	push_next(a, b, data);
}



void	bubble_sort(t_stack **a, t_stack **b, t_psdata *data)
{
	int	i;

	i = 0;
	while (is_sorted(*a) == 0)
	{
		if ((*a)->value > (*a)->next->value)
			sa((*a), (*b), data, 1);
		ra(a, b, data, 1);
		i++;
		if (i == data->stack_depth_a - 1)
		{
			ra(a, b, data, 1);
			i = 0;
		}
	}
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
		// visualize(*a, *b, data);
		// sleep(1);
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
	// visualize(*a, *b, data);
	// sleep(1);
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

void	push_segments(t_stack **a, t_stack **b, t_psdata *data, int sc)
{
	int	i;
	int	j;
	// int	min_seg;
	// int	max_seg;
	// int	mid_seg;
	(void)sc;

	i = 0;
	j = data->stack_depth_a;
	// mid_seg = sc / 2;
	// min_seg = (mid_seg - 2);
	// max_seg = (mid_seg + 3);
	while (i++ < j)
	{
		if ((*a)->segment >= 7 && (*a)->segment <= 10)
		{
			pb(a, b, data, 1);
			if ((*b)->segment == 8 || (*b)->segment == 9)
			{
				if ((*a)->segment >= 7 && (*a)->segment <= 10)
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
	i = 0;
	j = data->stack_depth_a;
	while (i++ < j)
	{
		if ((*a)->segment >= 5 && (*a)->segment <= 12)
		{
			pb(a, b, data, 1);
			if ((*b)->segment == 6 || (*b)->segment == 11)
			{
				if ((*a)->segment >= 5 && (*a)->segment <= 12)
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
	i = 0;
	j = data->stack_depth_a;
	while (i++ < j)
	{
		if ((*a)->segment >= 3 && (*a)->segment <= 14)
		{
			pb(a, b, data, 1);
			if ((*b)->segment == 4 || (*b)->segment == 13)
			{
				if ((*a)->segment >= 3 && (*a)->segment <= 14)
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
	i = 0;
	j = data->stack_depth_a;
	while (i++ < j)
	{
		if ((*a)->segment >= 1 && (*a)->segment <= 16)
		{
			pb(a, b, data, 1);
			if ((*b)->segment == 2 || (*b)->segment == 15)
			{
				if ((*a)->segment >= 1 && (*a)->segment <= 16)
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

void	get_segments(t_stack *stack_a, t_psdata *data, int seg_count)
{
	t_stack	*tmp;
	int		min;
	int		marked;
	int		i;
	int		j;

	marked = 0;
	i = 1;
	j = 0;
	while (marked < data->stack_depth_a)
	{
		tmp = stack_a;
		min = 2147483647;
		if (j > data->stack_depth_a / seg_count)
		{
			j = 0;
			i++;
		}
		while (tmp->next != NULL)
		{
			if (tmp->value < min && tmp->segment == -1)
				min = tmp->value;
			tmp = tmp->next;
		}
		tmp = stack_a;
		while (tmp->value != min)
			tmp = tmp->next;
		if (data->stack_depth_a - marked < 4)
			tmp->segment = 0;
		else
			tmp->segment = i;
		marked++;
		j++;

	}
}
