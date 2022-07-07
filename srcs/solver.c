

#include "../includes/push_swap.h"

void	solve_stacks(t_stack **a, t_stack **b, t_psdata *data)
{
	int	tmp;

	if (is_sorted(*a, *b))
		return ;
	push(a, b);
	data->stack_depht_b++;
	data->stack_depth_a--;
	push(a, b);
	data->stack_depht_b++;
	data->stack_depth_a--;
	while ((*a)->next != NULL)
	{
		tmp = data->stack_depht_b;
		while ((*a)->value <= (*b)->value && tmp >= 0)
		{
			rotate(b);
			tmp--;
			print_stacks(*a, *b);
			sleep(1);
		}
		push(a, b);
		data->stack_depht_b++;
		data->stack_depth_a--;
	}
	if ((*b)->value < (*b)->next->value)
		swap(*b);
	print_stacks(*a, *b);

	
	while ((*b)->next != NULL)
	{
		push(b, a);
		data->stack_depht_b--;
		data->stack_depth_a++;
	}

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
