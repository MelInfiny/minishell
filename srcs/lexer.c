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
		count ++;
	}
	if (line[count] != c)
	{
		ft_putstr_fd("Error : unclosed quote\n", 2);
		exit(0);
	}
	s = ft_substr(line, *start, count + 1);
	*start = count + 1;
	return (s);
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
		if (c == '\'' || c == '\"')
		{
			if (count - start > count)
				ft_addmap(&input->lexer, ft_mapnew(ft_substr(line, start, count - 1), WORD));
			if (c == '\'')
				ft_addmap(&input->lexer, ft_mapnew(search(line, &count), SQUOTE));
			if (c == '\"')
				ft_addmap(&input->lexer, ft_mapnew(search(line, &count), DQUOTE));
			start = count + 1;
		}
		count ++;
	}
}
