#include "minishell.h"

e_type	switch_type(char c, char next)
{
	if (c == '\"')
		return (DQUOTE);
	if (c == '\'')
		return (SQUOTE);
	if (c == '$')
	{
		if (next == ' ' || next == '\n')
			return (WORD);
		return (DOLLAR);
	}
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

static int	split_redir(t_input *input, char *line, int index, e_type *type)
{
	int	status;
	int	count;

	status = 0;
	count = index;
	while (line[count] && line[++count] == line[index])
		status ++;
	if (status > 1)
	{
		printf("error syntaxe unexpected token : \" %c \"", line[index]);
		exit (0);
	}
	if (status > 0)
	{
		free(ft_maplast(input->lexer)->content);
		if (*type == GREDIR)
			ft_maplast(input->lexer)->type = GRREDIR;
		if (*type == DREDIR)
			ft_maplast(input->lexer)->type = DRREDIR;
		ft_maplast(input->lexer)->content = ft_substr(line, index, 2);
	}
	return (status);
}

static void	split_delim(t_input *input, int *start, int index, e_type type)
{
	int	r;
	char	*line;

	r = index - *start;
	line = input->raw;
	if (r > 0)
		ft_addmap(&input->lexer, ft_mapnew(ft_substr(line, *start, r), WORD));
	if (type != ESPACE)
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
			if (switch_type(line[index], line[index+1]) == DOLLAR)
				split_delim(input, &start, index, DOLLAR);
		}
	}
	if (line[index] != c)
	{
		printf("error syntaxe unexpected token : \" %c \"", c);
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
		type = switch_type(line[count], line[count+1]);
		if (type != WORD)
		{
			split_delim(input, &start, count, type);
			if (type == GREDIR || type == DREDIR)
				count += split_redir(input, line, count, &type);
			if (type == SQUOTE || type == DQUOTE)
				count = split_quote(input, line, count, type);
			start = count + 1;
		}
		count ++;
	}
	if (count > start)
		ft_addmap(&input->lexer, ft_mapnew(ft_substr(line, start, count), WORD));
}
