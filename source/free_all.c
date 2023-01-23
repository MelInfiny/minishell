/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:56:49 by enolbas           #+#    #+#             */
/*   Updated: 2022/12/12 17:27:56 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	free_all(t_input *input)
{
	int	i;

	i = 0;
	if (input->env && *(input->env))
		while ((input->env)[i])
			free((input->env)[i++]);
	if (input->env)
		free(input->env);
	ls_clear(&(input->export));
	rl_clear_history();
	return (0);
}
