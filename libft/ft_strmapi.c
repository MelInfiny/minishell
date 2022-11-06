/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 09:27:31 by enolbas           #+#    #+#             */
/*   Updated: 2022/01/04 17:57:04 by enolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * applies the f function to the string s
 * create a new function with the result
 */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		count;
	char	*str;

	count = 0;
	if (!s || !f)
		return ((void *)0);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	while (s[count])
	{
		str[count] = f(count, s[count]);
		count++;
	}
	str[count] = '\0';
	return (str);
}
