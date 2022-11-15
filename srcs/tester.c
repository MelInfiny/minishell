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
int	main(int ac, char **argv, char **env)
{
	(void) ac;
	(void) argv;
	t_input	input;
	t_quote	q;

	init_input(&input, readline("minishell: "), env);
	init_quote(&q);

	ft_printf("dol : %d\n", find_dollar(&q, input.raw));
	ft_printf(" %s\n", find_varenv(&input, &q, input.raw));
	
}
