/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:19:01 by enolbas           #+#    #+#             */
/*   Updated: 2021/12/11 21:19:10 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int caractere)
{
	if (caractere == 0)
		return (1);
	if (caractere > 0 && caractere < 128)
		return (caractere);
	return (0);
}
