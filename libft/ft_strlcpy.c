/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:41:19 by enolbas           #+#    #+#             */
/*   Updated: 2021/11/23 15:43:59 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	len;

	len = 0;
	if (!size)
	{
		while (src[len])
			len++;
		return (len);
	}
	while (--size && src[len])
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (ft_strlen(src));
}
