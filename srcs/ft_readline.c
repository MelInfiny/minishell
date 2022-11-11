#include "minishell.h"

void	init_readline(t_readline *prompt)
{
	int	count;

	count = 0;
	prompt->line = NULL;
	prompt->last = NULL;
	prompt->index = 0;
	prompt->size_history = 0;
	while (count < 500)
		prompt->history[count++] = NULL;
}

int	ft_readline(void)
{
	char *line;

	while (1)
		line = readline("");
	ft_printf("line : %s\n", line);
	return (0);
}
