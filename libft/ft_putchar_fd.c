/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:01:21 by enolbas           #+#    #+#             */
/*   Updated: 2022/03/16 12:43:28 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// CREE UN FICHIER "test.txt" //

int		main(void)
{
	int		fd;
	char	buf[128];
	int		size;
	
	fd = open("test.txt", O_RDWR);
	if (fd == -1)
		return (1);
	size = read(fd, buf, 127);
	write(1, "\n", 1);
	write(1, buf, size);
	write(1, "\n\n", 2);
	buf[size] = 0;

	ft_putchar_fd('t', fd);

	close(fd);
	return (0);
}
*/
