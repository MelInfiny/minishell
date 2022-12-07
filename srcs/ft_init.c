#include "minishell.h"

void	init_input(t_input *input, char *line, char **env)
{
	input->env = ft_strdcpy(env);
	input->paths = ft_path(input->env);
	input->raw = line;
	input->lexer = NULL;
	input->parser = NULL;
	input->ast = NULL;
	input->fdin = 0;
	input->fdout = 1;
}
