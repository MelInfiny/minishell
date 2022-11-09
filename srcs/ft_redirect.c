#include "minishell.h"

static int	ft_duplicate(int fd, int status)
{
	if (status == 0)
	{
		if (dup2(fd, STDIN_FILENO) == -1)
			perror("infile dup ");
	
	}
	else if (status == 1)
	{
		if (dup2(fd, STDOUT_FILENO) == -1)
			perror("outfile dup ");
	}
	return (0);
}

int	get_outfile(char *file, int status)
{
	int	fd;

	if (status == 0)
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (status == 1)
		fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd != -1)
		ft_duplicate(fd, 1);
	else
	{
		perror("outfile ");
		exit(1);
	}
	return (0);
}

int	get_infile(char *file, int status)
{
	int	fd;

	if (status == 0)
		fd = open(file, O_CREAT | O_RDONLY, 0644);
	if (fd != -1)
		ft_duplicate(fd, 0);
	else
	{
		perror("outfile ");
		exit(1);
	}
	return (0);
}
