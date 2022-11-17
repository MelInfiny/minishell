#include "minishell.h"

int	is_varshell(char c)
{
	if (ft_isalnum(c) > 0 || c == '_')
		return (1);
	return (0);
}

int	search_dollar(t_quote *q, char *line, int index)
{
	int		count;

	q->end = 0;
	q->start = search_c(line, index, '$');
	if (q->start < 0)
		return (0);
	count = q->start + 1;
	while (is_varshell(line[count++]))
		q->end++;
	return (1);
}

char	*replace_dollar(t_quote q, char *line, char *varenv)
{
	char	*newline;
	int	count;
	int	i;
	int	j;

	i = -1;
	j = 0;
	newline = (char *) ft_calloc(ft_strlen(line) + ft_strlen(varenv) + 1 - q.end, sizeof(char));
	if (!newline)
	{
		ft_putstr_fd("Error : Alloc for alias\n", 2);
		exit(0);
	}
	while (++i < q.start)
		newline[i] = line[i];
	count = i + q.end + 1;
	while (varenv[j])
		newline[i++] = varenv[j++];
	while (line[count])
		newline[i++] = line[count++];
	free(varenv);
	free(line);
	return (newline);
}

char	*find_dollar(t_input *input, t_quote q, char *line)
{
	char	*tmp;
	int	count;

	count = -1;
	while (line[++count])
	{
		if (line[count] == '$')
		{
			q.start = count;
			q.end = 0;
			while (is_varshell(line[++q.start]))
				q.end ++;
			q.start = count;
			if (q.end == 0)
				continue;
			tmp = find_varenv(input, &q, line);
			if (q.pair)
				count += ft_strlen(tmp);
			line = replace_dollar(q, line, tmp);
		}
	}
	return (line);
}
