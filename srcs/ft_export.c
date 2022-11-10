#include "minishell.h"
#include "libft.h"

int	ft_export(const char *var)
{
	int	fd;

	fd = open("$HOME/.bashrc", O_WRONLY | O_CREAT | O_APPEND, 0766);
	if (fd < 0)
	{
		perror(".bashrc");
		return (1);
	}
	ft_putstr_fd(var, fd);
	close(fd);
	return (0);
}
