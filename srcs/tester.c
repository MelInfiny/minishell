#include "minishell.h"

int	main(void)
{
	t_readline rl;

	init_readline(&rl);
	load_history(&rl);
	while (1)
	{
		rl.line = readline("");
		ft_add_history(&rl);
		if (ft_equalstr(rl.line, "exit"))
			break;
	}
	reverse_history(&rl);
}
