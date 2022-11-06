/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:34:34 by enolbas           #+#    #+#             */
/*   Updated: 2022/01/04 18:04:35 by enolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t			count;
	size_t			tmp;
	char			*str;

	count = 0;
	tmp = start;
	if (!s)
		return (NULL);
	if (tmp > ft_strlen(s))
		return (ft_strdup(""));
	str = (char *) malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (count < len && tmp < ft_strlen(s))
	{
		str[count++] = s[tmp++];
	}
	str[count] = '\0';
	return (str);
}
