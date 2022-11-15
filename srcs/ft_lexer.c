#include "minishell.h"

static void	single_quote(t_quote *q, int s, int e)
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
	q->index = e + 1;
}

/**
 * Return NULL if there is a single quote open*/
int	find_quotes(t_quote *q, char *line, char c)
{
	int	status;
	int	count;

	count = q->index;
	status = -1;
	while (line[count])
	{
		if (line[count] == c)
		{
			if (status < 0)
				status = count;
			else
			{
				single_quote(q, status, count);
				return (0);
			}
		}
		count ++;
	}
	if (status > 0)
		return (1);
	return (0);
}

/*
int	break_line(t_input *input)
{
	input->raw = ft_split(raw, " ");
	return (0);

}*/
