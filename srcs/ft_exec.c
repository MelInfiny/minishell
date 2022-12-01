#include "minishell.h"

static void	execute(t_input *input, t_list *cmds)
{
	int	count;
	char	*command;
	char	*path;
	t_node	*node;

	count = 0;
	node = cmds->content;
	while (input->paths[count])
	{
		if (command)
			free(command);
		path = ft_strjoin(input->paths[count++], "/");
		command = ft_strjoin2(path, node->args[0]);
		if (access(command, F_OK) == 0)
		{
			if (execve(node->args[0], node->args, NULL) == -1)
				ft_cmd_error(input, cmds, "execve");
		}
	}
	if (access(command, F_OK) != 0)
		ft_cmd_error(input, cmds, "exec_cmd");
	free(command);
}

static void	create_pipe(t_input *input, t_list *cmds)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) < 0)
		ft_cmd_error(input, cmds, "");
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		if (dup2(fd[1], input->fdin) != -1)
			ft_cmd_error(input, cmds, "");
		close(fd[1]);
		execute(input, cmds);
	}
	else if (pid > 0)
	{
		close(fd[1]);
		if (dup2(fd[0], input->fdout) != -1)
			ft_cmd_error(input, cmds, "");
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}

void	ft_pipe(t_input *input)
{
	t_list	*tmp;
	int	count;

	tmp = input->ast;
	count = 0;
	if (!input->paths)
		ft_cmd_error(input, NULL, "path");
	if (dup2(input->fdin, STDIN_FILENO) == -1)
		ft_cmd_error(input, NULL, "pipe");
	while (count < ft_lstsize(input->ast) - 1)
	{
		create_pipe(input, tmp);
		tmp = tmp->next;
		count ++;
	}
	if (dup2(input->fdout, STDOUT_FILENO) == -1)
		ft_cmd_error(input, NULL, "pipe");
	execute(input, tmp);
}

