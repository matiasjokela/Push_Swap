

#include "../includes/push_swap.h"

void	solve_stacks(t_stack **a, t_stack **b, t_psdata *data)
{
	int	min;

	if (is_sorted(*a, *b))
		return ;
	ft_printf("move count: %d\n", data->stack_depth_b);
	while ((*a)->next != NULL)
	{
		min = find_min((*a));
		while ((*a)->value != min)
		{
			rotate(a);
			data->stack_depth_b++;
		}

		push(a, b);
		data->stack_depth_b++;
	}
	


	
	while ((*b)->next != NULL)
	{
		push(b, a);
		data->stack_depth_b++;
	}
	ft_printf("move count: %d\n", data->stack_depth_b);
}

int	is_sorted(t_stack *a, t_stack *b)
{
	int	tmp;

	if (b->next != NULL)
		return (0);
	while (a->next->next != NULL)
	{
		tmp = a->value;
		a = a->next;
		if (tmp == a->value)
			print_error();
		if (tmp > a->value)
			return (0);
	}
	return (1);
}

int	find_min(t_stack *a)
{
	int	min;

	min = a->value;
	while (a->next != NULL)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}
