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

void	print_colours(t_stack *a, t_stack *b, t_psdata *data, char *cmd)
{
	sleep(1);
	if (ft_strcmp(cmd, "sa") == 0)
		ft_printf("%s%14s%s\n", GREEN, "\u21c5", RESET);
	else if (ft_strcmp(cmd, "sb") == 0)
		ft_printf("%s%26s%s\n", GREEN, "\u21c5", RESET);
	else if (ft_strcmp(cmd, "ss") == 0)
		ft_printf("%s%14s%14s%s\n", GREEN, "\u21c5", "\u21c5", RESET);
	else if (ft_strcmp(cmd, "pa") == 0)
		ft_printf("%s%26s%s\n", GREEN, "\u2190", RESET);
	else if (ft_strcmp(cmd, "pb") == 0)
		ft_printf("%s%14s%s\n", GREEN, "\u2192", RESET);
	else if (ft_strcmp(cmd, "ra") == 0)
		ft_printf("%s%14s%s\n", GREEN, "\u2191", RESET);
	else if (ft_strcmp(cmd, "rb") == 0)
		ft_printf("%s%26s%s\n", GREEN, "\u2191", RESET);
	else if (ft_strcmp(cmd, "rr") == 0)
		ft_printf("%s%14s%14s%s\n", GREEN, "\u2191", "\u2191", RESET);
	else if (ft_strcmp(cmd, "rra") == 0)
		ft_printf("%s%14s%s\n", GREEN, "\u2193", RESET);
	else if (ft_strcmp(cmd, "rrb") == 0)
		ft_printf("%s%26s%s\n", GREEN, "\u2193", RESET);
	else if (ft_strcmp(cmd, "rrr") == 0)
		ft_printf("%s%14s%14s%s\n", GREEN, "\u2193", "\u2193", RESET);
	visualize(a, b, data);
}

void	visualize(t_stack *a, t_stack *b, t_psdata *data)
{
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
			if (b->value == data->min_b)
				ft_printf("%s%12d%s", GREEN, b->value, RESET);
			else if (b->value == data->max_b)
				ft_printf("%s%12d%s", YELLOW, b->value, RESET);
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
