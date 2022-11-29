#include "minishell.h"

size_t	ft_strdlen(char **strd)
{
	int	count;

	count = 0;
	if (!strd || !strd[0])
		return (0);
	while (strd && strd[count])
		count ++;
	return (count);
}

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
		newstrd[count] = ft_strdup(strd[count]);
		count ++;
	}
	return (newstrd);
}

char	**ft_strdjoin(char **strd, char *s)
{
	char	**newd;
	int		strdlen;
	int		count;

	strdlen = 0;
	if (strd)
		strdlen = ft_strdlen(strd);
	newd = ft_calloc(strdlen + 2, sizeof(char *));
	if (!newd)
		return (NULL);
	count = 0;
	while (strd && strd[count])
	{
		newd[count] = ft_strdup(strd[count]);
		count ++;
	}
	newd[count] = ft_strdup(s);
	if (strd)
		ft_strdfree(strd);
	return (newd);
}
