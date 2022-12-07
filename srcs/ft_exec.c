#include "minishell.h"

static int	execute(t_input *input, t_list *cmds)
{
	int	count;
	char	*command;
	t_node	*node;

	count = 0;
	node = cmds->content;
	if (!node->args || !node->args[0])
		return (0);
	while (input->paths[count])
	{
		command = ft_strjoin(input->paths[count++], "/");
		command = ft_strjoin2(command, node->args[0]);
		if (access(command, F_OK | X_OK) == 0)
		{	
			if (execve(command, node->args, NULL) == -1)
				return (ft_cmd_error(input, NULL, node->args[0]));
		}
	}
	if (access(command, F_OK) != 0)
		return (ft_cmd_error(input, NULL, node->args[0]));
	free(command);
	return (1);
}

static int	create_pipe(t_input *input, t_list *cmds)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) < 0)
		return (ft_cmd_error(input, cmds, "pipeline"));
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		if (dup2(fd[1], input->fdout) == -1)
			return (ft_cmd_error(input, cmds, "dup_stdin"));
		close(fd[1]);
		execute(input, cmds);
	}
	else if (pid > 0)
	{
		close(fd[1]);
		if (dup2(fd[0], input->fdin) == -1)
			return (ft_cmd_error(input, cmds, "dup_stdout"));
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
	else
		return (0);
	return (1);
}
/*
static int	last_exec(t_input *input, t_list *cmds)
{
	int	pid;
	
	pid = fork();
	if (pid == 0)
	{
		execute(input, cmds);
	}
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
		kill(pid, SIGTERM);
	}
	else
		return (ft_cmd_error(input, cmds, "exec"));
	return (1);
}
*/
void	ft_pipe(t_input *input)
{
	t_list	*tmp;
	int	count;

	tmp = input->ast;
	count = ft_lstsize(tmp);
	if (!input->paths)
	{
		ft_cmd_error(input, NULL, "path");
		return ;
	}
	while (count-- > 1)
	{
		if (!create_pipe(input, tmp))
			return ;
		tmp = tmp->next;
	}
	execute(input, tmp);
}
