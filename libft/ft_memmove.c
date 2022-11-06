/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:48:01 by enolbas           #+#    #+#             */
/*   Updated: 2021/12/28 14:17:54 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/**
 * copies n bytes from src's memory area to dest's memory area
 * even if there is an overleap, no parts are loose in the copy 
 *
 */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	count;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		count = (int) n;
		while (count--)
			*(unsigned char *)(dest + count) = *(unsigned char *)(src + count);
	}
	else
		dest = ft_memcpy(dest, src, n);
	return (dest);
}
