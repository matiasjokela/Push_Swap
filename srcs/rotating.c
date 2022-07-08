

#include "../includes/push_swap.h"

void	ra(t_stack **a, t_psdata *data)
{
	rotate(a);
	data->move_count++;
	//ft_printf("ra\n");
}

void	rb(t_stack **b, t_psdata *data)
{
	rotate(b);
	data->move_count++;
	//ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, t_psdata *data)
{
	rotate(a);
	rotate(b);
	data->move_count++;
	//ft_printf("rr\n");
}
