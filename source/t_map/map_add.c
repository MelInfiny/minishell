/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:16:33 by enolbas           #+#    #+#             */
/*   Updated: 2022/12/12 18:52:31 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	map_add(t_map **lst, t_map *new)
{
	t_map	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		(*lst)->key = 0;
		return ;
	}
	tmp = map_last(*lst);
	tmp->next = new;
	tmp->next->key = tmp->key + 1;
}
