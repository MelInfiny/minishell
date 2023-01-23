/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env_in_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:47:36 by enolbas           #+#    #+#             */
/*   Updated: 2022/12/07 20:14:37 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	free_function_all(t_input *input);

int	copy_env_in_export(t_input *input)
{
	int	i;

	i = 0;
	if (!input->env)
		return (0);
	while ((input->env)[i])
	{
		if (ls_add_back(&(input->export), ls_new(ft_strdup((input->env)[i]))))
			return (free_function_all(input));
		i++;
	}
	return (0);
}

static int	free_function_all(t_input *input)
{
	ls_clear(&(input->export));
	return (1);
}
