/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:22:37 by mjokela           #+#    #+#             */
/*   Updated: 2022/04/19 12:22:41 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	print_char(t_data *data, va_list ap)
{
	long long		len;
	char			*print;
	unsigned char	c;

	data->unsigned_mod = (unsigned char)va_arg(ap, int);
	data->precision = -1;
	data->plus = 0;
	data->blank = 0;
	c = data->unsigned_mod;
	len = 1;
	if (data->width > len)
		len = data->width;
	data->total_len += len;
	print = (char *)malloc(sizeof(char) * (len * 2));
	if (print == NULL)
		exit(-1);
	if (data->zero == 1)
		ft_memset(print, '0', len * 2);
	else
		ft_memset(print, ' ', len * 2);
	print[len - 1] = c;
	if (has_non_blanks(print, len) == 0 && c != 0)
		data->zero = 1;
	write_print(data, print, len, 0);
	free(print);
}
