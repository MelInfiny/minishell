/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:55:29 by enolbas           #+#    #+#             */
/*   Updated: 2023/01/23 13:00:52 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_int(int nbr, t_data *data)
{
	if (nbr == -2147483648)
	{
		if (write(1, "-2147483648", 11) != -1)
			data->nbr_return += 11;
	}
	else
	{
		if (nbr < 0)
		{
			nbr *= -1;
			if (write(1, "-", 1) != -1)
				data->nbr_return += 1;
		}
		if (nbr > 9)
			ft_putnbr_int(nbr / 10, data);
		ft_putchar(nbr % 10 + '0', data);
	}
}
