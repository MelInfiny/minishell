/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:41:13 by enolbas           #+#    #+#             */
/*   Updated: 2023/01/31 17:06:59 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	slen;
	size_t	jlen;
	size_t	i;
	size_t	j;
	char	*res;

	slen = ft_strlen(s1);
	jlen = ft_strlen(s2);
	res = (char *) malloc((slen + jlen + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < slen)
		res[i] = s1[i];
	j = -1;
	while (++j < jlen)
		res[i++] = s2[j];
	res[i] = '\0';
	return (res);
}
