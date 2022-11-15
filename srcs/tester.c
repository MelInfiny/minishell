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

void	test_varshell(void)
{
	char	*s = "PATH_=BON+JOUR";
	for (size_t i = 0; i < ft_strlen(s); i++)
	{
		if (is_varshell(s[i]))
			printf("ok %c\n", s[i]);
		else
			printf("non ok %c\n", s[i]);
	}
}

int	main(int ac, char **argv, char **env)
{
	(void) ac;
	(void) argv;
	t_input	input;
	t_quote	q;

	init_input(&input, readline("minishell: "), env);
	init_quote(&q);

//	printf("%d : ", find_dollar(&q, input.raw));
//	printf("%s ", find_varenv(&input, &q, input.raw));
	
	quotes_finder(&input, input.raw);
	printf("\n");
}
