/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:24:05 by mjokela           #+#    #+#             */
/*   Updated: 2022/04/19 12:24:08 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	print_string(t_data *data, va_list ap)
{
	long long	len;
	char		*print;
	char		*str;

	data->unsigned_mod = (unsigned long long)va_arg(ap, unsigned long long);
	str = (char *)data->unsigned_mod;
	if (data->unsigned_mod == 0 && data->precision == 0)
		str = "";
	else if (data->unsigned_mod == 0)
		str = "(null)";
	len = ft_strlen(str);
	if (data->precision != -1 && data->precision < len)
		len = data->precision;
	if (data->width > len)
		len = data->width;
	data->total_len += len;
	print = (char *)malloc(sizeof(char) * (len * 2));
	if (print == NULL)
		exit(-1);
	set_padding_str(data, print, str, len);
	if (ft_strcmp(str, "") == 0 || data->precision == 0)
		write(1, print, len);
	else
		write_print(data, print, len, 0);
	free(print);
}

void	set_padding_str(t_data *data, char *print, char *str, int len)
{
	int	i;

	i = ft_strlen(str);
	if (data->precision != -1 && data->precision < i)
		i = data->precision;
	data->blank = 0;
	data->plus = 0;
	if (data->zero == 1)
		ft_memset(print, '0', len * 2);
	else
		ft_memset(print, ' ', len * 2);
	ft_memcpy(&print[len - i], str, i);
}

void	copy_printable(char *dst, char const *src, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len && src[i] != '\0')
	{
		if (src[i] > 31)
			dst[j++] = src[i];
		i++;
	}
}
