/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:19:45 by enolbas           #+#    #+#             */
/*   Updated: 2022/12/10 21:11:10 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int		set_redir(t_type type);

void	parser(t_input *input)
{
	t_map	*tmp;
	t_node	*node;

	tmp = input->lexer;
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
			ft_lstadd_back(&node->redir,
				ft_lstnew(new_redir(set_redir(tmp->type),
						ft_strdup(tmp->next->content))));
			tmp = tmp->next;
		}
		tmp = tmp->next;
	}
}

static int	set_redir(t_type type)
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
