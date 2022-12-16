/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:38:40 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/16 12:54:58 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	lexer_str_error(t_input *input, char *message, char *content);
static void	skip_spaces(t_map **map);
static int	is_next_valid(t_type type);

int	check_syntax(t_input *input)
{
	t_map	*tmp;

	tmp = input->lexer;
	while (tmp)
	{
		if (is_break(tmp->type))
		{
			skip_spaces(&tmp);
			if (tmp)
			{
				if (!is_next_valid(tmp->type))
					return (lexer_str_error(input,
							"error : unexpeted token : ` ",
							tmp->content));
			}
			else
				return (lexer_str_error(input,
						"error : unexpeted token : << newline >>", NULL));
		}
		tmp = tmp->next;
	}
	return (1);
}

static void	skip_spaces(t_map **map)
{
	t_map	*tmp;

	tmp = (*map)->next;
	while (tmp && tmp->type == ESPACE)
	{
			tmp = tmp->next;
	}
	*map = tmp;
}

static int	lexer_str_error(t_input *input, char *message, char *content)
{
	printf("%s", message);
	if (content)
		printf("%s", content);
	printf("\n");
	(void) input;
	return (0);
}

static int	is_next_valid(t_type type)
{
	if (type == WORD)
		return (1);
	if (type == DQUOTE || SQUOTE)
		return (1);
	return (0);
}

int	check_pipes(t_input *input)
{
	t_map	*tmp;

	tmp = input->lexer;
	while (tmp && tmp->type == ESPACE)
			tmp = tmp->next;
	if (tmp)
	{
		if (tmp->type == PIPE)
		{
			return (lexer_str_error(input,
					"unexpeted token : ` ", tmp->content));
		}
	}
	else
		return (0);
	return (1);
}
