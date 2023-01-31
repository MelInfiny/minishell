/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unquote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:33:41 by enolbas           #+#    #+#             */
/*   Updated: 2023/01/31 16:49:40 by enolbas          ###   ########.fr       */
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
			ft_replace_redir(input, node);
			tmp = unquoted(input, node->args[count], 1);
			if (tmp != NULL)
			{
				free(node->args[count]);
				node->args[count] = NULL;
				node->args[count] = tmp;
			}
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
		tmp = unquoted(input, redir->file, 0);
		if (tmp != NULL)
		{
			free(redir->file);
			redir->file = NULL;
			redir->file = tmp;
		}
		if (redir->type == 11)
			ft_heredoc("/tmp/heredoc", redir->file);
		r = r->next;
	}
}

char	*unquoted(t_input *input, char *word, int status)
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
		{
			if (status)
				tmp = remove_quote_in_word(input, word, type, &count);
			else
				tmp = remove_quote_in_word(NULL, word, type, &count);
		}
		else if (status && type == DOLLAR)
			tmp = replace_dollar(input, word, &count, type);
		else
			tmp = ft_substr(word, count, 1);
		q = ft_strjoin_free(q, tmp);
		count++;
	}
	return (q);
}

char	*remove_quote_in_word(t_input *input, char *line, t_type t, int *s)
{
	int		index;
	char	*tmp;

	tmp = NULL;
	index = *s + 1;
	while (line[index] && switch_type(line[index]) != t)
	{
		if (input && t == DQUOTE && line[index] == '$')
		{
			if (index > *s + 1)
				tmp = ft_strjoin_free(tmp, ft_substr(line, *s + 1, index - 1));
			tmp = ft_strjoin_free(tmp, replace_dollar(input, line, &index, t));
			*s = index;
		}
		if (line[index])
			index++;
	}
	if (line[index] && switch_type(line[index]) == t)
		tmp = ft_strjoin_free(tmp,
				ft_substr(line, *s + 1, index - (*s + 1)));
	*s = index;
	return (tmp);
}
