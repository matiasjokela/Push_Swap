

#include "../includes/push_swap.h"

void	solve_stacks(t_stack **a, t_stack **b, t_psdata *data)
{

	if (is_sorted(*a, *b))
		return ;
	ft_printf("move count: %d\n", data->move_count);
	while ((*a)->next != NULL)
	{
		minimax((*a), data);
		while ((*a)->value != data->a_min)
		{
			if ((data->d_to_min * 2) < data->stack_depth_a)
				ra(a, data);
			else
				rra(a, data);
		}
		pb(a, b, data);
	}
	


	
	while ((*b)->next != NULL)
		pa(a, b, data);
	ft_printf("move count: %d\n", data->move_count);
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
