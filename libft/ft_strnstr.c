/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:21:51 by enolbas           #+#    #+#             */
/*   Updated: 2022/01/04 18:03:58 by enolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t size)
{
	size_t	count;
	size_t	search;

	if (find[0] == '\0')
		return ((char *)s);
	count = 0;
	while (s[count] && count < size)
	{
		search = 0;
		while (((count + search) < size) && (s[count + search] == find[search]))
		{
			search++;
			if (find[search] == '\0')
				return ((char *)s + count);
		}
		count++;
	}
	return ((void *)0);
}
