#include "minishell.h"

int	ft_exit(char ***env)
{
	free(*env);
	return (0);
}
