/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_off.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:10:02 by enolbas           #+#    #+#             */
/*   Updated: 2022/12/14 12:36:55 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	handler_off(int sig)
{
	int	return_write;

	return_write = 0;
	(void) return_write;
	if (sig == 2)
	{
		return_write = write(1, "\n", 1);
		return ;
	}
	if (sig == 3)
		return ;
}
