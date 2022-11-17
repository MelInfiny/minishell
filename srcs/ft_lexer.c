#include "minishell.h"

void	detector(t_input *input, char *line)
{
	int	count;

	count = 0;
	while (line[count])
	{
		if (line[count] == '\'' || line[count] == '\"')
			newline = ft_strjoin2(newline, replace_quotes(input, line, &count));
		else if (line[count] == '$')
			newline = ft_strjoin2(newline, replace_dollar(input, line, &count));
		else
			newline = ft_charjoin(newline, line[count]);
		count ++;
	}
	free(line);
	input->line = newline;
}
