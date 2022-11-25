#include "minishell.h"

void	lexer_str_error(t_input *input, char *message, char *content)
{
	printf("%s", message);
	if (content)
		printf("%s", content);
	printf("\n");
	free_input(input);
	exit(0);
}

void	lexer_char_error(t_input *input, char *message, char content)
{
	printf("%s", message);
	if (content)
		printf("%c", content);
	printf("\n");
	free_input(input);
	exit(0);
}

int	is_break(e_type type)
{
	if (type == PIPE || type == GREDIR || type == GRREDIR || type == DREDIR || type == DRREDIR)
		return (1);
	return (0);
}

void	check_syntax(t_input *input)
{
	t_map	*tmp;

	tmp = input->lexer;
	while (tmp)
	{
		if (is_break(tmp->type))
		{
			if (tmp->next)
			{
				if (tmp->next->type != WORD)
					lexer_str_error(input, "error : unexpeted token : ` ", tmp->next->content);
			}
			else
					lexer_str_error(input, "error : unexpeted token : << newline >>", NULL);
		}
		tmp = tmp->next;
	}
}

char	*remove_quote(t_input *input, t_map **map, e_type type)
{
	t_map	*tmp;
	char	*s;
	char	*d;

	tmp = (*map)->next;
	s = NULL;
	while (tmp && tmp->type != type)
	{
		if (tmp->type == DOLLAR)
		{
			if (tmp->next && tmp->next->type == type)
				d = ft_strdup("$");
			else
				d = expand_dollar(input, &tmp);
			s = ft_strjoin2(s, d);
			free(d);
		}
		else
			s = ft_strjoin2(s, tmp->content);
		tmp = tmp->next;
	}
	*map = tmp;
	return (s);
}

void	check_expand(t_input *input)
{
	t_map	*tmp;
	char	*s;

	tmp = input->lexer;
	while (tmp)
	{
		if (tmp->type == WORD || is_break(tmp->type))
		{
			s = ft_strdup(tmp->content);
			ft_addmap(&input->parser, ft_mapnew(s, tmp->type));
		}
		else
		{
			if (tmp->type == DOLLAR)
				s = expand_dollar(input, &tmp);
			if (tmp->type == SQUOTE || tmp->type == DQUOTE)
				s = remove_quote(input, &tmp, tmp->type);
			ft_addmap(&input->parser, ft_mapnew(s, WORD));
		}
		tmp = tmp->next;
	}
}
