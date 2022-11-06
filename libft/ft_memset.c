/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:12:41 by enolbas           #+#    #+#             */
/*   Updated: 2021/12/28 14:28:24 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * write n bytes of c value into the string (s)
 */

#include "libft.h"

void	*ft_memset(void	*s, int c, size_t n)
{
	size_t		count;

	count = 0;
	while (count < n)
	{
		*(unsigned char *)(s + count) = (unsigned char) c;
		count++;
	}
	return (s);
}
