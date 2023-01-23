/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:03:29 by enolbas           #+#    #+#             */
/*   Updated: 2023/01/11 18:34:55 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	ft_cmd_error(t_list *cmd, char *message)
{
	t_node	*node;

	if (cmd)
	{
		node = cmd->content;
		ft_putstr_fd(node->args[0], 2);
	}
	if (message)
		perror(message);
	return (0);
}
