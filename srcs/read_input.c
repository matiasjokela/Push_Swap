

#include "../includes/push_swap.h"

void	read_input(t_stack *stack_a, int argc, char **argv, t_flags *flags)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	tmp = stack_a;
	if (argc > 2)
		check_flags(argv, flags, &i);
	while (i < argc)
		read_values(stack_a, argv[i++]);
	stack_a = tmp;
}

void	check_flags(char **argv, t_flags *flags, int *i)
{
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		flags->v_flag = 1;
		*i = 2;
	}
	else if (ft_strcmp(argv[1], "-c") == 0)
	{
		flags->c_flag = 1;
		*i = 2;
	}
}

void	read_values(t_stack *stack_a, char *str)
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
		stack_a->value = value;
		stack_a->next = new_node(0);
		stack_a = stack_a->next;
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