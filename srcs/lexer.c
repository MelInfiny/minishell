#include "minishell.h"

e_type	switch_type(char c)
{
	if (c == '\"')
		return (DQUOTE);
	if (c == '\'')
		return (SQUOTE);
	if (c == '$' )
		return (DOLLAR);
	if (c == ' ' || c == '\n' || c == '|' || c == '<' || c == '>')
		return (DELIM);
	return (WORD);
}

static void	split_delim(t_input *input, int *start, int index, e_type type)
{
	int	r;
	char	*line;

	r = index - *start;
	line = input->raw;
	if (r > 0)
		ft_addmap(&input->lexer, ft_mapnew(ft_substr(line, *start, r), WORD));
	ft_addmap(&input->lexer, ft_mapnew(ft_substr(line, index, 1), type));
	*start = index + 1;
}

static int	split_quote(t_input *input, char *line, int index, e_type type)
{
	int	start;
	char	c;

	c = line[index];
	start = index + 1;
	while (line[index] && line[++index] != c)
	{
		if (c == '\"')
		{
			if (line[index] == '$')
				split_delim(input, &start, index, DOLLAR);
		}
	}
	if (line[index] != c)
	{
		ft_putstr_fd("Error : unclosed quote\n", 2);
		exit(0);
	
	}
	split_delim(input, &start, index, type);
	return (index);
}

void	ft_lexer(t_input *input, char *line)
{
	int		count;
	int		start;
	e_type		type;

	count = 0;
	start = 0;
	while (line[count])
	{
		type = switch_type(line[count]);
		if (type != WORD)
		{
			split_delim(input, &start, count, type);
			if (type == SQUOTE || type == DQUOTE)
			{
				count = split_quote(input, line, count, type);
				start = count + 1;
			}
		}
		count ++;
	}
	if (count > start)
		ft_addmap(&input->lexer, ft_mapnew(ft_substr(line, start, count), WORD));
}
