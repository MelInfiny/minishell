/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:54:56 by enolbas           #+#    #+#             */
/*   Updated: 2023/01/23 17:55:23 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node	*new_node(void)
{
	t_node	*node;

	node = (t_node *) ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->redir = NULL;
	return (node);
}

t_redir	*new_redir(int status, char *file)
{
	t_redir	*redir;

	redir = (t_redir *) ft_calloc(1, sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = status;
	redir->file = file;
	return (redir);
}