#include "minishell.h"

int	parse_first(t_input *input, int key)
{
	t_map	*tmp;

	tmp = input->lexer;
	if (tmp->type == WORD)
		return (0);
	if (tmp->type == SQUOTE)
		return (1);
	if (tmp->type == DRREDIR || GRREDIR || DREDIR)
		return (2);
	else
	{
		printf("minishell : parse error near :%s\n", tmp->content);
		exit (0);
	}
	return (-1);
}

void	parser(t_input *input, char *line)
{
	int	res;
	t_map	*parser;

	res = parse_first(input, 1);
	
		

}
