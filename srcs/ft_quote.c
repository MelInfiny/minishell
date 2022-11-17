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

int	handle_quotes(t_input *input, char *line, int index)
{
	int		res;
	char		*tmp;
	t_quote		q;

	res = search_c(line, index + 1, line[index]);
	if (res < 0)
	{
		ft_putstr_fd("Error : single quote open\n", 2);
		exit(0);
	}
	set_quote(&q, index, res);
	if (q.pair == true)
		tmp = ft_substr(line, q.start, q.end);
	else
		tmp = ft_strdup("");
	if (line[index] == '\'')
	{
		ft_addmap(&input->squotes, ft_mapnew(tmp));
		printf("%s", (char *) ft_maplast(input->squotes)->content);
	}
	else
	{
		if (find_dollar(&q, tmp))
			replace_dollar(q, tmp, find_varenv(input, q, line));
		ft_addmap(&input->dquotes, ft_mapnew(tmp));
		printf("%s", (char *) ft_maplast(input->dquotes)->content);
	}
	free(tmp);
	return (res);
}

int	quotes_finder(t_input *input, char *line)
{
	int		count;

	count = 0;
	while (line[count])
	{
		if (line[count] == '\'' ||  line[count] == '\"')
		{
			count += handle_quotes(input, line, count);
		}
		else
			printf("%c", line[count]);
		count ++;
	}
	return (0);
}
