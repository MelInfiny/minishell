#include "minishell.h"

void	test_main(void)
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

void	test_readline(void)
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

void	test_singleq(int ac, char **argv)
{
	(void) ac;
	char	*line = argv[1];
	t_quote q;
	
	q.start = 0;
	q.end = 0;
	q.index = 0;
	q.pair = false;
	
	printf("res %d\n", find_quotes(&q, line, '\''));
	printf("%d : start = %d	 end = %d  index = %d\n", q.pair, q.start, q.end, q.index);
}
