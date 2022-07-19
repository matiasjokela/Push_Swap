/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:56:33 by mjokela           #+#    #+#             */
/*   Updated: 2022/07/19 16:56:38 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **a, t_stack **b, t_psdata *data, int print)
{
	rev_rotate(a);
	data->move_count++;
	if (print)
		ft_printf("rra\n");
	if (data->v_flag == 1)
		print_stacks((*a), (*b));
	else if (data->c_flag == 1)
		print_colours(*a, *b, data, "rra");
}

void	rrb(t_stack **a, t_stack **b, t_psdata *data, int print)
{
	rev_rotate(b);
	data->move_count++;
	if (print)
		ft_printf("rrb\n");
	if (data->v_flag == 1)
		print_stacks((*a), (*b));
	else if (data->c_flag == 1)
		print_colours(*a, *b, data, "rrb");
}

void	rrr(t_stack **a, t_stack **b, t_psdata *data, int print)
{
	rev_rotate(a);
	rev_rotate(b);
	data->move_count++;
	if (print)
		ft_printf("rrr\n");
	if (data->v_flag == 1)
		print_stacks((*a), (*b));
	else if (data->c_flag == 1)
		print_colours(*a, *b, data, "rrr");
}
