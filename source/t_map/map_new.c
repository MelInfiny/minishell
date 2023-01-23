/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:08:06 by enolbas           #+#    #+#             */
/*   Updated: 2022/12/11 15:24:36 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_map	*map_new(char *content, t_type type)
{
	t_map	*lstnew;

	lstnew = (t_map *) ft_calloc(1, sizeof(*lstnew));
	if (!lstnew)
		return (NULL);
	lstnew->content = content;
		lstnew->type = type;
	lstnew->next = NULL;
	return (lstnew);
}
