/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:08:44 by enolbas           #+#    #+#             */
/*   Updated: 2021/12/28 14:37:14 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
 * convert ascii string (str) to integer
*/

int	ft_atoi(const char *str)
{
	int		count;
	int		sign;
	long	num;

	count = 0;
	sign = 1;
	num = 0;
	while (str[count] == 32 || (str[count] >= 9 && str[count] <= 13))
		count++;
	if (str[count] == '+' || str[count] == '-')
	{
		if (str[count] == '-')
			sign *= -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		if (num * sign > 2147483647)
			return (-1);
		else if (num * sign < -2147483648)
			return (0);
		num = (num * 10) + str[count] - 48;
		count++;
	}
	return (num * sign);
}
