/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:45:30 by enolbas           #+#    #+#             */
/*   Updated: 2021/12/28 14:30:36 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * compare byte strings on the same n byte size
 *
 */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		if (*(unsigned char *)(s1 + count) != *(unsigned char *)(s2 + count))
			return (*(unsigned char *)(s1 + count)
				- *(unsigned char *)(s2 + count));
		count++;
	}
	return (0);
}
