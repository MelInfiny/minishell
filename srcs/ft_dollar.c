#include "minishell.h"

static int	is_varshell(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (1);
	return (0);
}

int	find_dollar(t_quote *q, char *line)
{
	int		count;

	count = 0;
	q->start = search_c(line, 0, '$');
	if (q->start < 0)
		return (0);
	while (line[count] && is_varshell(line[count]))
		count ++;
	q->end = count;
	return (0);
}
