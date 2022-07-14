


#include "../includes/push_swap.h"

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

void	minimax(t_stack **a, t_stack **b, t_psdata *data)
{
	min_b(*b, data);
	max_b(*b, data);
	push_next(a, b, data);
}