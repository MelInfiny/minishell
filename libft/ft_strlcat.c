/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:52:24 by enolbas           #+#    #+#             */
/*   Updated: 2022/01/04 17:56:06 by enolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * concate the string src to the string dest after terminating charactere '\0'
 *
 */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	c_2;
	size_t			c_1;
	size_t			l_src;
	size_t			l_dest;

	c_2 = 0;
	c_1 = ft_strlen(dest);
	l_dest = ft_strlen(dest);
	l_src = ft_strlen(src);
	if (size > l_dest)
	{
		while (src[c_2] && (c_1 < size - 1))
			dest[c_1++] = src[c_2++];
		dest[c_1] = '\0';
		return (l_dest + l_src);
	}
	return (size + l_src);
}
