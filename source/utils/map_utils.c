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

t_map	*map_last(t_map *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	map_delone(t_map *lst, void (*del)(void*))
{
	if (!del || !lst)
		return ;
	if (lst->content)
		del(lst->content);
	free(lst);
}

void	map_clear(t_map **lst, void (*del)(void *))
{
	t_map	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		map_delone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
