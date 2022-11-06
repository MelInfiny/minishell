/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:24:10 by enolbas           #+#    #+#             */
/*   Updated: 2021/12/28 14:36:36 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		l_src;
	int		count;
	char	*copy;

	count = 0;
	l_src = 0;
	while (s[l_src])
		l_src++;
	copy = (char *) malloc (sizeof(char) * l_src + 1);
	if (!copy)
		return (NULL);
	while (count < l_src)
	{
		copy[count] = s[count];
		count++;
	}
	copy[count] = '\0';
	return (copy);
}
