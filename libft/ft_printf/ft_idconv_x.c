/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idconv_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:36:17 by enolbas           #+#    #+#             */
/*   Updated: 2022/03/31 17:36:53 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_idconv_x(t_data *data, va_list *ellipse)
{
	data->u = va_arg(*ellipse, unsigned int);
	ft_putnbr_hexa(data->u, data);
	data->pos += 1;
}
