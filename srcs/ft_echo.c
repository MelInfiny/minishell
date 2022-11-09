#include "minishell.h"

static char	*trim_n(const char *str)
{
	char	*res;
	int		count;
	int		i;

	res = (char *) calloc(ft_strlen(str), sizeof(str));
	if (!res)
		return (NULL);
	count = 0;
	i = 0;
	while (str[count])
	{
		if (str[count] == '\n')
			count++;
		res[i++] = str[count++]; 
	}
	return (res);
}

int	ft_echo(const char *str, int status)
{
	char	*display;

	if (!status)
	{
		ft_printf(str);
		return (0);
	}
	display = trim_n(str);
	if (!display)
		return (0);
	ft_printf(display);
	free(display);
	return (1);
}


