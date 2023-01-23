/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:19:11 by enolbas           #+#    #+#             */
/*   Updated: 2023/01/23 15:19:13 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_type	switch_type(char c)
{
	if (c == '\"')
		return (DQUOTE);
	if (c == '\'')
		return (SQUOTE);
	if (c == '$')
		return (DOLLAR);
	if (c == ' ')
		return (ESPACE);
	if (c == '|')
		return (PIPE);
	if (c == '<')
		return (GREDIR);
	if (c == '>')
		return (DREDIR);
	return (WORD);
}

static int	split_type(t_input *input, int *count, int *start, char *line)
{
	t_type	type;

	type = switch_type(line[*count]);
	if (type == SQUOTE || type == DQUOTE || type == DOLLAR)
	{
		if (type == DOLLAR)
			*count = split_dollar(input, *count);
		else
			*count = split_quote(line, *count);
	}
	else if (type != WORD)
	{
		split_delim(input, start, *count, type);
		if (type == GREDIR || type == DREDIR)
			*count += split_redir(input, line, *count, type);
		if (*count >= 0)
			*start = *count + 1;
	}
	return (*count);
}

static void	add_lexer(t_input *input, char *line, int count, int start)
{
	if (count > start)
		map_add(&input->lexer,
			map_new(ft_substr(line, start, count), WORD));
}

int	lexer(t_input *input, char *line)
{
	int		count;
	int		start;

	count = 0;
	start = 0;
	while (line[count])
	{
		if (split_type(input, &count, &start, line) < 0)
			return (0);
		count += !!line[count];
	}
	add_lexer(input, line, count, start);
	return (1);
}