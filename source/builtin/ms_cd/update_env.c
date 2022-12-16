/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:07:29 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/15 09:31:58 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	update_env(const char *str, t_input *input)
{
	char	*stock;
	char	pwd[PATH_MAX];

	pwd[0] = 0;
	if (!getcwd(pwd, PATH_MAX))
	{
		perror("getcwd");
		return (1);
	}
	stock = ft_strjoin("PWD=", pwd);
	if (ms_export(stock, input))
	{
		free(stock);
		return (1);
	}
	(void) str;
	free(stock);
	return (0);
}
