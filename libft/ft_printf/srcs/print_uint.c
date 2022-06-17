/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:24:39 by mjokela           #+#    #+#             */
/*   Updated: 2022/04/19 12:24:42 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	print_uint(t_data *data, va_list ap)
{
	long long			len;
	char				*print;
	char				*num_str;
	unsigned long long	arg;

	check_length_mod_uint(data, ap);
	arg = data->unsigned_mod;
	if (arg == 0 && data->precision == 0 && data->width == 0)
		return ;
	num_str = ft_ltoau_base(arg, 10, data);
	len = arg_len_uint(data, arg, num_str);
	print = (char *)malloc(sizeof(char) * (len * 2));
	if (print == NULL)
		exit(-1);
	set_padding_uint(data, print, num_str, len);
	if (has_non_blanks(print, len) == 0)
		data->minus = 0;
	write_print(data, print, len, 0);
	free(num_str);
	free(print);
}

void	check_length_mod_uint(t_data *data, va_list ap)
{
	if (data->mod_h == 1)
		data->unsigned_mod = (unsigned short)va_arg(ap, unsigned int);
	else if (data->mod_hh == 1)
		data->unsigned_mod = (unsigned char)va_arg(ap, unsigned int);
	else if (data->mod_l == 1)
		data->unsigned_mod = (unsigned long)va_arg(ap, unsigned long);
	else if (data->mod_ll == 1)
		data->unsigned_mod = (unsigned long long)va_arg(ap, unsigned long long);
	else
		data->unsigned_mod = (unsigned int)va_arg(ap, unsigned int);
	data->blank = 0;
	data->plus = 0;
	if (data->conversion == 'u')
		data->hash = 0;
}

long long	arg_len_uint(t_data *data, long long arg, char *oct_str)
{
	long long	len;
	int			strl;

	strl = ft_strlen(oct_str);
	len = strl;
	if (data->width > len)
		len = data->width;
	if (data->precision > len)
		len = data->precision;
	if (data->hash == 1 && len == strl && arg != 0)
		len++;
	data->total_len += len;
	return (len);
}

void	set_padding_uint(t_data *data, char *print, char *num_str, int len)
{
	int	i;
	int	precision;

	i = ft_strlen(num_str);
	precision = data->precision - i;
	if (data->zero == 1)
		ft_memset(print, '0', len * 2);
	else
		ft_memset(print, ' ', len * 2);
	if (!(data->precision == 0 && data->unsigned_mod == 0 && data->width != 0))
		ft_memcpy(&print[len - i], num_str, i);
	if (data->hash == 1)
		print[len - i - 1] = '0';
	if (precision > 0)
		ft_memset(&print[len - i - precision], '0', precision);
}
