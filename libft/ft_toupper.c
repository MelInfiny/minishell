/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:55:32 by enolbas           #+#    #+#             */
/*   Updated: 2021/11/23 15:57:08 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int caractere)
{
	if (caractere >= 'a' && caractere <= 'z')
		caractere -= 32;
	return (caractere);
}
