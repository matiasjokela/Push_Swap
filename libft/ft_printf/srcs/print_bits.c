/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:06:00 by mjokela           #+#    #+#             */
/*   Updated: 2022/05/05 16:06:03 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	print_bits(t_data *data, va_list ap)
{
	long long	arg;
	int			len;
	int			arr[64];
	int			i;

	arg = check_length_mod_int(data, ap);
	i = 0;
	if (data->mod_h == 1)
		len = 16;
	else if (data->mod_hh == 1)
		len = 8;
	else if (data->mod_l == 1 || data->mod_ll == 1)
		len = 64;
	else
		len = 32;
	data -> total_len += len;
	while (i < len)
	{
		arr[i] = (arg & 1);
		arg = arg >> 1;
		i++;
	}
	while (--i >= 0)
		ft_putnbr(arr[i]);
}
