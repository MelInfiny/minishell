#include "minishell.h"

int	find_builtin(t_input *input, char *line)
{
	int		count;
	char	**tmp;
	
	(void) input;
	count = 0;
	tmp = ft_split(line, ' ');
	if (!tmp)
	{
		ft_putstr_fd("Error split\n", 2);
		exit (0);
	}
	return (-1);
}

