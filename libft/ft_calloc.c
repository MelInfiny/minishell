/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:18:05 by enolbas           #+#    #+#             */
/*   Updated: 2022/01/04 17:47:16 by enolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * allocates space for n objects of size bytes each
 * filled this bytes with zeroes
 */

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	ptr = (void *) malloc(size * n);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, (n * size));
	return (ptr);
}
