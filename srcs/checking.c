/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:54:10 by mjokela           #+#    #+#             */
/*   Updated: 2022/07/19 16:54:17 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Check if stack is sorted */
int	is_sorted(t_stack *stack)
{
	int	tmp;

	while (stack->next->next != NULL)
	{
		tmp = stack->value;
		stack = stack->next;
		if (tmp > stack->value)
			return (0);
	}
	return (1);
}

/* Check for duplicates, print error message and exit if found */
void	check_duplicates(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*current;
	int		value;

	tmp = a;
	current = a;
	while (current->next != 0)
	{
		value = current->value;
		while (tmp->next != NULL)
		{
			if (tmp->value == value && current != tmp)
				print_error();
			tmp = tmp->next;
		}
		current = current->next;
		tmp = a;
	}
}

/* Check for flags fo the visualizer */
void	check_flags(char **argv, t_psdata *data, int *i)
{
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		data->v_flag = 1;
		*i = 2;
	}
	else if (ft_strcmp(argv[1], "-c") == 0)
	{
		data->c_flag = 1;
		*i = 2;
	}
}
