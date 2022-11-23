#include "minishell.h"

char	first_letter(char *str)
{
	return (str[0]);
}

t_token	*parse_first(t_input *input, int key)
{
	t_token	*head;
	char	*tmp;

	if (tmp->type == WORD)
		return (0);
	if (tmp->type == SQUOTE)
	{
		return (1);
	}
	if (tmp->type == DRREDIR || GRREDIR || DREDIR)
		return (2);
	else
	{
		printf("minishell : parse error near :%s\n", tmp->content);
		exit (0);
	}

	return (-1);
}

char	*parse_quote(t_map *map, e_type type)
{
	t_map	*tmp;
	char	*s;
	char	**expand;

	tmp = map->next;
	s = ft_strdup("");
	while (tmp->next)
	{
		if (tmp->type == type)
			break;
		if (tmp->type == DOLLAR)
		{
			tmp = tmp->next;
			expand = ft_expand_env(tmp->conent);
			s = ft_strjoin2(s, expand[0]);
			s = ft_strjoin2(s, expand[1]);
			free_strd(expand);
		}
		else
			s = ft_strjoin2(s, tmp->content);

		tmp = tmp->next;
	}
	return (s);
}

char	*parse_lexer(t_input *input, t_map *cmd)
{
	char	*cmd;
	t_map	*tmp;

	tmp = cmd;
	while (!is_redir(tmp_type) && tmp_type != PIPE)
	{
		if (tmp->type == WORD)
			cmd = tmp->content;
		if (tmp->type == SQUOTE || tmp->type == DQUOTE)
		{
			cmd = parse_quote(tmp, tmp->type);
		}
		
		tmp = tmp->next;
	}
}

void	parser(t_input *input, char *line)
{
	int	res;
	t_map	*parser;

	res = parse_first(input, 1);
	if (res)
	{
		
	}
		

}
