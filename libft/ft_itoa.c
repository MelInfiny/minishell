/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 09:57:19 by enolbas           #+#    #+#             */
/*   Updated: 2021/12/28 14:31:19 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/**
 * *
 * converts the integer argument into his representative string
 * 
 */

static int	ft_numlen(int n)
{
	int				len;
	unsigned int	nbr;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len ++;
		nbr = -n;
	}
	else
		nbr = n;
	while (nbr)
	{
		nbr /= 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				len;
	char			*res;

	len = ft_numlen(n);
	res = (char *) malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		nbr = -n;
		res[0] = '-';
	}
	else
		nbr = n;
	while (nbr > 0)
	{
		res[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}
