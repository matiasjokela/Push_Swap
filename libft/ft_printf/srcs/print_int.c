/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:11:16 by mjokela           #+#    #+#             */
/*   Updated: 2022/04/07 16:11:21 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	print_int(t_data *data, va_list ap)
{
	long long	len;
	char		*print;
	char		*num_str;
	long long	arg;

	arg = check_length_mod_int(data, ap);
	if (data->signed_mod == 0 && data->precision == 0 && data->width == 0)
		return ;
	num_str = get_num_str(data, arg);
	len = arg_len_int(data, arg);
	print = (char *)malloc(sizeof(char) * (len * 2));
	if (print == NULL)
		exit(-1);
	set_padding(data, print, num_str, len);
	if (has_non_blanks(print, len) == 0)
	{
		print[len] = 'k';
		data->minus = 0;
	}		
	write_print(data, print, len, 0);
	free(num_str);
	free(print);
}

char	*get_num_str(t_data *data, long long arg)
{
	char	*num_str;

	if (arg < -9223372036854775807)
		num_str = ft_strdup("9223372036854775808");
	else if (arg < 0)
	{
		data->blank = 0;
		data->plus = 0;
		num_str = ft_ltoa(arg * -1);
	}
	else
		num_str = ft_ltoa(arg);
	return (num_str);
}

long long	check_length_mod_int(t_data *data, va_list ap)
{
	if (data->mod_h == 1)
		data->signed_mod = (short)va_arg(ap, int);
	else if (data->mod_hh == 1)
		data->signed_mod = (char)va_arg(ap, int);
	else if (data->mod_l == 1)
		data->signed_mod = (long)va_arg(ap, long);
	else if (data->mod_ll == 1)
		data->signed_mod = (long long)va_arg(ap, long long);
	else
		data->signed_mod = (int)va_arg(ap, int);
	return (data->signed_mod);
}

long long	arg_len_int(t_data *data, long long arg)
{
	long long	len;

	len = ft_longlen(arg);
	if (data->width > len)
		len = data->width;
	if (data->precision > len)
		len = data->precision;
	if (len == data->precision && arg < 0)
		len++;
	if ((data->blank == 1 || data->plus == 1) && (len == ft_longlen(arg) \
	|| len == data->precision) && \
	!(arg == 0 && data->precision == 0 && data->width == 1))
		len++;
	data->total_len += len;
	return (len);
}

char	*ft_ltoa(long long n)
{
	long long	i;
	char		*stri;

	i = ft_longlen(n);
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	stri = (char *)malloc(sizeof(char) * i + 1);
	if (stri == NULL)
		return (NULL);
	stri[i--] = '\0';
	if (n < 0)
	{
		stri[0] = '-';
		n *= -1;
	}
	while (n / 10 != 0)
	{
		stri[i--] = n % 10 + '0';
		n = n / 10;
	}
	stri[i--] = n % 10 + '0';
	return (stri);
}
