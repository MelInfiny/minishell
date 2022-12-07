#include "minishell.h"

static void	ft_heredoc(char *file, char *limit)
{
	char	*input;
	int	heredoc;

	heredoc = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
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
	close(heredoc);
}

static int	g_redir(t_input *input, t_redir *redir, int status)
{
	int	infile;

	infile = -1;
	if (status)
	{
		ft_heredoc(".heredoc", redir->file);
		infile = open(".heredoc", O_RDONLY);
	}
	else
		infile = open(redir->file, O_RDONLY);
	if (infile == -1)
		return (0);
	if (dup2(infile, input->fdin) == -1)
	       return (0);
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
	close(outfile);
	return (1);
}

int	ft_redirect(t_input *input, t_node *node)
{
	t_redir	*redir;
	t_list	*r;
	int	res;

	res = 1;
	r = node->redir;
	while (r)
	{
		redir = r->content;
		if (redir->type == 1)
			res = g_redir(input, redir, 0);
		if (redir->type == 11)
			res = g_redir(input, redir, 1);
		if (redir->type == 2)
			res = d_redir(input, redir->file, 0);
		if (redir->type == 22)
			res = d_redir(input, redir->file, 1);
		if (res != 1)
		{
			perror("redirection ");
			return (0);
		}
		r = r->next;
	}
	return (1);
}
