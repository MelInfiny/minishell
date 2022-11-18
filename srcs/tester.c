#include "minishell.h"

void	print_map(t_map *map)
{
	t_map	*tmp;

	tmp = map;
	while (tmp)
	{
		printf("%d:", tmp->key);
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}

int	main(int ac, char **argv, char **env)
{
	(void) ac;
	(void) argv;
	t_input input;
	
	printf("HELLO WORLD !\n");
	init_input(&input, readline("minishell: "), env);
	ft_lexer(&input, input.raw);
	print_map(input.lexer);
	free_input(&input);
	return (0);
}
