/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enolbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:38:40 by enolbas           #+#    #+#             */
/*   Updated: 2022/12/16 16:34:53 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	is_next_valid(t_type type);

int	is_break(t_type type)
{
	if (type == PIPE || type == GREDIR
		|| type == GRREDIR || type == DREDIR || type == DRREDIR)
		return (1);
	return (0);
}

int	check_syntax(t_input *input)
{
	t_map	*tmp;

	tmp = input->lexer;
	while (tmp)
	{
		if (is_break(tmp->type))
		{
			if (tmp->next)
			{
				if (!is_next_valid(tmp->next->type))
					return (lexer_str_error(tmp->next->content));
			}
			else
				return (lexer_str_error("<< newline >>"));
		}
		tmp = tmp->next;
	}
	return (1);
}

static int	is_next_valid(t_type type)
{
	if (type == WORD)
		return (1);
	if (type == DQUOTE || SQUOTE)
		return (1);
	return (0);
}