/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_and_dispatching.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:58:37 by mjokela           #+#    #+#             */
/*   Updated: 2022/04/12 14:58:41 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	isvalid(const char *format, int i)
{
	if (format[i] == '\0')
		return (0);
	while (ft_strchr(CONVERSION, format[i]) == NULL)
	{
		if (ft_strchr(SPECIFIERS, format[i]) == NULL || format[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	dispatch(t_data *data, va_list ap)
{
	if (data->conversion == '%')
		print_modulo(data);
	else if (data->conversion == 'd' || data->conversion == 'i')
		print_int(data, ap);
	else if (data->conversion == 'o')
		print_octal(data, ap);
	else if (data->conversion == 'x' || data->conversion == 'X')
		print_hex(data, ap);
	else if (data->conversion == 'u')
		print_uint(data, ap);
	else if (data->conversion == 'c')
		print_char(data, ap);
	else if (data->conversion == 'p')
		print_pointer(data, ap);
	else if (data->conversion == 's')
		print_string(data, ap);
	else if (data->conversion == 'b')
		print_bits(data, ap);
	else if (data->conversion == 'f' || data->conversion == 'F')
		print_float(data, ap);
}

int	convert(const char *format, int *i, t_data *data, va_list ap)
{
	clear_data(data);
	*i += 1;
	if (!isvalid(format, *i))
		return (0);
	read_data(format, i, data, ap);
	return (1);
}
