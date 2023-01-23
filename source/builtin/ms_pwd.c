/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:58:37 by enolbas           #+#    #+#             */
/*   Updated: 2022/12/15 09:30:48 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	ms_pwd(void)
{
	char	pwd[PATH_MAX];

	pwd[0] = 0;
	if (!getcwd(pwd, PATH_MAX))
	{
		perror("getcwd");
		return (1);
	}
	if (!*pwd)
		return (1);
	ft_printf("%s\n", pwd);
	return (0);
}
