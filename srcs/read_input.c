/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:45:04 by mjokela           #+#    #+#             */
/*   Updated: 2022/06/30 14:45:17 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	read_input(t_stack *stack_a, int argc, char **argv, t_psdata *data)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	tmp = stack_a;
	if (argc > 2)
		check_flags(argv, data, &i);
	while (i < argc)
		read_values(&stack_a, argv[i++], data);
	stack_a = tmp;
	check_duplicates(stack_a);
	get_segments(stack_a, data);
}

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

void	read_values(t_stack **stack_a, char *str, t_psdata *data)
{
	int			i;
	long long	value;

	i = 0;
	value = 0;
	while (str[i] != '\0')
	{
		value = ps_atoi(str, &i);
		if (value < -2147483648 || value > 2147483647)
			print_error();
		(*stack_a)->value = value;
		(*stack_a)->next = new_node(0);
		*stack_a = (*stack_a)->next;
		data->stack_depth_a += 1;
	}
}

long long	ps_atoi(char *str, int *i)
{
	long long	value;
	long long	sign;

	value = 0;
	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		*i += 1;
	}
	if (!(str[*i] >= '0' && str[*i] <= '9'))
		return (2147483648);
	while (str[*i] != '\0' && str[*i] >= '0' && str[*i] <= '9')
	{
		value = value * 10 + str[*i] - '0';
		if (value  > 2147483647)
			return (2147483648);
		*i += 1;
	}
	if (str[*i] == ' ')
		*i += 1;
	else if (str[*i] != '\0')
		return (2147483648);
	return (sign * value);
}

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

void	get_segments(t_stack *stack_a, t_psdata *data)
{
	t_stack	*tmp;
	int		min;
	int		marked;

	marked = 0;
	while (marked < data->stack_depth_a)
	{
		tmp = stack_a;
		min = 2147483647;
		while (tmp->next != NULL)
		{
			if (tmp->value < min && tmp->segment == -1)
				min = tmp->value;
			tmp = tmp->next;
		}
		tmp = stack_a;
		while (tmp->value != min)
			tmp = tmp->next;
		if (data->stack_depth_a - marked < 4)
			tmp->segment = 0;
		else if (marked < (data->stack_depth_a / 6))
			tmp->segment = 1;
		else if (marked < ((data->stack_depth_a / 6) * 2))
			tmp->segment = 2;
		else if (marked < ((data->stack_depth_a / 6) * 3))
			tmp->segment = 3;
		else if (marked < ((data->stack_depth_a / 6) * 4))
			tmp->segment = 4;
		else if (marked < ((data->stack_depth_a / 6) * 5))
			tmp->segment = 5;
		else
			tmp->segment = 6;
		marked++;
	}
}