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
	input->line = NULL;
}
