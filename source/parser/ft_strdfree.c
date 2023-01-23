/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:37:26 by enolbas           #+#    #+#             */
/*   Updated: 2022/11/30 00:37:38 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	ft_strdfree(char **strd)
{
	int	count;

	count = 0;
	while (strd[count])
	{
		free(strd[count]);
		count ++;
	}
	free(strd);
}
