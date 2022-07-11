

#include "../includes/push_swap.h"

void	solve_stacks(t_stack **a, t_stack **b, t_psdata *data)
{

	if (is_sorted(*a))
		return ;
	ft_printf("node count: %d\n", data->stack_depth_a);
	// bubble_sort(a, b, data);
	push_segments(a, b, data);
	bubble_sort(a, b, data);
	//find_and_push(a, b, data);



	while ((*b)->next != NULL)
		push_max_b(a, b, data);


	// minimax((*a), data);
	// data->global_max = data->a_max;
	// push_min(a, b, data);
	// while ((*a)->next != NULL)
	// {
	// 	minimax((*a), data);
	// 	push_next(a, b, data);
	// }
	// while ((*b)->value != data->global_max)
	// 	rb(a, b, data);	
	// while ((*b)->next != NULL)
	// 	pa(a, b, data);
	ft_printf("move count: %d\n", data->move_count);
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


void	minimax(t_stack *a, t_psdata *data)
{
	int	i;

	i = 0;
	data->a_min = a->value;
	data->a_max = a->value;
	data->d_to_min = data->stack_depth_a;
	data->d_to_max = data->stack_depth_a;
	while (a->next != NULL)
	{
		if (a->value < data->a_min)
		{
			data->a_min = a->value;
			data->d_to_min = i;
		}
		else if (a->value > data->a_max)
		{
			data->a_max = a->value;
			data->d_to_max = i;
		}
		i++;
		a = a->next;
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
		rotate(a);
		i++;
		if (i == data->stack_depth_a - 1)
		{
			rotate(a);
			i = 0;
		}
	}
}

void	push_next(t_stack **a, t_stack **b, t_psdata *data)
{
	data->rot_dir = 1;
	data->rot_needed = data->d_to_min;
	data->min_or_max = 'm';
	if (data->stack_depth_a - data->d_to_min < data->rot_needed)
	{
		data->rot_dir = 2;
		data->rot_needed = data->stack_depth_a - data->d_to_min;
	}
	if (data->d_to_max < data->rot_needed)
	{
		data->rot_dir = 1;
		data->rot_needed = data->d_to_max;
		data->min_or_max = 'M';
	}
	if (data->stack_depth_a - data->d_to_max < data->rot_needed)
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
	while ((*a)->value != data->a_min)
	{
		if (data->rot_dir == 1)
			ra(a, b, data);
		else
			rra(a, b, data);
	}
	if (data->stack_depth_b == 0)
		pb(a, b, data);
	else
	{
		while ((*b)->value != data->b_floor)
			rb(a, b, data);
		pb(a, b, data);
	}
	data->b_floor = data->a_min;
}

void	push_max(t_stack **a, t_stack **b, t_psdata *data)
{
	while ((*a)->value != data->a_max)
	{
		if (data->rot_dir == 1)
			ra(a, b, data);
		else
			rra(a, b, data);
	}
	while ((*b)->value != data->b_floor)
		rb(a, b, data);
	pb(a, b, data);
}

void	push_segments(t_stack **a, t_stack **b, t_psdata *data)
{
	int	i;
	int	j;

	i = 0;
	j = data->stack_depth_a;
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
	i = 0;
	j = data->stack_depth_a;
	while (i++ < j)
	{
		if ((*a)->segment == 3)
			pb(a, b, data);
		else
			ra(a, b, data);
	}
	i = 0;
	j = data->stack_depth_a;
	while (i++ < j)
	{
		if ((*a)->segment == 4)
			pb(a, b, data);
		else
			ra(a, b, data);
	}
	i = 0;
	j = data->stack_depth_a;
	while (i++ < j)
	{
		if ((*a)->segment == 5)
			pb(a, b, data);
		else
			ra(a, b, data);
	}
}
