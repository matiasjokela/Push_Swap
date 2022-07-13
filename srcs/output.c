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
			ft_printf("%12d %d", a->value, a->segment);
			a = a->next;
		}
		else
			ft_printf("%12c", ' ');
		if (b->next != NULL)
		{
			ft_printf("%12d %d", b->value, b->segment);
			b = b->next;
		}
		else
			ft_printf("%12c", ' ');
		ft_printf("\n");
	}
	ft_printf("\n           A           B\n");
}

void	print_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	visualize(t_stack *a, t_stack *b, t_psdata *data)
{
	ft_printf("move count: %d\n", data->move_count);
	ft_printf("Stacks:\n");
	while (!(a->next == NULL && b->next == NULL))
	{
		if (a->next != NULL)
		{
			ft_printf("%12d", a->value);
			a = a->next;
		}
		else
			ft_printf("%12c", ' ');
		if (b->next != NULL)
		{
			if (b->value == data->sec_min_b)
				ft_printf("%s%12d%s", BLUE, b->value, RESET);
			else if (b->value == data->min_b)
				ft_printf("%s%12d%s", GREEN, b->value, RESET);
			else if (b->value == data->sec_max_b)
				ft_printf("%s%12d%s", YELLOW, b->value, RESET);
			else if (b->value == data->max_b)
				ft_printf("%s%12d%s", RED, b->value, RESET);
			else
				ft_printf("%12d", b->value);
			b = b->next;
		}
		else
			ft_printf("%12c", ' ');
		ft_printf("\n");
	}
	ft_printf("\n           A           B\n");
}