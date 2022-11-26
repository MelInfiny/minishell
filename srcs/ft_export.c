#include "minishell.h"

size_t	ft_strdlen(char **strd)
{
	int	count;

	count = 0;
	while (strd && strd[count])
		count ++;
	return (count);
}

int	ft_export(char *var, char ***env)
{
	char	**newenv;

	newenv = ft_strdjoin(*env, var);
	if (!newenv)
	{
		perror("export");
		return (1);
	}
	free(*env);
	*env = newenv;
	return (0);
}
