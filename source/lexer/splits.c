/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_iii.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas enolbasstudent.42.fr>          	+#+  +:+      +#+    	  */
/*                                                +#+#+#+#+#+ 	+#+           */
/*   Created: 2022/12/17 04:19:37 by enolbas         #+#     #+#              */
/*   Updated: 2022/12/17 04:24:14 by enolbas        ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	split_quote(char *line, int index)
{
	char	c;

	c = line[index];
	index++;
	while (line[index] && line[index] != c)
		index++;
	if (line[index] != c)
		return (lexer_char_error(c));
	return (index);
}

int	split_dollar(t_input *input, int index)
{
	int		count;
	char	*line;

	count = index;
	line = input->raw;
	while (line[count] && line[count + 1])
	{
		if (switch_type(line[count + 1]) != WORD)
			break ;
		count ++;
	}
	if (line[count + 1] == '$' && count == index)
		return (lexer_char_error(line[count]));
	return (count);
}

int	split_redir(t_input *input, char *line, int index, t_type type)
{
	int	status;
	int	count;

	status = 0;
	count = index;
	while (line[count] && line[++count] == line[index])
		status ++;
	if (status > 1)
	{
		lexer_char_error(line[index]);
		return ((index + 1) * (-1));
	}
	if (status > 0)
	{
		free(map_last(input->lexer)->content);
		if (type == GREDIR)
			map_last(input->lexer)->type = GRREDIR;
		if (type == DREDIR)
			map_last(input->lexer)->type = DRREDIR;
		(map_last(input->lexer))->content = ft_substr(line, index, 2);
	}
	return (status);
}

void	split_delim(t_input *input, int *start, int index, t_type type)
{
	int		r;
	char	*line;

	r = index - *start;
	line = input->raw;
	if (r > 0)
		map_add(&input->lexer, map_new(ft_substr(line, *start, r), WORD));
	if (type != ESPACE)
		map_add(&input->lexer, map_new(ft_substr(line, index, 1), type));
	*start = index + 1;
}
