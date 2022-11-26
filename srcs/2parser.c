#include "minishell.h"

int	parse_status(e_type type)
{
	if (type == WORD)
		return (0);
	if (type == PIPE)
		return (1);
	if (type == DREDIR)
		return (2);
	if (type == DRREDIR)
		return (22);
	if (type == GREDIR)
		return (3);
	if (type == GRREDIR)
		return (33);
	return (-1);
}

t_node	*new_node(t_map *map)
{
	t_node	*node;

	node = (node *) ft_calloc(1, sizeof(node));
	if (!node)
		return (NULL);
	node->status = parse_status(map->type);
	return (node);
}

t_list	*parser_ast(t_input *input, t_map **lexer)
{
	t_map	*tmp;
	t_node	*node;
	int	start;

	tmp = input->lexer;
	start = 0;
	while (tmp)
	{
		if (is_break(tmp->type))
		{
			if (

		}
	}
}

