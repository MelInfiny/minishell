#include "minishell.h"

void	test_commoners(void)
{
	char	*line;
	
	while (1)
	{
		line = readline("");
		add_history(line);
		if (ft_equalstr(line, "exit"))
			break;
	}
}

int	main(void)
{
	t_readline rl;

	init_readline(&rl);
	load_history(&rl);
	while (1)
	{
		ft_readline(&rl);
		rl.line = get_next_line(0);
		free(rl.buff);
		ft_add_history(&rl);
		if (ft_equalstr(rl.line, "exit"))
			break;
		free(rl.line);
	}
	free(rl.line);
	reverse_history(&rl);
}
