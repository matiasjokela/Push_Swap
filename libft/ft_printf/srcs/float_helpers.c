/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:22:13 by mjokela           #+#    #+#             */
/*   Updated: 2022/04/21 15:22:15 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

long double	check_length_mod_float(t_data *data, va_list ap)
{
	if (data->mod_ld == 1)
		data->float_mod = (long double)va_arg(ap, long double);
	else
		data->float_mod = (double)va_arg(ap, double);
	return (data->float_mod);
}

char	*get_float_str(t_data *data, long double arg)
{
	char	*float_str;

	if (data->double_is_negative == 1)
	{
		data->blank = 0;
		data->plus = 0;
		float_str = ft_dtoa(arg * -1.0, data);
	}
	else
		float_str = ft_dtoa(arg, data);
	return (float_str);
}

int	double_is_negative(double n)
{
	unsigned long long	*tmp;

	tmp = (unsigned long long *)&n;
	return ((int)(*tmp >> 63));
}

long long	arg_len_float(t_data *data, char *float_str)
{
	long long	len;

	len = ft_strlen(float_str);
	if (data->double_is_negative == 1 || data->plus == 1 || \
	data->blank == 1)
		len++;
	if (data->width > len)
		len = data->width;
	data->total_len += len;
	return (len);
}

int	ft_floatlen(long double n, t_data *data)
{
	long long	i;

	i = 0;
	i += ft_longlen(n / 1);
	if (!(data->precision == 0 && data->hash == 0))
		i += data->precision + 1;
	return (i);
}
