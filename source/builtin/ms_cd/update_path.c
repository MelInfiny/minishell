/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:09:20 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/15 09:31:30 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	free_function_all(char **stock);

int	update_path(const char *path, char **path_update, t_input *input)
{
	char	pwd[PATH_MAX];
	char	*save_for_free;
	char	*stock;

	(void) input;
	pwd[0] = 0;
	if (!getcwd(pwd, PATH_MAX))
	{
		perror("getcwd");
		return (1);
	}
	if (access(path, F_OK) > -1)
	{
		save_for_free = *path_update;
		*path_update = ft_strdup(path);
		return (0);
	}
	save_for_free = *path_update;
	stock = ft_strjoin("/", path);
	if (!stock)
		return (1);
	*path_update = ft_strjoin(pwd, stock);
	if (!*path_update)
		return (free_function_all(&stock));
	*path_update = remove_point(*path_update);
	free(stock);
	free(save_for_free);
	return (0);
}

static int	free_function_all(char **stock)
{
	free(*stock);
	return (1);
}