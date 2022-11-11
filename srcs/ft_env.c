#include "minishell.h"

void	ft_strdfree(char **strd)
{
	int	count;

	count = 0;
	while (strd[count])
	{
		free(strd[count]);
		count ++;
	}
	free(strd);
}

char	**ft_strdcpy(char **strd)
{
	char	**newstrd;
	int		count;

	newstrd = (char **) calloc(ft_strdlen(strd) + 1, sizeof(char *));
	if (!strd)
		return (NULL);
	count = 0;
	while (strd[count])
	{
		newstrd[count] = strd[count];
		count ++;
	}
	newstrd[count] = NULL;
	return (newstrd);
}

int	ft_env(char **env)
{
	int	count;

	count = 0;
	while (env[count])
	{
		ft_printf("%s\n", env[count]);
		count ++;
	}
	return (0);
}
