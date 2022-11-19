#include "minishell.h"

static char	*search(char *line, int *start)
{
	int		count;
	char	*s;
	char	c;

	count = *start;
	c = line[*start];
	while (line[++count])
	{
		if (c == line[count])
			break;
	}
	if (line[count] != c)
	{
		ft_putstr_fd("Error : unclosed quote\n", 2);
		exit(0);
	}
	s = ft_substr(line, *start, count - *start + 1);
	*start = count;
	return (s);
}

bool	is_delim(char c)
{
	if (c == ' ' || c == '\n' || c == '|' || c == '<' || c == '>' || c == '$')
		return (true);
	return (false);
}

void	ft_lexer(t_input *input, char *line)
{
	int		count;
	int		start;
	char	c;

	count = 0;
	start = 0;
	while (line[count])
	{
		c = line[count];
		if (is_delim(c))
		{
			ft_addmap(&input->lexer, ft_mapnew(ft_substr(line, start, count - start, WORD)));
			ft_addmap(&input->lexer, ft_mapnew(ft_substr(line, count, 1, DELIM)));
			start = count + 1;
		}
		if (c == '\'' || c == '\"')
		{
			if (count - start > 0)
				ft_addmap(&input->lexer, ft_mapnew(ft_substr(line, start, count - start), WORD));
			if (c == '\'')
				ft_addmap(&input->lexer, ft_mapnew(search(line, &count), SQUOTE));
			else if (c == '\"')
				ft_addmap(&input->lexer, ft_mapnew(search(line, &count), DQUOTE));
			start = count + 1;
		}
		count ++;
	}
}
