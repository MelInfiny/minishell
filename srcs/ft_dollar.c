#include "minishell.h"

int	is_varshell(char c)
{
	if (ft_isalnum(c) > 0 || c == '_')
		return (1);
	return (0);
}

void	set_dollar(t_quote *q, char *line, int start)
{
	int	count;

	count = start;
	q->end = 0;
	while (is_varshell(line[++count]))
		q->end ++;
	q->start = start + 1;
}

char	*ft_strinsert(t_quote q, char *line, char *varenv)
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
	while (++i < q.start - 1)
		newline[i] = line[i];
	count = q.start + q.end;
	while (varenv[j])
		newline[i++] = varenv[j++];
	while (line[count])
		newline[i++] = line[count++];
	free(varenv);
	free(line);
	return (newline);
}

char	*find_dollar(t_input *input, char *line)
{
	char	*tmp;
	int	count;
	t_quote	q;

	count = -1;
	while (line[++count])
	{
		if (line[count] == '$')
		{
			set_dollar(&q, line, count);
			if (q.end == 0)
				continue;
			tmp = find_varenv(input, &q, line);
			if (q.pair)
				count += ft_strlen(tmp);
			line = ft_strinsert(q, line, tmp);
		}
	}
	return (line);
}

char	*replace_dollar(t_input *input, char *line, int *index)
{
	char	*tmp;
	t_quote	q;
	
	set_dollar(&q, line, *index);
	if (q.end == 0)
		return (ft_strdup("$"));
	tmp = find_varenv(input, &q, line);
	if (q.pair)
		*index += q.end;
	return (tmp);
}
