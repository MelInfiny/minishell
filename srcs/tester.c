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

void	print_ast(t_list *ast)
{
	t_list	*tmp;
	t_node	*node;

	tmp = ast;
	while (tmp)
	{
		node = tmp->content;
		printf("%d :", node->status);
		for (size_t i = 0; node->args[i]; i++)
		{
				printf(" %s\n", node->args[i]);
		}
		tmp = tmp->next;
	}
}

void	test_expand(t_input *input)
{
	t_map	*tmp = input->lexer;
	while (tmp)
	{
		if (tmp->type == DOLLAR)
			printf("%s\n", expand_dollar(input, &tmp));
		tmp = tmp->next;
	}
}

void	test_lexer(t_input *input)
{
	ft_lexer(input, input->raw);
	check_syntax(input);
	check_expand(input);
	//print_map(input->parser);
}

void	test_ast(t_input *input)
{
	ft_parser(input);
	print_ast(input->ast);
}

int	main(int ac, char **argv, char **env)
{
	(void) ac;
	(void) argv;
	t_input input;
	
	init_input(&input, readline("minishell: "), env);

	test_lexer(&input);
	test_ast(&input);
	
	printf("\n");
	free_input(&input);
	return (0);
}


