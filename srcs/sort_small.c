

#include "../includes/push_swap.h"

void	sort_small(t_stack **a, t_stack **b, t_psdata *data)
{
	if (data->stack_depth_a == 1)
		return ;
	if (data->stack_depth_a == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(*a, *b, data, 1);
		return ;
	}
	while (data->stack_depth_a > 3)
	{
		if ((*a)->segment != 0)
			pb(a, b, data, 1);
		else
			ra(a, b, data, 1);
	}
	sort_three(a, b, data);
	while ((*b)->next != NULL)
		push_max_b(a, b, data);
}

void	get_values(t_stack *a, int *min, int *mid, int *max)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	i = 0;
	while (i++ < 3)
	{
		if (tmp->value < *min)
			*min = tmp->value;
		if (tmp->value > *max)
			*max = tmp->value;
		tmp = tmp->next;
	}
	tmp = a;
	i = 0;
	while (i++ < 3)
	{
		if (tmp->value != *min && tmp->value != *max)
			*mid = tmp->value;
		tmp = tmp->next;
	}
}

void	sort_three(t_stack **a, t_stack **b, t_psdata *data)
{
	int	min;
	int	mid;
	int	max;

	min = (*a)->value;
	mid = min;
	max = mid;
	get_values(*a, &min, &mid, &max);
	if ((*a)->value == max && (*a)->next->value == mid)
	{
		sa(*a, *b, data, 1);
		rra(a, b, data, 1);
	}
	else if ((*a)->value == mid && (*a)->next->value == max)
		rra(a, b, data, 1);
	else if ((*a)->value == mid && (*a)->next->value == min)
		sa(*a, *b, data, 1);
	else if ((*a)->value == min && (*a)->next->value == max)
	{
		rra(a, b, data, 1);
		sa(*a, *b, data, 1);
	}
	else if ((*a)->value == max && (*a)->next->value == min)
		ra(a, b, data, 1);
}