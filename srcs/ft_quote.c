#include "minishell.h"

/** 
 * pair is true if we need to interprete between the quote s*/
void	det_quote(t_quote *q, int s, int e)
{
	if (e - s > 1)
	{
		q->start = s + 1;
		q->end = e;
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

static int	set_quote(t_quote *q, char *line, int start, char c)
{
	int	count;

	count = start;
	q->end = 0;
	while (line[++count] != c)
		q->end ++;
	if (line[count] != c)
		return (0);
	if (q->end > 0)
		q->pair = true;
	else
		q->pair = false;
	q->start = start + 1;
	return (1);
}

char	*replace_quote(t_input *input, char *line, int *index)
{
	char		c;
	char		*tmp;
	t_quote		q;

	c = line[*index];
	init_quote(&q);
	if (!set_quote(&q, line, *index, c))
	{
		ft_putstr_fd("Error : single quote open\n", 2);
		exit(0);
	}
	*index += q.end +1 ;
	if (q.pair == true)
	{
		tmp = ft_substr(line, q.start, q.end);
		if (c == '\"')
			tmp = find_dollar(input, tmp);
	}
	else
		tmp = ft_strdup("");
	return (tmp);
}

char	*find_quotes(t_input *input, char *line)
{
	int		count;
	int		index;
	char		*tmp;
	char		*newline;

	count = 0;
	newline = ft_strdup("");
	while (line[count])
	{
		if (line[count] == '\'' ||  line[count] == '\"')
		{
			index = count;
			tmp = replace_quote(input, line, &count);
			if (count > index)
				newline = ft_strjoin2(newline, tmp);
			free(tmp);
		}
		else
			newline = ft_charjoin(newline, line[count]);
		count ++;
	}
	return (newline);
}
