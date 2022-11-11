#include "minishell.h"

bool	ft_equalstr(char *str, char *find)
{
	int	count;

	count = 0;
	if (ft_strlen(str) != ft_strlen(find))
		return (0);
	while (str[count] && find[count])
	{
		if (str[count] != find[count])
			return (0);
		count ++;
	}
	return (1);
}

bool	ft_findstr(char *str, const char *find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == find[j])
		{
			while (str[i + j] == find[j])
				j++;
			if (find[j] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

static char	**ft_strdel(const char *var, char **env)
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

	newstrd = ft_strdel(var, *env);
	if (!newstrd)
	{
		perror("unset");
		return (1);
	}
	free(*env);
	*env = newstrd;
	return (0);
}


