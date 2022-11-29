#include "minishell.h"

e_type	switch_type(char c)
{
	if (c == '\"')
		return (DQUOTE);
	if (c == '\'')
		return (SQUOTE);
	if (c == '$')
		return (DOLLAR);
	if (c == ' ')
	       return (ESPACE);
	if (c == '|')
	       return (PIPE);
	if (c == '<')
	       return (GREDIR);
	if (c == '>')
		return (DREDIR);
	return (WORD);
}

static int	set_redir(e_type type)
{
	if (type == GREDIR)
		return (1);
	if (type == GRREDIR)
		return (11);
	if (type == DREDIR)
		return (2);
	if (type == DRREDIR)
		return (22);
	return (0);
}

static t_node	*new_node(void)
{
	t_node	*node;

	node = (t_node *) ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->status = 0;
	return (node);
}

void	ft_parser(t_input *input)
{
	t_map	*tmp;
	t_node	*node;

	tmp = input->parser;
	ft_lstadd_back(&input->ast, ft_lstnew(new_node()));
	while (tmp)
	{
		if (tmp->type == WORD)
		{
			node = ft_lstlast(input->ast)->content;
			node->args = ft_strdjoin(node->args, tmp->content);
		}
		else if (tmp->type == PIPE)
			ft_lstadd_back(&input->ast, ft_lstnew(new_node()));
		else if (is_break(tmp->type))
		{
			node = ft_lstlast(input->ast)->content;
			node->status = set_redir(tmp->type);
			node->file = ft_streplace(node->file, ft_strdup(tmp->next->content));
			tmp = tmp->next;
		}
		tmp = tmp->next;
	}
}
