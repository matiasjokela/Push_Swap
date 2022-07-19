/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:54:40 by mjokela           #+#    #+#             */
/*   Updated: 2022/07/19 16:54:46 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_data(t_psdata *data)
{
	data->v_flag = 0;
	data->c_flag = 0;
	data->stack_depth_a = 0;
	data->stack_depth_b = 0;
	data->move_count = 0;
	data->marked = 0;
}

t_stack	*new_node(int nbr)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == 0)
		exit(1);
	node->value = nbr;
	node->segment = -1;
	node->next = NULL;
	return (node);
}
