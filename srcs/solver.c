

#include "../includes/push_swap.h"

void	solve_stacks(t_stack **a, t_stack **b, t_psdata *data)
{

	if (is_sorted(*a))
		return ;
	if (data->stack_depth_a < 6)
	{
		sort_small(a, b, data);
		return ;
	}



	push_segments(a, b, data);
	bubble_sort(a, b, data);

	while ((*b)->next != NULL)
		push_max_b(a, b, data);



	// while ((*b)->next != NULL)
	// 	push_next(a, b, data);
	// while (!(is_sorted(*a)))
	// {
	// 	ra(a, b, data);
	// }
	



	
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
		if ((*b)->value == data->sec_max_b)
			pa(a, b, data);
		if (data->rot_dir == 1)
			rb(a, b, data);
		else
			rrb(a, b, data);
	}
	pa(a, b, data);
	if ((*a)->value > (*a)->next->value)
		sa(*a, *b, data);
}


void	minimax(t_stack *b, t_psdata *data)
{
	int	i;

	i = 0;
	data->b_min = b->value;
	data->b_max = b->value;
	data->d_to_min = data->stack_depth_b;
	data->d_to_max = data->stack_depth_b;
	while (b->next != NULL)
	{
		if (b->value < data->b_min)
		{
			data->b_min = b->value;
			data->d_to_min = i;
		}
		else if (b->value > data->b_max)
		{
			data->b_max = b->value;
			data->d_to_max = i;
		}
		i++;
		b = b->next;
	}
}

void	bubble_sort(t_stack **a, t_stack **b, t_psdata *data)
{
	int	i;

	i = 0;
	while (is_sorted(*a) == 0)
	{
		if ((*a)->value > (*a)->next->value)
			sa((*a), (*b), data);
		ra(a, b, data);
		i++;
		if (i == data->stack_depth_a - 1)
		{
			ra(a, b, data);
			i = 0;
		}
	}
}

void	push_next(t_stack **a, t_stack **b, t_psdata *data)
{
	minimax(*b, data);
	data->rot_dir = 1;
	data->rot_needed = data->d_to_min;
	data->min_or_max = 'm';
	if (data->stack_depth_b - data->d_to_min < data->rot_needed)
	{
		data->rot_dir = 2;
		data->rot_needed = data->stack_depth_b - data->d_to_min;
	}
	if (data->d_to_max < data->rot_needed)
	{
		data->rot_dir = 1;
		data->rot_needed = data->d_to_max;
		data->min_or_max = 'M';
	}
	if (data->stack_depth_b - data->d_to_max < data->rot_needed)
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
	while ((*b)->value != data->b_min)
	{
		if (data->rot_dir == 1)
			rb(a, b, data);
		else
			rrb(a, b, data);
	}
	pa(a, b, data);
	ra(a, b, data);
}

void	push_max(t_stack **a, t_stack **b, t_psdata *data)
{
	while ((*b)->value != data->b_max)
	{
		if (data->rot_dir == 1)
			rb(a, b, data);
		else
			rrb(a, b, data);
	}
	pa(a, b, data);
}

void	push_segments(t_stack **a, t_stack **b, t_psdata *data)
{
	int	i;
	int	j;
	int	segment;

	i = 0;
	j = data->stack_depth_a;
	segment = 3;
	while (i++ < j)
	{
		if ((*a)->segment == 1 || (*a)->segment == 2)
		{
			pb(a, b, data);
			if ((*b)->segment == 1)
				rb(a, b, data);
		}
		else
			ra(a, b, data);
	}
	while (segment <= 6)
	{
		i = 0;
		j = data->stack_depth_a;
		while (i++ < j)
		{
			if ((*a)->segment == segment)
				pb(a, b, data);
			else
				ra(a, b, data);
		}
		segment++;
	}
}


