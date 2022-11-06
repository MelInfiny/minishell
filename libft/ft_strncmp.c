/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:00:50 by enolbas           #+#    #+#             */
/*   Updated: 2021/11/23 16:04:16 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	count;
	unsigned int	length;

	count = 0;
	length = (unsigned int) n;
	while (s1[count] && s2[count] && count < (length - 1)
		&& (s1[count] == s2[count]))
	{
		count++;
	}
	if (length == 0)
		return (0);
	return ((unsigned char) s1[count] - (unsigned char) s2[count]);
}
