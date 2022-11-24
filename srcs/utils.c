#include "minishell.h"

char	**ft_strdjoin(char **strd, char *s)
{
	char	**newd;
	int	strdlen;
	int	count;

	strdlen = ft_strdlen(strd);
	newd = ft_calloc(len+ 1, sizeof(char *));
	if (!newd)
		return (NULL);
	count = -1;
	while (strd[++count])
		newd[count] = strd[count];
	newd[count] = ft_strdup(s);
	if (strd)
		ft_strdfree(strd);
	return (newd);
}

char	**ft_strsplit(char *s, char c)
{
	int	count;
	char	*strd;

	count = -1;
	strd = (char **) ft_calloc(3, sizeof(char *));
	if (!strd)
		return (NULL);
	while (s[++count])
	{
		if (s[count] == c)
			break;
	}
	strd[0] = ft_substr(s, 0, count);
	if (s[count] == c)
		strd[1] == ft_substr(s, count, ft_strlen(s) - count);
	return (strd);
}
