/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:32:35 by enolbas           #+#    #+#             */
/*   Updated: 2022/11/11 23:29:30 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t n, size_t size);

size_t	ft_strlen2(const char *s)
{
	size_t	count;

	count = 0;
	if (!s || s[count] == '\0')
		return (0);
	while (s[count])
		count++;
	return (count);
}

char	*ft_strjoin2(char *s1, char const *s2)
{
	size_t	count;
	size_t	copy;
	size_t	len;
	char	*all;

	count = 0;
	copy = 0;
	len = ft_strlen2(s1);
	if (!s1 && !s2)
		return (NULL);
	all = (char *) ft_calloc(len + ft_strlen2(s2) + 1, sizeof(char));
	if (!all)
		return (NULL);
	while (count < len)
		all[copy++] = s1[count++];
	count = 0;
	while (count < ft_strlen2(s2))
		all[copy++] = s2[count++];
	all[copy] = '\0';
	if (len > 0)
		free(s1);
	return (all);
}

char	*ft_substr2(const char *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	tmp;
	size_t	size;
	char	*str;

	count = 0;
	tmp = start;
	if (!s)
		return (NULL);
	size = ft_strlen2(s);
	if (tmp > size)
		return (ft_strjoin2("", ""));
	str = (char *) ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (count < len && tmp < size)
	{
		str[count++] = s[tmp++];
	}
	str[count] = '\0';
	return (str);
}
