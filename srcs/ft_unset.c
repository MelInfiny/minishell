#include "minishell.h"

static char	**del_in_env(const char *var, char **env)
{
	char	**newstrd;
	int		i;
	int		j;

	newstrd = (char **) calloc(ft_strdlen(env) + 1, sizeof(char *));
	if (!newstrd)
		return (NULL);
	i = 0;
	j = 0;
	while (env[i])
	{
		if (!ft_findstr(env[i], var))
			newstrd[j++] = env[i];
		i++;
	}
	newstrd[j] = NULL;
	return (newstrd);
}

int	ft_unset(const char *var, char ***env)
{
	char	**newstrd;

	newstrd = del_in_env(var, *env);
	if (!newstrd)
	{
		perror("unset");
		return (1);
	}
	free(*env);
	*env = newstrd;
	return (0);
}