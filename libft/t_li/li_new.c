/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by enolbas           #+#    #+#             */
/*   Updated: 2022/11/18 12:19:26 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_li	*li_new(int content_one, int content_two)
{
	t_li	*li;

	li = malloc(sizeof(t_li));
	if (!li)
		return (NULL);
	li->content_one = content_one;
	li->content_two = content_two;
	li->next = NULL;
	li->prev = NULL;
	return (li);
}
