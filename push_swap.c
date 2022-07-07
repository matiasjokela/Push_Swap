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
	print_stacks(stack_a, stack_b);
	solve_stacks(&stack_a, &stack_b, data);
	print_stacks(stack_a, stack_b);
	// for (int i = 0; i < 10; i++)
	// {
	// 	rev_rotate(&stack_a);
	// 	print_stacks(stack_a, stack_b);
	// 	sleep(1);
	// }





	
	// Check duplicates from sorted array
	
}

void	init_data(t_psdata *data)
{
	data->v_flag = 0;
	data->c_flag = 0;
	data->stack_depth_a = 0;
	data->stack_depht_b = 0;
}

t_stack	*new_node(int nbr)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == 0)
		exit(1);
	node->value = nbr;
	node->next = NULL;
	return (node);
}