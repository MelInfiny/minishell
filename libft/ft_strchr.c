/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:31:43 by enolbas           #+#    #+#             */
/*   Updated: 2021/12/28 14:32:17 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * search the first occurence of caractere into the string (s)
 * include the null terminating '\0' in the research
 */

#include "libft.h"

char	*ft_strchr(const char *s, int caractere)
{
	int	count;

	count = 0;
	while (s[count])
	{
		if (s[count] == (char) caractere)
			return ((char *)(s + count));
		count++;
	}
	if (s[count] == (char) caractere)
		return ((char *)(s + count));
	return ((void *) 0);
}
