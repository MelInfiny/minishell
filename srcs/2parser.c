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

	node = (t_node *) ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->status = parse_status(map->type);
	if (node->status == -1)
		exit(0);
	node->args = (char **) ft_calloc(1, sizeof(char));
	if (!node->args)
		return (NULL);
	if (content)
		node->args[0] = ft_strdup(content);
	return (node);
}

t_list	*ft_lstlast_word(t_list *lst)
{
	int	size;
	int	count;
	//t_node	*node;

	count = 0;
	size = ft_lstsize(lst);
	printf("size = %d\n", size);
	while (lst && count < size - 1)
	{
		lst = lst->next;
	}/*
	node = lst->next->content;
	if (node->status == 0)
		lst = lst->next;
		*/
	return (lst);
}

void	ft_parser(t_input *input)
{
	t_map	*tmp;
	int		status;
	t_node	*node;

	tmp = input->lexer;
	status = 0;
	while (tmp)
	{
		printf("\ntype = %d: ", parse_status(tmp->type));
		if (is_break(tmp->type))
		{
			if (tmp->type == PIPE)
			{
				ft_lstadd_back(&input->ast, ft_lstnew(new_node(tmp, NULL)));
				status = 0;
			}
			else
			{
				ft_lstadd_back(&input->ast, ft_lstnew(new_node(tmp, tmp->next->content)));
				tmp = tmp->next;
			}
		}
		else if (tmp->type == WORD)
		{
			if (status == 0)
			{
				ft_lstadd_back(&input->ast, ft_lstnew(new_node(tmp, tmp->content)));
				status = 1;
			}
			else
			{
				node = ft_lstlast_word(input->ast)->content;
				node->args = ft_strdjoin(node->args, ft_strdup(tmp->content));
			}
		}
		tmp = tmp->next;
	}
}

