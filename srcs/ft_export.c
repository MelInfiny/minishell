#include "minishell.h"

size_t	ft_strdlen(char **strd)
{
	int	count;

	count = 0;
	while (strd && strd[count])
		count ++;
	return (count);
}

char	**ft_strdjoin(char **strd, char *s)
{
	char	**newstr;
	int		i;

	newstr = (char **) calloc(ft_strdlen(strd) + 2, sizeof(char *));
	if (!newstr)
		return (NULL);
	i = 0;
	while (strd[i])
	{
		newstr[i] = strd[i];
		i++;
	}
	newstr[i++] = s;
	newstr[i] = NULL;
	return (newstr);
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
