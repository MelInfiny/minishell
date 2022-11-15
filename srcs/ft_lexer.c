#include "minishell.h"

/** 
 * pair is true if we need to interprete between the quote s*/
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
 * Return 1 if there is a single quote open*/
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
	int	res_single;

	res_single = find_quotes(&input->q, &input->line, '\'');
	if (res_single > 0)
		print_error("single quote open\n");
	if (input->q.index == ft_strlen(input->line) && !input->q.pair)
		return (0);
	input->raw = ft_split(raw, " ");
	return (0);

}*/
