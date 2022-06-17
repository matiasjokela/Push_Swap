/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:18:18 by mjokela           #+#    #+#             */
/*   Updated: 2022/04/14 16:18:21 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	print_hex(t_data *data, va_list ap)
{
	long long			len;
	char				*print;
	char				*oct_str;
	unsigned long long	arg;

	check_length_mod_uint(data, ap);
	arg = data->unsigned_mod;
	if (arg == 0 && data->precision == 0 && data->width == 0)
		return ;
	if (arg == 0 && data->hash == 1)
		data->hash = 2;
	oct_str = ft_ltoau_base(arg, 16, data);
	len = arg_len_hex(data, arg, oct_str);
	print = (char *)malloc(sizeof(char) * (len * 2));
	if (print == NULL)
		exit(-1);
	set_padding_hex(data, print, oct_str, len);
	if (has_non_blanks(print, len) == 0)
		data->zero = 1;
	write_print(data, print, len, 0);
	free(oct_str);
	free(print);
}

void	set_padding_hex(t_data *data, char *print, char *num_str, int len)
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
	if (precision > 0)
		ft_memset(&print[len - i - precision], '0', precision);
	if (data->hash == 1)
	{
		if (data->zero == 1)
			print[1] = data->conversion;
		if (data->zero == 1)
			return ;
		if (precision < 0)
			precision = 0;
		i = len - i - precision;
		print[i - 2] = '0';
		print[i - 1] = data->conversion;
	}
}

long long	arg_len_hex(t_data *data, long long arg, char *oct_str)
{
	long long	len;
	int			strl;

	strl = ft_strlen(oct_str);
	len = strl;
	if (data->precision > len)
		len = data->precision;
	if (data->hash == 1 && arg != 0)
		len += 2;
	if (data->width > len)
		len = data->width;
	data->total_len += len;
	return (len);
}

int	has_non_blanks(char *print, long long len)
{
	long long	i;
	long long	limit;

	i = 0;
	limit = 2 * len;
	while (i < limit)
	{
		if (print[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
