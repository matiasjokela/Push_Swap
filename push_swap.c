/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:10:24 by mjokela           #+#    #+#             */
/*   Updated: 2022/06/21 15:10:34 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"


int		main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_psdata	*data;

	if (argc == 1)
		return (1);
	stack_a = new_node(0);
	stack_b = new_node(0);
	data = (t_psdata *)malloc(sizeof(t_psdata));
	if (data == NULL)
		return (1);
	init_data(data);
	read_input(stack_a, argc, argv, data);
	//print_stacks(stack_a, stack_b);
	solve_stacks(&stack_a, &stack_b, data);
	//print_stacks(stack_a, stack_b);
	// if (!is_sorted(stack_a))
	// 	ft_printf("NOT SORTED!!\n");
	// ft_printf("node count: %d\n", data->stack_depth_a);
	// ft_printf("move count: %d\n", data->move_count);
	

	
}

