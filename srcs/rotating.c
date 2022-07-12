

#include "../includes/push_swap.h"

void	ra(t_stack **a, t_stack **b, t_psdata *data, int print)
{
	rotate(a);
	data->move_count++;
	if (print)
		ft_printf("ra\n");
	if (data->v_flag == 1)
		print_stacks((*a), (*b));
}

void	rb(t_stack **a, t_stack **b, t_psdata *data, int print)
{
	rotate(b);
	data->move_count++;
	if (print)
		ft_printf("rb\n");
	if (data->v_flag == 1)
		print_stacks((*a), (*b));
}

void	rr(t_stack **a, t_stack **b, t_psdata *data, int print)
{
	rotate(a);
	rotate(b);
	data->move_count++;
	if (print)
		ft_printf("rr\n");
	if (data->v_flag == 1)
		print_stacks((*a), (*b));
}
