/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:56:50 by mjokela           #+#    #+#             */
/*   Updated: 2022/07/19 16:56:55 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Rotate stack a */
void	ra(t_stack **a, t_stack **b, t_psdata *data, int print)
{
	rotate(a);
	data->move_count++;
	if (print)
		ft_printf("ra\n");
	if (data->v_flag == 1)
		print_stacks((*a), (*b));
	else if (data->c_flag == 1)
		print_colours(*a, *b, data, "ra");
}

/* Rotate stack b */
void	rb(t_stack **a, t_stack **b, t_psdata *data, int print)
{
	rotate(b);
	data->move_count++;
	if (print)
		ft_printf("rb\n");
	if (data->v_flag == 1)
		print_stacks((*a), (*b));
	else if (data->c_flag == 1)
		print_colours(*a, *b, data, "rb");
}

/* Rotate stacks a and b */
void	rr(t_stack **a, t_stack **b, t_psdata *data, int print)
{
	rotate(a);
	rotate(b);
	data->move_count++;
	if (print)
		ft_printf("rr\n");
	if (data->v_flag == 1)
		print_stacks((*a), (*b));
	else if (data->c_flag == 1)
		print_colours(*a, *b, data, "rr");
}
