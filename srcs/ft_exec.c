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

static void	exec_cmd(t_input *input, t_list *cmds)
{
	int	pid;
	int	status;
	int	ret;

	ret = -1;
	pid = fork();
	if (pid < 0)
		return ;
	if (pid == 0) //fiston
	{
		ret = execute(input, cmds);
		exit(ret);
	}
	else
	{
		wait(&status);			// papa
	//	exit(status);
	}
}

static void	create_pipes(t_input *input, t_list *cmds, int *pids)
{
	int	count;
	int	fd[2];

	count = -1;
	while (++count < ft_lstsize(cmds))
	{
		if (pipe(fd) < 0)
			return ;
		pids[count] = fork();
		print_break(NULL);
		if (pids[count] == 0) // papa
		{
			if (dup2(fd[1], STDOUT_FILENO) == -1)
				return ;
			exec_cmd(input, cmds);
		}
		else if (pids[count] > 0) // papy
		{
			print_break(NULL);
			if (dup2(fd[0], STDIN_FILENO) == -1)
				return ;
		}
		else
			return ;
		cmds = cmds->next;
	}
}

static void	wait_pipes(int *pids, size_t size)
{
	size_t	count;
	int	ret;

	while (1)
	{
		count = 0;
		while (count < size)
		{
			ret = waitpid(pids[count], NULL, WNOHANG);
			print_break(NULL);
			if (ret == 0)
				count ++;
			else
			{
				if (ret < 0)
				{
					//kill(pids[count], SIGINT);
					return ;
				}
				if (ret > 0)
				{
					kill(pids[count], SIGTERM);
				}
			}
		}
	}
}

void	ft_pipe(t_input *input)
{
	t_list	*cmds;
	int	*pids;

	cmds = input->ast;
	pids = (int *) ft_calloc(ft_lstsize(cmds), sizeof(int));
	if (!pids)
		return ;
	print_break(NULL);
	if (dup2(input->fdin, STDIN_FILENO) == -1)
	{
		free(pids);
		return ;
	}
	print_break(NULL);
	create_pipes(input, cmds, pids);
	wait_pipes(pids, ft_lstsize(cmds));
	print_break(NULL);
	if (dup2(input->fdout, STDOUT_FILENO) == -1)
	{
		free(pids);
		return ;
	}
	print_break(NULL);
}
