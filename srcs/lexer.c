#include "minishell.h"

char	*first_detector(t_input *input, char *line)
{
	char	*newline;
	char	*tmp;
	int	count;

	count = 0;
	newline = "";
	while (line[count])
	{
		if (line[count] == '\'' || line[count] == '\"')
		{
			tmp = replace_quote(input, line, &count);
			newline = ft_strjoin2(newline, tmp);
			free(tmp);
		}
		else if (line[count] == '$')
		{
			tmp = replace_dollar(input, line, &count);
			newline = ft_strjoin2(newline, tmp);
			free(tmp);
		}
		else
			newline = ft_charjoin(newline, line[count]);
		count ++;
	}
	free(line);
	return (newline);
}
