/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_streplace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:24:26 by enolbas           #+#    #+#             */
/*   Updated: 2022/11/30 00:24:41 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

char	*ft_streplace(char *oldstr, char *newstr)
{
	if (oldstr)
		free(oldstr);
	oldstr = NULL;
	return (newstr);
}
