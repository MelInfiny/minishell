#include "minishell.h"

bool	is_delim(char c)
{
	if (c == ' ' || c == '\n' || c == '|' || c == '<' || c == '>')
		return (true);
	return (false);
}

int	search_d(char *line, int index)
{
	int	count;

	count = index;
	while (line[count] == line[index])
		count ++;
	return (count);
}

void	find_delim(t_input *input, char *line)
{
	int	count;

	count = 0;
	index = 0;
	while (line[count])
	{
		if (is_delim(c))
		{
			ft_addmap(input->parser, ft_mapnew(ft_substr(tmp->content, index, count), CMD);
			cmd = ft_substr(tmp->content, index, ft_strlen(tmp->content) - count);
			ft_addmap(input->parser, ft_mapnew(cmd, ARG));
			

			ft_addmap(input->parser, ft_mapnew(ft_substr(line, index, count - index + 1), ));
			index = search_d(line, count);
			ft_substr(line, count, index - count);
			count = index;
		}
		else
			count ++;
	}
}

t_map	*parser_first(t_input *input)
{
	t_map	*tmp;
	char	*cmd;

	tmp = input->lexer;
	if (tmp->type == SQUOTE || tmp->type == DQUOTE)
	{
		cmd = ft_substr(tmp->content, 1, ft_strlen(tmp->content) - 1);
		ft_addmap(input->parser, ft_mapnew(cmd, CMD));
	}
	else (tmp->type == WORD)
	{
		while (tmp->content[count] && !is_delim(tmp->content[count]))
			count ++;
		cmd = ft_substr(tmp->content, count, ft_strlen(tmp->content) - count);
		ft_addmap(input->parser, ft_mapnew(ft_substr(tmp->content, 0, count), CMD);
		ft_addmap(input->parser, ft_mapnew(cmd, ARG));

	}
	free(cmd);
}
