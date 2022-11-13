#include "minishell.h"

void	init_readline(t_readline *prompt)
{
	int	count;

	count = 0;
	prompt->line = NULL;
	prompt->last = NULL;
	prompt->buff = NULL;
	prompt->index = 0;
	prompt->size_history = 0;
	while (count < 500)
		prompt->history[count++] = NULL;
}

static void	ft_read_arrow(t_readline *prompt, char arrow)
{
	if (prompt->index == 0)
		prompt->buff = get_next_line(STDIN_FILENO);
	if (arrow == 'A')
		prompt->index --;
	else if (arrow == 'B')
		prompt->index ++;
	last_history(prompt);
	ft_putstr_fd(prompt->last, STDOUT_FILENO);
	free(prompt->last);
}

int	ft_readline(t_readline *prompt)
{
	char	c;
	
	while (1)
	{
		read(0, &c, 1);
		if (c == '\n')
			break;
		if (c == '\033')
		{
			read(0, &c, 1);
			if (c == '[')
				read(0, &c, 1);
			if (c == 'A' || c == 'B')
				ft_read_arrow(prompt, c);
			else
				ft_putchar_fd(STDIN_FILENO, '[');
		}
		else
			ft_putchar_fd(STDIN_FILENO, c);
	}
	return (0);
}

int	get_input(t_readline *prompt)
{
	ft_readline(prompt);
	prompt->line = get_next_line(STDIN_FILENO);
	ft_add_history(prompt);
	free(prompt->buff);
	return (0);
}
