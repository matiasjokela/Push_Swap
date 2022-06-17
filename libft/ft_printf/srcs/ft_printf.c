/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:06:07 by mjokela           #+#    #+#             */
/*   Updated: 2022/03/20 15:06:10 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_data	*data;
	int		len;

	va_start(ap, format);
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (-1);
	data->total_len = 0;
	read_and_write(format, ap, data);
	va_end(ap);
	len = data->total_len;
	free(data);
	return (len);
}

void	read_and_write(const char *format, va_list ap, t_data *data)
{
	char	*mod;
	int		i;

	i = 0;
	while (1)
	{
		mod = ft_strchr(&format[i], '%');
		if (mod != NULL)
		{
			write(1, &format[i], mod - &format[i]);
			data->total_len += mod - &format[i];
			i += mod - &format[i];
		}			
		else
		{
			mod = ft_strchr(&format[i], '\0');
			write(1, &format[i], mod - &format[i]);
			data->total_len += mod - &format[i];
			break ;
		}
		if (convert(format, &i, data, ap) == 1)
			dispatch(data, ap);
	}
}

void	set_padding(t_data *data, char *print, char *num_str, int len)
{
	int	i;
	int	precision;

	i = ft_strlen(num_str);
	precision = data->precision - i;
	if (data->zero == 1)
		ft_memset(print, '0', len * 2);
	else
		ft_memset(print, ' ', len * 2);
	if (data->signed_mod == 0 && data->precision == 0)
			print[len - 1] = ' ';
	else
		ft_memcpy(&print[len - i], num_str, i);
	if (precision > 0)
		ft_memset(&print[len - i - precision], '0', precision);
}

void	write_print(t_data *data, char *print, int len, int i)
{
	if (data->zero == 1)
	{
		if (data->signed_mod < 0)
			print[0] = '-';
		else if (data->plus == 1)
			print[0] = '+';
		else if (data->blank == 1)
			print[0] = ' ';
		write(1, print, len);
	}
	else
	{
		while (print[i] == ' ' && i < (len * 2) - 1)
			i++;
		if (data->signed_mod < 0)
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
