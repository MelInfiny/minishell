/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:27:58 by enolbas           #+#    #+#             */
/*   Updated: 2021/12/12 11:32:09 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * copies n bytes from src's memory area to dest's memory area 
 *
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	count;

	count = 0;
	if (!dest && !src)
		return (NULL);
	while (count < n)
	{
		*(char *)(dest + count) = *(char *)(src + count);
		count++;
	}
	return (dest);
}
