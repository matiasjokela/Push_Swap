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
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_flags	*flags;

	if (argc == 1)
		return (1);
	stack_a = new_node(0);
	stack_b = NULL;
	flags = (t_flags *)malloc(sizeof(t_flags));
	if (flags == NULL)
		return (1);
	init_flags(flags);
	read_input(stack_a, argc, argv, flags);
	(void)stack_b;
	while (stack_a->next != NULL)
	{
		ft_printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}


	
	// Check duplicates from sorted array
	
}

void	init_flags(t_flags *flags)
{
	flags->v_flag = 0;
	flags->c_flag = 0;
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