/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:35:03 by enolbas           #+#    #+#             */
/*   Updated: 2022/01/04 17:54:49 by enolas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_sep(char c, char set)
{
	if (c == set)
		return (1);
	return (0);
}

static char	*create_word(const char *s, int start, int end)
{
	char	*word;
	int		count;

	count = 0;
	word = (char *) malloc(sizeof(char) * (end - start) + 1);
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[count++] = s[start++];
	}
	word[count] = '\0';
	return (word);
}

static unsigned int	ft_strslen(const char *s, char set)
{
	unsigned int	len;
	int				count;

	count = 0;
	len = 0;
	while (s[count])
	{
		while (is_sep(s[count], set) && s[count])
			count++;
		if (!is_sep(s[count], set) && s[count])
		{
			len++;
			while (!is_sep(s[count], set) && s[count])
				count++;
		}
	}
	return (len);
}

static void	ft_split2(const char *s, char set, char **words)
{
	int	start;
	int	count;
	int	nbr;

	count = 0;
	nbr = 0;
	while (s[count])
	{
		while (is_sep(s[count], set) && s[count])
			count++;
		if (!is_sep(s[count], set) && s[count])
		{
			start = count;
			while (!is_sep(s[count], set) && s[count])
				count++;
			words[nbr++] = create_word(s, start, count);
		}
	}
	words[nbr] = NULL;
}

char	**ft_split(const char *s, char set)
{
	char	**words;

	if (!s)
		return (NULL);
	words = (char **) ft_calloc(sizeof(char *), ft_strslen(s, set) + 1);
	if (!words)
		return (NULL);
	if (ft_strslen(s, set) == 0)
		words[0] = NULL;
	else
		ft_split2(s, set, words);
	return (words);
}
