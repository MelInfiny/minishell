#include "minishell.h"

int	ft_readline(void)
{
	char *line;

	for (int i = 0; i < 4; i++)
		line = readline("");
	printf("line : %s\n", line);
	return (0);
}
