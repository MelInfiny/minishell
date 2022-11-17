#include "minishell.h"

/** 
 * pair is true if we need to interprete between the quote s*/
static void	set_quote(t_quote *q, int s, int e)
{
	if (e - s > 1)
	{
		q->start = s + 1;
		q->end = e - 1;
		q->pair = true;
	}
	else
	{
		q->start = 0;
		q->end = 0;
		q->pair = false;
	}
}

/**
 * Return 1 if there is a single quote open*/
int	search_c(char *line, int start, char c)
{
	int		count;

	count = start;
	while (line[count])
	{
		if (line[count] == c)
			return (count);
		count ++;
	}
	return (-1);
}

static char	*handle_quotes(t_input *input, char *line, int *index)
{
	int		res;
	char		*tmp;
	t_quote		q;

	res = search_c(line, *index + 1, line[*index]);
	if (res < 0)
	{
		ft_putstr_fd("Error : single quote open\n", 2);
		exit(0);
	}
	set_quote(&q, *index, res);
	if (q.pair == true)
		tmp = ft_substr(line, q.start, q.end);
	else
		tmp = ft_strdup("");
	if (line[*index] == '\"' && q.pair)
	{
		tmp = find_dollar(input, q, tmp);
	}
	*index = res;
	return (tmp);
}

char	*find_quotes(t_input *input, char *line)
{
	int		count;
	char		*tmp;
	char		*newline;

	count = 0;
	while (line[count])
	{
		if (line[count] == '\'' ||  line[count] == '\"')
		{
			tmp = handle_quotes(input, line, &count);
			newline = ft_strjoin2(newline, tmp);
			free(tmp);
		}
		else
			newline = ft_strjoin2(newline, &line[count]);
		count ++;
	}
	return (newline);
}
