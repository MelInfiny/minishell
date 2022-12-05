#include "minishell.h"

static void	ft_heredoc(int heredoc, char *limit)
{
	char	*input;

	while (1)
	{
		write(1, "> ", 2);
		input = get_next_line(0);
		if (!ft_strncmp(input, limit, ft_strlen(limit)) || !input)
			break;
		write(heredoc, input, ft_strlen(input));
		free(input);
	}
	free(input);
}

static int	g_redir(t_input *input, t_node *node, int status)
{
	int	infile;
	char	*file;

	if (status)
	{
		file = ft_strdup(".heredoc");
		infile = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
		ft_heredoc(infile, node->file);
	}
	else
	{
		infile = open(file, O_RDONLY);
		file = node->file;
	}
	if (infile == -1)
		return (0);
	if (ft_strdlen(node->args) == 1)
		node->args = ft_strdjoin(node->args, file);
	(void) input;
	close(infile);
	return (1);
}

static int	d_redir(t_input *input, char *file, int status)
{
	int	outfile;
	
	if (status)
		outfile = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		outfile = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile == -1)
		return (0);
	if (dup2(outfile, input->fdout) == -1)
	       return (0);
	return (1);
}

int	ft_redirect(t_input *input, t_list *cmd)
{
	t_node	*node;
	int	redir;
	int	res;

	node = cmd->content;
	redir = node->status;
	res = 1;
	if (redir == 1)
		res = g_redir(input, node, 0);
	if (redir == 11)
		res = g_redir(input, node, 1);
	if (redir == 2)
		res = d_redir(input, node->file, 0);
	if (redir == 22)
		res = d_redir(input, node->file, 1);
	if (res != 1)
	{
		perror("redirection ");
		return (0);
	}
	return (1);
}
