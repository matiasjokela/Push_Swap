
#include "../includes/push_swap.h"

void	sa(t_stack *a, t_psdata *data)
{
	swap(a);
	data->move_count++;
	//ft_printf("sa\n");
}

void	sb(t_stack *b, t_psdata *data)
{
	swap(b);
	data->move_count++;
	//ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b, t_psdata *data)
{
	swap(a);
	swap(b);
	data->move_count++;
	//ft_printf("ss\n");
}

void	pa(t_stack **a, t_stack **b, t_psdata *data)
{
	push(b, a);
	data->move_count++;
	data->stack_depth_a++;
	data->stack_depth_b--;
	//ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, t_psdata *data)
{
	push(a, b);
	data->move_count++;
	data->stack_depth_a--;
	data->stack_depth_b++;
	//ft_printf("pb\n");
}
