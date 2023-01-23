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

bool	ft_findstr(char *str, const char *find)
{
	size_t	len;

	len = ft_strlen(find);
	if (ft_strncmp(str, find, len))
		return (false);
	if (str[len] != '=')
		return (false);
	return (true);
}

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

char	*find_in_env(char **env, char *var)
{
	int		count;
	size_t	len;

	count = 0;
	len = ft_strlen(var);
	while (env[count])
	{
		if (ft_findstr(env[count], var))
		{
			free(var);
			return (ft_substr(env[count],
					len + 1, ft_strlen(env[count])));
		}
		count ++;
	}
	free(var);
	return (ft_strdup(""));
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
