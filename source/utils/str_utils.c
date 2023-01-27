/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:35:47 by enolbas           #+#    #+#             */
/*   Updated: 2023/01/27 09:25:32 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

size_t	ft_strdlen(char **strd)
{
	int	count;

	count = 0;
	if (!strd || !strd[0])
		return (0);
	while (strd && strd[count])
		count ++;
	return (count);
}

char	*ft_streplace(char *oldstr, char *newstr)
{
	if (oldstr)
		free(oldstr);
	oldstr = NULL;
	return (newstr);
}

void	ft_strdfree(char **strd)
{
	int	count;

	count = 0;
	while (strd[count])
	{
		free(strd[count]);
		count ++;
	}
	free(strd);
}

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

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	count;
	size_t	copy;
	char	*all;

	count = 0;
	copy = 0;
	if (!s1 && !s2)
		return (NULL);
	all = (char *) ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!all)
		return (NULL);
	while (count < ft_strlen(s1))
		all[copy++] = s1[count++];
	count = 0;
	while (count < ft_strlen(s2))
		all[copy++] = s2[count++];
	all[copy] = '\0';
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (all);
}
