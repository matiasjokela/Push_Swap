/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:30:49 by mjokela           #+#    #+#             */
/*   Updated: 2022/03/24 15:31:02 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	read_data(const char *format, int *i, t_data *data, va_list ap)
{
	read_flags(format, i, data);
	read_dimensions(format, i, data, ap);
	read_modifiers(format, i, data);
	data->conversion = format[*i];
	*i += 1;
	if (data->conversion == '%' || data->conversion == 'c')
		return ;
	if (data->minus == 1)
		data->zero = 0;
	if (data->precision != -1 && data->conversion != 'f')
		data->zero = 0;
	if (data->plus == 1)
		data->blank = 0;
}

void	read_flags(const char *format, int *i, t_data *data)
{
	char	c;

	while (1)
	{
		c = format[*i];
		if (c == '-')
			data->minus = 1;
		else if (c == '0')
			data->zero = 1;
		else if (c == '+')
			data->plus = 1;
		else if (c == ' ')
			data->blank = 1;
		else if (c == '#')
			data->hash = 1;
		else
			break ;
		*i += 1;
	}
}

void	read_dimensions(const char *form, int *i, t_data *data, va_list ap)
{
	read_width(form, i, data, ap);
	if (form[*i] == '.')
	{
		*i += 1;
		if (form[*i] == '*')
		{
			data->precision = (int)va_arg(ap, int);
			if (data->precision < 0)
				data->precision = -1;
			*i += 1;
		}
		else
		{
			data->precision = ft_atoi(&form[*i]);
			while (form[*i] >= '0' && form[*i] <= '9')
				*i += 1;
		}
	}
}

void	read_modifiers(const char *format, int *i, t_data *data)
{
	if (format[*i] == 'h' && format[*i + 1] != 'h')
		data->mod_h = 1;
	else if (format[*i] == 'h')
		data->mod_hh = 1;
	else if (format[*i] == 'l' && format[*i + 1] != 'l')
		data->mod_l = 1;
	else if (format[*i] == 'l')
		data->mod_ll = 1;
	else if (format[*i] == 'L')
		data->mod_ld = 1;
	while (ft_strchr(CONVERSION, format[*i]) == NULL && format[*i] != '\0')
		*i += 1;
}

void	read_width(const char *form, int *i, t_data *data, va_list ap)
{
	if (form[*i] == '*')
	{
		data->width = (int)va_arg(ap, int);
		if (data->width < 0)
		{
			data->width *= -1;
			data->minus = 1;
		}
		*i += 1;
	}
	if (form[*i] >= '0' && form[*i] <= '9')
	{
		data->width = ft_atoi(&form[*i]);
		while (form[*i] >= '0' && form[*i] <= '9')
			*i += 1;
	}
}
