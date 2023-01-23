/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:19:08 by enolbas           #+#    #+#             */
/*   Updated: 2022/11/24 13:54:59 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ls_clear(t_ls **lst)
{
	t_ls	**copyls;
	t_ls	*copyls_two;

	copyls = lst;
	if (!*lst)
		return ;
	while (*copyls)
	{
		copyls_two = (*copyls)->next;
		free((*copyls)->content_one);
		free(*copyls);
		*copyls = copyls_two;
	}
	*lst = NULL;
}
