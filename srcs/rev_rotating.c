

#include "../includes/push_swap.h"

void	rra(t_stack **a, t_psdata *data)
{
	rev_rotate(a);
	data->move_count++;
	//ft_printf("rra\n");
}

void	rrb(t_stack **b, t_psdata *data)
{
	rev_rotate(b);
	data->move_count++;
	//ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, t_psdata *data)
{
	rev_rotate(a);
	rev_rotate(b);
	data->move_count++;
	//ft_printf("rrr\n");
}
