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
	if (pid == 0)				//fiston 
		ret = execute(input, cmds);
	else
	{	
		wait(&status);			// papa
		exit(status);
	}
	exit(ret);
}

static int	create_pipe(t_input *input, t_list *cmds, int fd[2])
{
	int	pid;

	pid = fork();
	if (pid == 0)			// papa
	{
		if (fd)
		{
			close(fd[0]);
			print_break(input);
			if (dup2(fd[1], STDOUT_FILENO) == -1)
				return ;
			print_break(input);
			close(fd[1]);
		}
		exec_cmd(input, cmds);
	}
	else if (pid > 0)		// papy	
	{
		if (fd)
		{
			close(fd[1]);
			print_break(input);
			if (dup2(fd[0], STDIN_FILENO) == -1)
				return ;
			print_break(input);
			close(fd[0]);
		}
	}
	return (pid);
}

void	ft_pipe(t_input *input)
{
	t_list	*tmp;
	t_list	*pids;
	int	count;
	int	fd[2];

	tmp = input->ast;
	count = ft_lstsize(tmp);
	if (!input->paths)
	{
		ft_cmd_error(input, NULL, "path");
		return ;
	}
	while (count--)
	{
		// count = 0 dup stdin
		// count = lst dup stdout
		if (pipe(fd) < 0)
			return ;
		ft_lstadd(ft_lstnew(create_pipe(input, tmp, fd)));
		tmp = tmp->next;
	}
	count = ft_lstsize(tmp);
	while (1)
	{
		while (pids)
		{
			ret = waitpid(pids->content, NULL, WNOHANG);
			if (ret < 0)
			{
				perror("pid");
				// kill
				return ;
			}
			else if (ret > 0)
				return ;	//kill
			pids = pids->next;
		}
	}	
	//create_pipe(input, tmp, NULL);
}
