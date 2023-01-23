/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idconv_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:45:32 by enolbas           #+#    #+#             */
/*   Updated: 2022/03/31 17:45:52 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_idconv_c(t_data *data, va_list *ellipse)
{
	data->c = va_arg(*ellipse, int);
	write(1, &data->c, 1);
	data->pos += 1;
	data->nbr_return += 1;
}
