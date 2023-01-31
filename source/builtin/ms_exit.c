/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:08:30 by enolbas           #+#    #+#             */
/*   Updated: 2023/01/31 18:12:41 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	ms_exit(t_input *input, int exit_status)
{
	ft_putstr_fd("exit\n", 2);
	free_input(input);
	free_all(input);
	if (exit_status > 0 && exit_status < 255)
		exit(exit_status);
	else
		exit(0);
}
