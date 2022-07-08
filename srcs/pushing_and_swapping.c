
#include "../includes/push_swap.h"

void	sa(t_stack *a, t_stack *b, t_psdata *data)
{
	swap(a);
	data->move_count++;
	//ft_printf("sa\n");
	if (data->v_flag == 1)
		print_stacks(a, b);
}

void	sb(t_stack *a, t_stack *b, t_psdata *data)
{
	swap(b);
	data->move_count++;
	//ft_printf("sb\n");
	if (data->v_flag == 1)
		print_stacks(a, b);
}

void	ss(t_stack *a, t_stack *b, t_psdata *data)
{
	swap(a);
	swap(b);
	data->move_count++;
	//ft_printf("ss\n");
	if (data->v_flag == 1)
		print_stacks(a, b);
}

void	pa(t_stack **a, t_stack **b, t_psdata *data)
{
	push(b, a);
	data->move_count++;
	data->stack_depth_a++;
	data->stack_depth_b--;
	//ft_printf("pa\n");
	if (data->v_flag == 1)
		print_stacks((*a), (*b));
}

void	pb(t_stack **a, t_stack **b, t_psdata *data)
{
	push(a, b);
	data->move_count++;
	data->stack_depth_a--;
	data->stack_depth_b++;
	//ft_printf("pb\n");
	if (data->v_flag == 1)
		print_stacks((*a), (*b));
}
