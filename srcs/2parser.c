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

t_node	*new_node(t_map *map, char *content)
{
	t_node	*node;

	node = (node *) ft_calloc(1, sizeof(node));
	if (!node)
		return (NULL);
	node->status = parse_status(map->type);
	node->args = (char **) ft_calloc(1, sizeof(char));
	if (!node->args)
		return (NULL);
	node->args[0] = ft_strdup(content);
	return (node);
}

t_list	*parser_ast(t_input *input, t_map **lexer)
{
	t_map	*tmp;
	t_node	*node;
	int	status

	tmp = input->lexer;
	status = 0;
	while (tmp)
	{
		if (is_break(tmp->type))
		{
			if (tmp->type == PIPE)
			{
				ft_lstadd(&input->ast, new_node(tmp, NULL));
				status = 0;
			}	// fin PIPE
			else
			{
				if (ft_lstlast(&input->ast) && ft_lstlast(&input->ast)->type == WORD)
					status = 1;
				else
					status = 0;
				ft_lstadd(&input->ast, new_node(tmp, tmp->next->content));
				tmp = tmp->next;
			}
		}
		else if (tmp->type == WORD)
		{
			if (status == 0)
			{
				ft_lstadd(&input->ast, new_node(tmp, tmp->content));
				status = 1;
			}
			else
				ft_lstlast(&input->ast)->args = ft_strdjoin(ft_lstlast(&input->ast)->args, tmp->content);
		}
	}
}

