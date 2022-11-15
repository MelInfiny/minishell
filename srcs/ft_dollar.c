#include "minishell.h"

int	is_varshell(char c)
{
	if (ft_isalnum(c) > 0 || c == '_')
		return (1);
	return (0);
}

int	find_dollar(t_quote *q, char *line)
{
	int		count;

	q->end = 0;
	q->start = search_c(line, 0, '$');
	if (q->start < 0)
		return (0);
	count = q->start + 1;
	while (is_varshell(line[count++]))
		q->end++;
	return (1);
}
