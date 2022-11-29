#include "minishell.h"

void	init_input(t_input *input, char *line, char **env)
{
	input->env = ft_strdcpy(env);
	input->raw = line;
	input->lexer = NULL;
	input->parser = NULL;
	input->ast = NULL;
	input->line = NULL;
}