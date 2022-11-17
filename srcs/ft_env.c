/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:28:30 by enolbas           #+#    #+#             */
/*   Updated: 2022/11/15 22:46:18 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	**ft_strdcpy(char **strd)
{
	char	**newstrd;
	int		count;

	newstrd = (char **) calloc(ft_strdlen(strd) + 1, sizeof(char *));
	if (!strd)
		return (NULL);
	count = 0;
	while (strd[count])
	{
		newstrd[count] = strd[count];
		count ++;
	}
	newstrd[count] = NULL;
	return (newstrd);
}

int	ft_env(char **env)
{
	int	count;

	count = 0;
	while (env[count])
	{
		ft_printf("%s\n", env[count]);
		count ++;
	}
	return (0);
}

char	*find_varenv(t_input *input, t_quote *q, char *line)
{
	int		count;
	char	*varenv;
	char	*buff;

	count = 0;
	buff = ft_substr(line, q->start + 1, q->end);
	while (input->env[count])
	{
		if (ft_findstr(input->env[count], buff))
		{
			varenv = ft_substr(input->env[count], ft_strlen(buff) + 1, ft_strlen(input->env[count]));
			free(buff);
			q->pair = true;
			return (varenv);
		}
		count ++;
	}
	free(buff);
	q->pair = false;
	return (ft_strdup(""));
}
