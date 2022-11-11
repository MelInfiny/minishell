#include "minishell.h"

void	load_history(t_readline *prompt)
{
	char	*line;
	int		count;
	int		fd;

	count = 0;
	fd = open(".minishell_history", O_RDONLY | O_CREAT, 0777);
	if (!fd)
	{
		perror("history");
		return ;
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		prompt->history[count++] = line;
		prompt->size_history++;
		free(line);
	}
	close(fd);
}

void reverse_history(t_readline *prompt)
{
	int	count;
	int	fd;
	
	count = 0;
	fd = open(".minishell_history", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (!fd)
	{
		perror("history");
		return;
	}
	while (prompt->history[count])
	{
		ft_putstr_fd(prompt->history[count], fd);
		ft_putstr_fd("\n", fd);
		count ++;
	}
	close(fd);
}

int ft_add_history(t_readline *prompt)
{
	int	count;

	if (!prompt->line)
		return (1);
	if (prompt->size_history < 500)
	{
		prompt->history[prompt->size_history++] = prompt->line;
		return (0);
	}
	count = 0;
	while (count < 500)
	{
		free(prompt->history[count]);
		if (count == 499)
			prompt->history[count] = prompt->line;
		else
			prompt->history[count] = prompt->history[count + 1];
		count ++;
	}
	prompt->last = prompt->line;
	return (0);
}

int	last_history(t_readline *prompt)
{
	int	count;

	count = prompt->size_history - prompt->index;
	if (!prompt->last)
	{
		prompt->last = NULL;
		return (1);
	}
	free(prompt->last);
	prompt->last = prompt->history[count];
	return (0);
}
