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

static void	create_pipe(t_input *input, t_list *cmds, int fd[2])
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (fd)
		{
			close(fd[1]);
			if (dup2(input->fdin, fd[0]) == -1)
				return ;
			close(fd[0]);
		}
		execute(input, cmds);
	}
	else if (pid > 0)
	{
		if (fd)
		{
			close(fd[0]);
			if (dup2(input->fdout, fd[1]) == -1)
				return ;
			close(fd[1]);
		}
		waitpid(pid, NULL, 0);
		//wait(&status);
	}
}

void	ft_pipe(t_input *input)
{
	t_list	*tmp;
	int	count;
	int	fd[2];

	tmp = input->ast;
	count = ft_lstsize(tmp);
	if (!input->paths)
	{
		ft_cmd_error(input, NULL, "path");
		return ;
	}
	while (count-- > 1)
	{
		if (pipe(fd) < 0)
			return ;
		create_pipe(input, tmp, fd);
		tmp = tmp->next;
	}
	create_pipe(input, tmp, NULL);
}
