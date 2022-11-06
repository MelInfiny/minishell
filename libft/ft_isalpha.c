/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:18:25 by enolbas           #+#    #+#             */
/*   Updated: 2021/12/11 21:20:25 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int caractere)
{
	if ((caractere >= 65 && caractere <= 90)
		|| (caractere >= 97 && caractere <= 122))
		return (caractere);
	return (0);
}
