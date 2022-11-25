#include "minishell.h"

void	init_quote(t_quote *q)
{
	q->start = 0;
	q->end = 0;
	q->pair = false;
}

void	init_input(t_input *input, char *line, char **env)
{
	input->env = ft_strdcpy(env);
	input->raw = line;
	input->lexer = NULL;
	input->parser = NULL;
	input->line = NULL;
}

void	free_input(t_input *input)
{
	ft_strdfree(input->env);
	free(input->raw);
	ft_mapclear(&input->lexer, free);
	ft_mapclear(&input->parser, free);
	if (input->line)
		free(input->line);
}
