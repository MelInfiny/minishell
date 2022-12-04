#include "minishell.h"

int	switch_redir(t_input *input, t_list *cmd)
{
	t_node	*node;
	int	redir;

	node = cmd->content;
	redir = node->status;
	if (redir == 1)
		g_redir(input, ft_heredoc(node->file));
	if (redir == 11)
		g_redir(input, node->file);
	if (redir == 2)
		d_redir(input, node->file, 0);
	if (redir == 22)
		d_redir(input, node->file, 1);
}

//dup2
char	*ft_heredoc(t_list *cmd);

int	g_redir(t_input *input, char *file);

int	d_redir(t_input *input, char *file, int status);
