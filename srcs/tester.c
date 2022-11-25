#include "minishell.h"

void	print_type(e_type type)
{
	printf("\n\n");
	if (type == WORD)
		printf("WORD");
	if (type == DQUOTE)
		printf("DQUOTE");
	if (type == SQUOTE)
		printf("SQUOTE");
	if (type == DOLLAR)
		printf("DOLLAR");
	if (type == ESPACE)
		printf("ESPACE");
	if (type == PIPE)
		printf("PIPELINE");
	if (type == GREDIR)
		printf("GREDIR");
	if (type == DREDIR)
		printf("DREDIR");
	if (type == GRREDIR)
		printf("GRREDIR");
	if (type == DRREDIR)
		printf("DRREDIR");
}

void	print_map(t_map *map)
{
	t_map	*tmp;

	tmp = map;
	while (tmp)
	{
		print_type(tmp->type);
		printf(" %d: ", tmp->key);
		printf(" len = %ld: ", ft_strlen(tmp->content));
		printf("%s", tmp->content);
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
	check_syntax(&input);
	print_map(input.lexer);
	printf("\n");
	free_input(&input);
	return (0);
}
