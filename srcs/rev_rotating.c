

#include "../includes/push_swap.h"

void	rra(t_stack **a, t_stack **b, t_psdata *data)
{
	rev_rotate(a);
	data->move_count++;
	//ft_printf("rra\n");
	if (data->v_flag == 1)
		print_stacks((*a), (*b));
}

void	rrb(t_stack **a, t_stack **b, t_psdata *data)
{
	rev_rotate(b);
	data->move_count++;
	//ft_printf("rrb\n");
	if (data->v_flag == 1)
		print_stacks((*a), (*b));
}

void	rrr(t_stack **a, t_stack **b, t_psdata *data)
{
	rev_rotate(a);
	rev_rotate(b);
	data->move_count++;
	//ft_printf("rrr\n");
	if (data->v_flag == 1)
		print_stacks((*a), (*b));
}
