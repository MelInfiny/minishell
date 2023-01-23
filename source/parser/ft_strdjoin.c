/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:34:16 by enolbas           #+#    #+#             */
/*   Updated: 2022/11/30 00:34:31 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

char	**ft_strdjoin(char **strd, char *s)
{
	char	**newd;
	int		strdlen;
	int		count;

	strdlen = 0;
	if (strd)
		strdlen = ft_strdlen(strd);
	newd = ft_calloc(strdlen + 2, sizeof(char *));
	if (!newd)
		return (NULL);
	count = 0;
	while (strd && strd[count])
	{
		newd[count] = ft_strdup(strd[count]);
		count ++;
	}
	newd[count] = ft_strdup(s);
	if (strd)
		ft_strdfree(strd);
	strd = NULL;
	return (newd);
}
