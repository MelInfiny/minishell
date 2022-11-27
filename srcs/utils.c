#include "minishell.h"

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

char	*ft_streplace(char *oldstr, char *newstr)
{
	if (oldstr)
		free(oldstr);
	oldstr = NULL;
	return (newstr);
}

void	ft_freenode(void *n)
{
	int		count;
	t_node	*node;

	count = 0;
	node = (t_node *) n;
	if (node->file)
		free(node->file);
	while (node->args && node->args[count])
		free(node->args[count++]);
	free(node->args);
}

