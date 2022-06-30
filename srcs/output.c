/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:05:15 by mjokela           #+#    #+#             */
/*   Updated: 2022/06/30 15:07:10 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	ft_printf("Stacks:\n");
	while (!(a->next == NULL && b->next == NULL))
	{
		if (a->next != NULL)
		{
			ft_printf("%12d", a->value);
			a = a->next;
		}
		if (b->next != NULL)
		{
			ft_printf("%12d", b->value);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n           A           B\n");
}

void	print_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

