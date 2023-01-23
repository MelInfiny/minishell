/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_tab_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:53:09 by enolbas           #+#    #+#             */
/*   Updated: 2022/11/18 11:03:25 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	my_tab_reverse(int *tab, size_t size)
{
	int	i;
	int	stock;

	i = 0;
	while (size - 1 > (size - 1) / 2)
	{
		stock = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = stock;
		size--;
	}
}
