

#include "../includes/push_swap.h"

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

int	get_next_min(t_stack *tmp)
{
	int min;

	min = 2147483647;
	while (tmp->next != NULL)
	{
		if (tmp->value < min && tmp->segment == -1)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

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

