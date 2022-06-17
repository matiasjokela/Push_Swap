/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:23:40 by mjokela           #+#    #+#             */
/*   Updated: 2022/04/19 12:23:46 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	print_pointer(t_data *data, va_list ap)
{
	long long			len;
	char				*print;
	char				*pstr;
	unsigned long long	arg;

	data->unsigned_mod = (unsigned long long)va_arg(ap, unsigned long long);
	arg = data->unsigned_mod;
	pstr = ft_ltoau_base(arg, 16, data);
	len = ft_strlen(pstr) + 2;
	if (data->width > len)
		len = data->width;
	if (data->precision > len)
		len = data->precision;
	if (len == data->precision)
		len += 2;
	if (data->width == 0 && data->precision == 0 && arg == 0)
		len = 2;
	data->total_len += len;
	print = (char *)malloc(sizeof(char) * (len * 2));
	if (print == NULL)
		exit(-1);
	set_padding_pointer(data, print, pstr, len);
	write_print(data, print, len, 0);
	free(pstr);
	free(print);
}

void	set_padding_pointer(t_data *data, char *print, char *pstr, int len)
{
	int	i;
	int	precision;

	if (data->width == 0 && data->precision == 0 && data->unsigned_mod == 0)
	{
		print[0] = '0';
		print[1] = 'x';
		return ;
	}
	i = ft_strlen(pstr);
	precision = data->precision - i;
	data->blank = 0;
	data->plus = 0;
	ft_memset(print, ' ', len * 2);
	ft_memcpy(&print[len - i], pstr, i);
	if (precision > 0)
		ft_memset(&print[len - i - precision], '0', precision);
	if (precision > 0)
		i = len - i - precision;
	else
		i = len - i;
	print[i - 2] = '0';
	print[i - 1] = 'x';
}
