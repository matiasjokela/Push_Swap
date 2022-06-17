/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:23:09 by mjokela           #+#    #+#             */
/*   Updated: 2022/04/19 12:23:12 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	print_float(t_data *data, va_list ap)
{
	long long	len;
	char		*print;
	char		*float_str;
	long double	arg;

	if (data->precision == -1)
		data->precision = 6;
	arg = check_length_mod_float(data, ap);
	data->double_is_negative = double_is_negative(data->float_mod);
	float_str = get_float_str(data, arg);
	len = arg_len_float(data, float_str);
	print = (char *)malloc(sizeof(char) * (len * 2));
	if (print == NULL)
		exit(-1);
	set_padding_float(data, print, float_str, len);
	write_print_float(data, print, len, 0);
	free(float_str);
	free(print);
}

char	*ft_dtoa(long double n, t_data *data)
{
	int					i;
	char				*str;
	unsigned long long	tmp;

	i = ft_floatlen(n, data);
	str = (char *)malloc(sizeof(char) * i + 2);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, i-- + 2);
	tmp = (unsigned long long)n;
	if (data->precision != 0)
		get_fractal(&n, data, &i, str);
	else
	{
		if (!(n - (long double)tmp == 0.5 && tmp % 2 == 0))
		{
			if (ft_longlen((long long)n) < ft_longlen((long long)(n + 0.5)))
				i++;
			n += 0.5;
		}
		if (data->hash == 1)
			str[i--] = '.';
	}
	fill_str((unsigned long long)n, &i, 0, str);
	return (str);
}

void	get_fractal(long double *n, t_data *data, int *i, char *str)
{
	int					j;
	long double			fract;
	unsigned long long	tmp;

	j = 0;
	fract = *n - (long long)*n;
	data->true_precision = get_true_precision(data);
	while (j++ < data->true_precision)
		fract *= 10;
	if (data->true_precision != data->precision)
		pad_with_zeros(data->true_precision, data, i, str);
	tmp = (unsigned long long)fract;
	if (!(fract - tmp <= 0.5 && tmp % 2 == 0))
		fract += 0.5;
	tmp = (unsigned long long)fract;
	if (ft_longlen((long long)fract) > --j && tmp != 0)
	{
		tmp = 0;
		if (ft_longlen((long long)*n) < ft_longlen((long long)(*n + 1)))
			*i += 1;
		*n += 1;
	}
	fill_str(tmp, i, j, str);
	str[*i] = '.';
	*i -= 1;
}

void	set_padding_float(t_data *data, char *print, char *fstr, int len)
{
	int	i;

	i = ft_strlen(fstr);
	if (data->zero == 1)
		ft_memset(print, '0', len * 2);
	else
		ft_memset(print, ' ', len * 2);
	ft_memcpy(&print[len - i], fstr, i);
}

void	write_print_float(t_data *data, char *print, int len, int i)
{
	if (data->zero == 1)
	{
		if (data->double_is_negative == 1)
			print[0] = '-';
		else if (data->plus == 1)
			print[0] = '+';
		else if (data->blank == 1)
			print[0] = ' ';
		write(1, print, len);
	}
	else
	{
		while (print[i] == ' ')
			i++;
		if (data->double_is_negative == 1)
			print[--i] = '-';
		else if (data->plus == 1)
			print[--i] = '+';
		else if (data->blank == 1)
			print[--i] = ' ';
		if (data->minus == 1)
			write(1, &print[i], len);
		else
			write(1, print, len);
	}
}
