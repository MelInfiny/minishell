/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:33:41 by enolbas           #+#    #+#             */
/*   Updated: 2023/01/11 19:15:08 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	ft_replace_redir(t_input *input, t_node *node);

void	ft_replace_quote(t_input *input)
{
	t_list	*ast;
	t_node	*node;
	char	*tmp;
	int		count;

	ast = input->ast;
	tmp = NULL;
	while (ast)
	{
		node = ast->content;
		count = 0;
		while (node->args && node->args[count])
		{
			tmp = unquoted(input, node->args[count]);
			if (tmp != NULL)
			{
				free(node->args[count]);
				node->args[count] = NULL;
				node->args[count] = tmp;
			}
			ft_replace_redir(input, node);
			count++;
		}
		ast = ast->next;
	}
}

static void	ft_replace_redir(t_input *input, t_node *node)
{
	t_list	*r;
	t_redir	*redir;
	char	*tmp;

	r = node->redir;
	while (r)
	{
		redir = r->content;
		tmp = unquoted(input, redir->file);
		if (tmp != NULL)
		{
			free(redir->file);
			redir->file = NULL;
			redir->file = tmp;
		}
		r = r->next;
	}
}

char	*unquoted(t_input *input, char *word)
{
	t_type	type;
	char	*q;
	char	*tmp;
	int		count;

	count = 0;
	q = NULL;
	while (word[count])
	{
		type = switch_type(word[count]);
		if (type == DQUOTE || type == SQUOTE)
			tmp = remove_quote_in_word(input, word, type, &count);
		else if (type == DOLLAR)
			tmp = replace_dollar(input, word, &count, type);
		else
			tmp = ft_substr(word, count, 1);
		q = ft_strjoin_free(q, tmp);
		count++;
	}
	return (q);
}

char	*remove_quote_in_word(t_input *input,
			char *line, t_type type, int *start)
{
	int		index;
	char	*tmp;

	tmp = NULL;
	index = *start + 1;
	while (line[index] && switch_type(line[index]) != type)
	{
		if (type == DQUOTE && line[index] == '$')
		{
			if (index > *start + 1)
				tmp = ft_strjoin_free(ft_substr(line, *start + 1, index - 1), tmp);
			tmp = ft_strjoin_free(replace_dollar(input, line, &index, type), tmp);
			*start = index;
		}
		if (line[index])
			index++;
	}
	if (line[index] && switch_type(line[index]) == type)
		tmp = ft_strjoin_free(
				ft_substr(line, *start + 1, index - (*start + 1)), tmp);
	*start = index;
	return (tmp);
}