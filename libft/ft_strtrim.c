/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:54:47 by enolbas           #+#    #+#             */
/*   Updated: 2021/12/28 14:24:02 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_set(char c, const char *set)
{
	int	count;

	count = 0;
	while (set[count])
	{
		if (set[count] == c)
			return (1);
		count++;
	}
	return (0);
}

char	*ft_strtrim(const char *s, const char *set)
{
	int		count;
	int		start;
	int		end;
	char	*trimstr;

	count = 0;
	start = 0;
	if (!s)
		return ((void *) 0);
	end = (int) ft_strlen(s);
	while (s[start] && is_set(s[start], set))
		start++;
	while (end > start && is_set(s[end - 1], set))
		end--;
	trimstr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!trimstr)
		return (NULL);
	while (start < end)
		trimstr[count++] = s[start++];
	trimstr[count] = '\0';
	return (trimstr);
}
