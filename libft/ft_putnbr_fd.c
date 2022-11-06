/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:39:20 by enolbas           #+#    #+#             */
/*   Updated: 2021/12/28 14:31:32 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	if (n < 0)
	{
		nbr = (long int) n * (-1);
		ft_putchar_fd('-', fd);
	}
	else
		nbr = (long int) n;
	if (nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	nbr %= 10;
	ft_putchar_fd('0' + nbr, fd);
}
