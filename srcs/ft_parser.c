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


char	*parse_quote(t_map **map, e_type type, env)
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
			s = ft_strjoin2(s, parse_dollar(&tmp, env, 1));
		else
			s = ft_strjoin2(s, tmp->content);

		tmp = tmp->next;
	}
	*map = tmp;
	return (s);
}

char	*parse_dollar(t_map **map, char **env, int status)
{
	char	**tmp;
	char	*var;

	*map = map->next;
	if (!status)
		return (ft_expand_env(*map->content, env));
	tmp = ft_strsplit(*map->content, ' ');
	var = ft_expand_env(tmp[0]);
	if (tmp[1])
		var = ft_strjoin2(var, tmp[1]);
	ft_strdfree(tmp);
	return (var);
}

char	**parse_lexer(t_map **commande, char **env)
{
	char	**cmd;
	t_map	*tmp;

	tmp = *commande
	while (!is_redir(tmp_type) && tmp_type != PIPE)
	{
		if (tmp->type == WORD)
			cmd = strdjoin(cmd, tmp->content);
		else if (tmp->type == DOLLAR)
			cmd = strdjoin(cmd, parse_dollar(&mp, env, 0));
		else if (tmp->type == SQUOTE || tmp->type == DQUOTE)
			cmd = strdjoin(cmd, parse_quote(&tmp, tmp->type, env));
		tmp = tmp->next;
	}
	*commande = tmp;
	return (cmd);
}

void	parser(t_input *input, t_map *lexer)
{
	char	**res;
	int	status;

	tmp = lexer;
	status = -1;
	while (tmp)
	{
		if (is_redir(tmp->type))
		{
			res = parse_redir(&tmp, tmp_type);
			ft_lst_add(input->parser->redir, ft_newredir(res));
		}
		else if (tmp->type == PIPE)
		{
			res = parse_pipe(&tmp);
			ft_lst_add(input->parser->redir, ft_newredir(res));
			status = -1
		}
		else if (status < 0)
		{
			res = parse_lexer(&tmp, input->env);
			ft_lst_add(input->parser->cmds, ft_newcmd(res));
			status = -1;
		}
		else
		{
			res = parse_lexer(&tmp, input->env);
			ft_strdjoin(input->parser->cdms, res);
		}	
		tmp = tmp->next;
	}	
}

void	check_symbols(void);
