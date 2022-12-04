#include "minishell.h"

int	ft_cmd_error(t_input *input, t_list *cmd, char *message)
{
	t_node	*node;
	if (cmd)
	{
		node = cmd->content;
		printf("%s", node->args[0]);
	}
	if (message)
		perror(message);
	(void) input;
	return (0);
}

void	ft_freenode(void *n)
{
	int		count;
	t_node	*node;

	count = 0;
	node = (t_node *) n;
	if (node->file)
		free(node->file);
	while (node->args && node->args[count])
		free(node->args[count++]);
	free(node->args);
}

void	free_input(t_input *input)
{
	ft_strdfree(input->env);
	free(input->raw);
	ft_mapclear(&input->lexer, free);
	ft_mapclear(&input->parser, free);
	ft_lstiter(input->ast, &ft_freenode);
	ft_lstclear(&input->ast, free);
	if (input->line)
		free(input->line);
	if (input->paths)
		ft_strdfree(input->paths);
}
