/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_modulo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:52:47 by mjokela           #+#    #+#             */
/*   Updated: 2022/04/12 14:52:52 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	print_modulo(t_data *data)
{
	int	len;

	len = 1;
	if (data->width > 0)
		len = data->width;
	if (data->minus == 1)
	{
		ft_putchar_pro('%', data, 1);
		ft_putchar_pro(' ', data, len - 1);
		return ;
	}
	if (data->zero == 1)
		ft_putchar_pro('0', data, len - 1);
	else
		ft_putchar_pro(' ', data, len - 1);
	ft_putchar_pro('%', data, 1);
}

void	ft_putchar_pro(unsigned char c, t_data *data, int i)
{
	while (i > 0)
	{
		ft_putchar(c);
		data->total_len++;
		i--;
	}
}
