#include "minishell.h"

int	ft_pwd(void)
{
	char	path[256];

	if (getcwd(path, sizeof(path)) == NULL)
	{
			perror("pwd");
			return (1);
	}
	printf("%s\n", path);
	return(0);
}
