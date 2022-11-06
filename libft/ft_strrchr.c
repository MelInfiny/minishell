/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:28:33 by enolbas           #+#    #+#             */
/*   Updated: 2021/12/28 14:32:55 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * search the last occurence of a caractere into the string (s)
 * include the null terminating caractere '\0'
 */

#include "libft.h"

char	*ft_strrchr(const char *s, int caractere)
{
	int	count;

	count = ft_strlen(s);
	while (count >= 0)
	{
		if (s[count] == (char) caractere)
			return ((char *)(s + count));
		count--;
	}
	return ((void *) 0);
}
