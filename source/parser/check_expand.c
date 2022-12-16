/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:41:02 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/16 13:49:09 by enolbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static char	*remove_quote(t_input *input, t_map **map, t_type type);
static char	*join_quote(t_input *input, t_map **map);
static char	*ft_join(char *old, char *newstr);
static void	add_word(t_input *input, t_map **map);
static char	*find_in_env(char **env, char *var);
bool	ft_findstr(char *str, const char *find);
char	*expand_dollar(t_input *input, t_map **map);

void	check_expand(t_input *input)
{
	t_map	*tmp;
	char	*s;

	s = NULL;
	tmp = input->lexer;
	while (tmp)
	{
		if (tmp->type == ESPACE)
			;
		else if (is_break(tmp->type))
			map_add(&input->parser, map_new(ft_strdup(tmp->content), tmp->type));
		else if (tmp->type == WORD)
			add_word(input, &tmp);
		else
		{
			if (tmp->type == DOLLAR)
				s = expand_dollar(input, &tmp);
			if (tmp->type == SQUOTE || tmp->type == DQUOTE)
				s = join_quote(input, &tmp);
			map_add(&input->parser, map_new(s, WORD));
		}
		if (tmp)
			tmp = tmp->next;
	}
}

static void	add_word(t_input *input, t_map **map)
{
	char	*s;
	t_map	*tmp;

	tmp = (*map);
	s = ft_strdup(tmp->content);
	if (tmp->next && (tmp->next->type == DQUOTE || tmp->next->type == SQUOTE))
	{
		tmp = tmp->next;
		s = ft_join(s, join_quote(input, &tmp));
		if (tmp)
		{
			map_add(&input->parser, map_new(s, WORD));
			*map = tmp;
			return ;
		}
	}
	map_add(&input->parser, map_new(s, WORD));
}

static char	*ft_join(char *old, char *newstr)
{
	char	*ret;

	if (newstr)
	{
		if (old)
		{
			ret = ft_strjoin(old, newstr);
			free(old);
		}
		else
			ret = ft_strdup(newstr);
		free(newstr);
		return (ret);
	}
	return (NULL);
}

static char	*join_quote(t_input *input, t_map **map)
{
	t_map	*tmp;
	char	*s;

	tmp = (*map);
	s = NULL;
	while (tmp)
	{
		if (tmp->type == SQUOTE || tmp->type == DQUOTE)
			s = ft_join(s, remove_quote(input, &tmp, tmp->type));
		if (tmp->type == WORD && tmp->content)
			s = ft_join(s, ft_strdup(tmp->content));
		if (tmp->type == DOLLAR)
			s = ft_join(s, expand_dollar(input, &tmp));
		if (!tmp->next || (tmp->next && (tmp->next->type == ESPACE
					|| is_break(tmp->next->type))))
			break ;
		tmp = tmp->next;
	}
	*map = tmp;
	if (!s)
		return (ft_strdup(""));
	return (s);
}

static char	*remove_quote(t_input *input, t_map **map, t_type type)
{
	t_map	*tmp;
	char	*s;
	char	*d;

	tmp = (*map)->next;
	s = NULL;
	while (tmp && tmp->type != type)
	{
		if (type == DQUOTE && tmp->type == DOLLAR)
		{
			if (tmp->next && tmp->next->type == type)
				d = ft_strdup("$");
			else
				d = expand_dollar(input, &tmp);
			s = ft_strjoin_free(s, d);
			free(d);
		}
		else if (tmp->content)
			s = ft_strjoin_free(s, tmp->content);
		tmp = tmp->next;
	}
	*map = tmp;
	return (s);
}
char	*expand_dollar(t_input *input, t_map **map)
{
	t_map	*tmp;

	tmp = (*map)->next;
	if (tmp)
	{
		*map = tmp;
		if (tmp->type == WORD && ft_strlen(tmp->content) > 0)
		{
			if (!my_strcmp("?", tmp->content))
				return (ft_itoa(g_status));
			return (find_in_env(input->env, tmp->content));
		}
	}
	return (ft_strdup("$"));
}

static char	*find_in_env(char **env, char *var)
{
	int	count;

	count = 0;
	while (env[count])
	{
		if (ft_findstr(env[count], var))
			return (ft_substr(env[count],
					ft_strlen(var) + 1, ft_strlen(env[count])));
		count ++;
	}
	return (ft_strdup(""));
}

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

