#include "minishell.h"

t_node	*new_node(t_map *map)
{
	t_node	*node;

	node = (node *) ft_calloc(1, sizeof(node));
	if (!node)
		return (NULL);
	node->status = 1;
	if (is_break(map->type))
		node->status = 0;
	return (node);
}

t_list	*parser_ast(t_input *input, t_map **lexer)
{
	t_map	*tmp;
	t_node	*node;

	tmp = input->lexer;
	while (tmp)
	{
		if (tmp->type == WORD)
		{
			node = new_node(tmp);
			
		}
	}
}

