#include <minishell.h>

int	ft_cd(const char *path)
{
	int	res;

	res = chdir(path);
	if (res < 0)
	{
		perror("cd");
		return (1);
	}
	return (0);
}

