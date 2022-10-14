/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:10:01 by mjokela           #+#    #+#             */
/*   Updated: 2022/06/21 15:10:06 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/*	Allocate space for stacks and data, and initialize that data.
	Read input from command line to stack a and execute commands given from
	stdin to that stack. Check if the execution of those commands leads
	to an empty stack b and a sorted stack a. Print OK if it does and KO if
	it doesn't. Finally, free all allocated memory */
int	main(int argc, char **argv)
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
	execute_commands(&stack_a, &stack_b, data);
	if (stack_b->next == NULL && is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_all(stack_a, stack_b, data);
	return (0);
}

/*	Read commands from stdin until there are no more commands.
	Dispatch each line found to check_line */
void	execute_commands(t_stack **a, t_stack **b, t_psdata *data)
{
	int		i;
	char	line[500];
	char	tmp[1];

	i = 0;
	tmp[0] = '\0';
	ft_bzero(line, 500);
	while (read(0, tmp, 1) > 0)
	{
		if (tmp[0] == '\n')
		{
			check_line(a, b, data, line);
			ft_bzero(line, 500);
			i = 0;
		}
		else
			line[i++] = tmp[0];
		if (i == 499)
		{
			while (read(0, tmp, 1) > 0)
				;
			print_error();
		}
	}
}

/*	Check if line given as input is a valid command. If it is, execute
	that command on the stacks. Otherwise print error and exit */
void	check_line(t_stack **a, t_stack **b, t_psdata *data, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(*a, *b, data, 0);
	else if (ft_strcmp(line, "sb") == 0)
		sb(*a, *b, data, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ss(*a, *b, data, 0);
	else if (ft_strcmp(line, "pa") == 0)
		pa(a, b, data, 0);
	else if (ft_strcmp(line, "pb") == 0)
		pb(a, b, data, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ra(a, b, data, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rb(a, b, data, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rr(a, b, data, 0);
	else if (ft_strcmp(line, "rra") == 0)
		rra(a, b, data, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(a, b, data, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(a, b, data, 0);
	else
		print_error();
}
