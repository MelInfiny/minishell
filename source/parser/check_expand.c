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

void	check_expand(t_input *input)
{
	t_map	*tmp;
	char	*s;

	s = NULL;
	tmp = input->lexer;
	while (tmp)
	{
		if (tmp->type == WORD || is_break(tmp->type))
		{
			s = ft_strdup(tmp->content);
			map_add(&input->parser, map_new(s, tmp->type));
		}
		tmp = tmp->next;
	}
}

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
