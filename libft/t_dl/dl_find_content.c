/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_find_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:07:07 by enolbas           #+#    #+#             */
/*   Updated: 2022/10/24 21:07:11 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_li	*dl_find_content(t_dl *lst, int content)
{
	t_dl	*nextl;
	size_t	i;

	i = 0;
	nextl = lst;
	if (!lst)
		return (NULL);
	while (nextl)
	{
		if (nextl->content == content)
			return (nextl->next_li);
		nextl = nextl->next;
		i++;
	}
	return (NULL);
}
