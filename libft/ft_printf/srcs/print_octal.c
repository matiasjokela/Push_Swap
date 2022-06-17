/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:39:29 by mjokela           #+#    #+#             */
/*   Updated: 2022/04/12 15:39:32 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	print_octal(t_data *data, va_list ap)
{
	long long			len;
	char				*print;
	char				*oct_str;
	unsigned long long	arg;

	check_length_mod_uint(data, ap);
	arg = data->unsigned_mod;
	if (data->hash == 0 && arg == 0 && data->precision == 0 && data->width == 0)
		return ;
	if (arg == 0 && data->hash == 1)
		data->hash = 2;
	oct_str = ft_ltoau_base(arg, 8, data);
	len = arg_len_uint(data, arg, oct_str);
	print = (char *)malloc(sizeof(char) * (len * 2));
	if (print == NULL)
		exit(-1);
	set_padding_octal(data, print, oct_str, len);
	if (has_non_blanks(print, len) == 0)
		data->zero = 1;
	write_print(data, print, len, 0);
	free(oct_str);
	free(print);
}

char	*ft_ltoau_base(unsigned long long n, int base, t_data *data)
{
	int		i;
	char	*hex;
	char	stri[65];

	if (base < 2 || base > 16)
		return (NULL);
	i = 63;
	if (data->conversion == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	ft_bzero(stri, 65);
	while (n / base != 0)
	{
		stri[i--] = hex[n % base];
		n = n / base;
	}
	stri[i] = hex[n % base];
	return (ft_strdup(&stri[i]));
}

void	set_padding_octal(t_data *data, char *print, char *o_str, int len)
{
	int	i;
	int	precision;

	i = ft_strlen(o_str);
	precision = data->precision - i;
	if (data->zero == 1)
		ft_memset(print, '0', len * 2);
	else
		ft_memset(print, ' ', len * 2);
	if (!(data->precision == 0 && data->unsigned_mod == 0 && data->width != 0 \
	&& data->hash == 0))
		ft_memcpy(&print[len - i], o_str, i);
	if (data->hash == 1)
		print[len - i - 1] = '0';
	if (precision > 0)
		ft_memset(&print[len - i - precision], '0', precision);
}
