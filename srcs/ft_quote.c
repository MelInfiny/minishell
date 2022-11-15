#include "minishell.h"

/** 
 * pair is true if we need to interprete between the quote s*/
static void	set_quote(t_quote *q, int s, int e)
{
	if (e - s > 1)
	{
		q->start = s;
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

int	handle_quotes(t_input *input, char *line, int index)
{
	int		res;
	char	c;
	t_quote	q;

	c = line[index];
	res = search_c(line, index + 1, c);
	if (res < 0)
	{
		ft_putstr_fd("Error : single quote open\n", 2);
		exit(0);
	}
	set_quote(&q, index, res);
	if (find_dollar(&q, line))
		input->line = find_varenv(input, &q, line);
	return (res);
}

int	quotes_finder(t_input *input, char *line)
{
	int		count;

	count = 0;
	while (line[count])
	{
		if (line[count] == '\'' ||  line[count] == '\"')
			count = handle_quotes(input, line, count);
		else
			printf("%c", line[count]);
		if (input->line != NULL)
		{
			printf("%s", input->line);
			free(input->line);
			input->line = NULL;
		}
		count ++;
	}
	return (0);
}
