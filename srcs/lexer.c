#include "minishell.h"

void	ft_lexer(t_input *input, char *line)
{
	int		count;
	char	c;

	count = 0;
	while (line[count])
	{
		c = line[count];
		if (c == '>' || c == '<' || c == '|' || c == '&' || c == '\n')
			ft_addmap(&input->lexer, ft_mapnew(&line[count], OPERATOR));
		else
			ft_addmap(&input->lexer, ft_mapnew(&line[count], WORD));
		count ++;
	}
	free(line);
}

int	extract_word(t_input *input, int start)
{
	t_map	*tmp;

	tmp = ft_getmap(input->lexer, start);
	while (tmp->type != OPERATOR)
		tmp = tmp->next;
	if (tmp->type == OPERATOR)
		return (tmp->key);
	return (-1);
}



