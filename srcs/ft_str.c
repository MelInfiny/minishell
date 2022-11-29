#include "minishell.h"

char	*ft_streplace(char *oldstr, char *newstr)
{
	if (oldstr)
		free(oldstr);
	oldstr = NULL;
	return (newstr);
}

bool	ft_findstr(char *str, const char *find)
{
	size_t	len;

	len = ft_strlen(find);
	if (ft_strncmp(str, find, len))
		return (false);
	if (str[len] != '=')
		return (false);
	return (true);
}