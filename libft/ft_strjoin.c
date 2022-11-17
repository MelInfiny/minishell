/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:34:41 by enolbas           #+#    #+#             */
/*   Updated: 2021/12/11 21:27:13 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen2(char *str);
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	count;
	size_t	copy;
	char	*all;

	count = 0;
	copy = 0;
	if (!s1 || !s2)
		return (NULL);
	all = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!all)
		return (NULL);
	all[0] = '\0';
	while (count < ft_strlen(s1))
		all[copy++] = s1[count++];
	count = 0;
	while (count < ft_strlen(s2))
		all[copy++] = s2[count++];
	all[copy] = '\0';
	return (all);
}

char	*ft_charjoin(char *s1, char c)
{
	size_t	count;
	size_t	len;
	char	*all;

	count = 0;
	if (!s1)
		len = 0;
	else
		len = ft_strlen2(s1);
	all = (char *) ft_calloc(len + 2, sizeof(char));
	while (s1[count])
	{
		all[count] = s1[count];
		count ++;
	}
	all[count] = c;
	if (len > 0)
		free(s1);
	return (all);
}
