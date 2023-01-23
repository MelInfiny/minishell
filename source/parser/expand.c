/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:41:02 by enolbas           #+#    #+#             */
/*   Updated: 2023/01/11 19:26:51 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

char	*replace_dollar(t_input *input, char *word, int *start, t_type type)
{
	int		count;
	char	*tmp;

	count = *start;
	while (word[count + 1])
	{
		if ((switch_type(word[count + 1]) == type
				|| word[count + 1] == ' ' || word[count + 1] == '$'
				|| word[count + 1] == '\'' || word[count + 1] == '\"'))
			break ;
		count++;
	}
	if (count > *start)
	{
		tmp = ft_substr(word, *start + 1, count - *start);
		*start = count;
		if (tmp && !ft_strncmp("?", tmp, 2))
		{
			free(tmp);
			return (ft_itoa(g_status));
		}
		else if (tmp)
			return (find_in_env(input->env, tmp));
	}
	return (ft_strdup("$"));
}

char	*find_in_env(char **env, char *var)
{
	int		count;
	size_t	len;

	count = 0;
	len = ft_strlen(var);
	while (env[count])
	{
		if (!ft_strncmp(var, env[count], len) && env[count][len] == '=')
		{
			free(var);
			return (ft_substr(env[count],
					len + 1, ft_strlen(env[count])));
		}
		count ++;
	}
	free(var);
	return (ft_strdup(""));
}